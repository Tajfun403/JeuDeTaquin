#pragma once
struct ThreadArgs {
	void* (*func)(void*);
	void** inputArray;
	void** outputArray;
	int start;
	int end;
	int* progress;
};
int GetCoresCount();
void RunBatch(void* (*func)(void*), void** inputArray, void** outputArray, int n, int* progress);
void UpdateProgress();
void RunBatchThread(struct ThreadArgs* args);

