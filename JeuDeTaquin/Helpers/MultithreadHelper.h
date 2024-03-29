#pragma once
#include <stdbool.h>
#include <windows.h>

/// <summary>
/// Arguments to pass to a worker thread for main threading
/// </summary>
struct ThreadArgs {
	/// <summary>
	/// Function to call on each data item. Argument is an item from inputArray; return value is written to outputArray
	/// </summary>
	void* (*func)(void*);

	/// <summary>
	/// Array with input values. Set to NULL to skip
	/// </summary>
	void** inputArray;

	/// <summary>
	/// Array for output values. Set to NULL to skip
	/// </summary>
	void** outputArray;

	/// <summary>
	/// Start index for this thread
	/// </summary>
	int start;

	/// <summary>
	/// End index for this thread
	/// </summary>
	int end;

	/// <summary>
	/// Pointer to a progress counter which can be updated.
	/// </summary>
	int* progress;
};

/// <summary>
/// Arguments to pass to a progress counter thread
/// </summary>
struct ProgressArgs {
	/// <summary>
	/// An array of pointers to progresses' of each worker
	/// </summary>
	int** progressArray;

	/// <summary>
	/// Expected sum of all progresses
	/// </summary>
	/// <returns></returns>
	int MaxProgressSum;

	/// <summary>
	/// Amount of workers
	/// </summary>
	int progressEntriesCount;

	/// <summary>
	/// Set to true once main work is done so that the counter thread can stop listening.
	/// </summary>
	bool* ShouldCancel;
};

/// <summary>
/// PRIVATE FUNCTION: Get amount of logical cores in the system
/// </summary>
/// <returns>Amount of logical cores in the system</returns>
int GetCoresCount();

/// <summary>
/// Run a given function on a data set with automatical split to threads
/// </summary>
/// <param name="func">Function to call on each data item</param>
/// <param name="inputArray">Input array. Elements from this array will be passed as arg to the func. Set to NULL to skip.</param>
/// <param name="outputArray">Output array. Return value from the func will be written to this array. Set to NULL to skip.</param>
/// <param name="n">Amount of items in array</param>
void RunBatch(void* (*func)(void*), void** inputArray, void** outputArray, int n);

/// <summary>
/// PRIVATE FUNCTION: Main function for each thread
/// </summary>
/// <param name="args">Thread arguments</param>
/// <returns>Return code of the thread</returns>
int RunBatchThread(struct ThreadArgs* args);

/// <summary>
/// Spawn a progress thread, which will periodically count and print current progress of all workers to standard output.
/// </summary>
/// <param name="progressArray">An array of pointers to progresses' of each worker</param>
/// <param name="progressCount">Amount of workers in prev array</param>
/// <param name="MaxProgressSum">Expected sum of all progresses</param>
/// <param name="bFinished">Pointer to a bool which will change once the task is finished and monitoring should be ceased</param>
/// <returns>Handle to spawned thread</returns>
HANDLE* RunProgressThread(int** progressArray, int progressCount, int MaxProgressSum, bool* bFinished);

/// <summary>
/// PRIVATE: Main function for progress counter thread
/// </summary>
/// <param name="progressArray">An array with arguments for the thread</param>
/// <returns>Return code of the thread</returns>
int UpdateProgress(struct ProgressArgs* args);
