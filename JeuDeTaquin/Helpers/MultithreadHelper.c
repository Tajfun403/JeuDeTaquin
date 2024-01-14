#pragma region GetCoresCount
// https://stackoverflow.com/q/8666378
#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#elif defined(__unix__)
#include <unistd.h>
#endif
#pragma endregion

#include <math.h>
#include "MultithreadHelper.h"
#include <stdbool.h>
#include <Windows.h>
#include "Exceptions.h"

// https://stackoverflow.com/a/150971

int GetCoresCount() {
#if defined(_WIN32) || defined(WIN32)
	SYSTEM_INFO sysinfo;
	GetSystemInfo(&sysinfo);
	return sysinfo.dwNumberOfProcessors;
#elif defined(__unix__)
	return sysconf(_SC_NPROCESSORS_ONLN);
#endif
}

// function pointers: return_type (*pointerName[])(arg1, arg2, arg3, .....) 
// eg. void* (*func)(void*) is a func of return void*, takes void* as 1st arg, 
// and is put into var called *func

void RunBatch(void* (*func)(void*), void** inputArray, void** outputArray, int n) {
	int cores = GetCoresCount();
	// avoid spinning useless threads
	if (n < cores)
		cores = n;
	int itemsPerCore = floor(n / cores);
	int leftoverItems = n - (itemsPerCore * cores);

	// https://learn.microsoft.com/en-us/windows/win32/procthread/creating-threads?redirectedfrom=MSDN
	HANDLE* threads = malloc(sizeof(HANDLE) * cores);
	int** progressArray = malloc(sizeof(int*) * cores);
	for (size_t i = 0; i < cores; i++)
	{
		progressArray[i] = malloc(sizeof(int));
		*progressArray[i] = 0;
	}
	bool* bFinished = malloc(sizeof(bool));
	*bFinished = false;

	for (int i = 0; i < cores; i++) {
		bool isThisLastOne = i == cores - 1;
		struct ThreadArgs* args = malloc(sizeof(struct ThreadArgs));
		args->func = func;
		args->inputArray = inputArray;
		args->outputArray = outputArray;
		args->start = itemsPerCore * i;
		args->end = !isThisLastOne ? (itemsPerCore * (i + 1)) - 1 : leftoverItems;
		args->progress = progressArray[i];

		threads[i] = CreateThread(
			NULL,                   // default security attributes
			0,                      // use default stack size  
			RunBatchThread,         // thread function name
			args,                   // argument to thread function 
			0,                      // use default creation flags 
			NULL);    
	}

	HANDLE* progressThread = RunProgressThread(progressArray, cores, n, bFinished);
	WaitForMultipleObjects(cores, threads, TRUE, INFINITE);
	*bFinished = true; // callback so that the counter can kill itself
	printf("\rCurrentProgress: %i / %i        \n", n, n);

	for (int i = 0; i < cores; i++)
		CloseHandle(threads[i]);
	CloseHandle(progressThread);
}

int RunBatchThread(struct ThreadArgs* args) {
	for (int i = args->start; i <= args->end; i++) {
		void* arg;
		if (args->inputArray != NULL)
			arg = args->inputArray[i];
		else
			arg = NULL;

		if (args->outputArray != NULL)
			args->outputArray[i] = (args->func)(arg);
		else
			(args->func)(arg);
		(*(args->progress))++;
	}
	return (*(args->progress));
}

#pragma region Progress

HANDLE* RunProgressThread(int** progressArray, int progressCount, int MaxProgressSum, bool* bFinished) {
	HANDLE* thread = malloc(sizeof(HANDLE));
	struct ProgressArgs* args = malloc(sizeof(struct ProgressArgs));
	args->MaxProgressSum = MaxProgressSum;
	args->progressEntriesCount = progressCount;
	args->progressArray = progressArray;
	args->ShouldCancel = bFinished;
	thread = CreateThread(
		NULL,                   // default security attributes
		0,                      // use default stack size  
		UpdateProgress,         // thread function name
		args,                   // argument to thread function 
		0,                      // use default creation flags 
		NULL);
	return thread;
}

int UpdateProgress(struct ProgressArgs* args) {
	printf("Using %i threads\n", args->progressEntriesCount);
	printf("Starting progress count");
	while (!*(args->ShouldCancel)) {
		// refresh counter once per second
		Sleep(1000);
		int currProgressCount = 0;
		for (size_t i = 0; i < args->progressEntriesCount; i++)
		{
			currProgressCount += *(args->progressArray[i]);
		}
		// r puts cursor at the start of curr line, allowing one to overwrite it
		printf("\rCurrentProgress: %i / %i        ", currProgressCount, args->MaxProgressSum);
	}
	// let the upper thread do the final print
	// to avoid overprinting while this one still waits for next refresh cycle
	// printf("\rCurrentProgress: %i / %i        \n", args->MaxProgressSum, args->MaxProgressSum);
	return 100;
}

#pragma endregion