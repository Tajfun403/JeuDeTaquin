#pragma once
/// <summary>
/// Arguments to pass to a worker thread
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
/// PRIVATE FUNCTION<para />Get amount of cores in the system
/// </summary>
/// <returns></returns>
int GetCoresCount();

/// <summary>
/// Run a given function on a data set with automatical split to threads
/// </summary>
/// <param name="func">Function to call on each data item</param>
/// <param name="inputArray">Input array. Elements from this array will be passed as arg to the func. Set to NULL to skip.</param>
/// <param name="outputArray">Output array. Return value from the func will be written to this array. Set to NULL to skip.</param>
/// <param name="n">Amount of items in array</param>
/// <param name="progress">Pointer to progress var that will be updated with current progress</param>
void RunBatch(void* (*func)(void*), void** inputArray, void** outputArray, int n, int* progress);

void UpdateProgress();

/// <summary>
/// PRIVATE FUNCTION<para />Main function for each thread
/// </summary>
/// <param name="args">Thread arguments</param>
void RunBatchThread(struct ThreadArgs* args);

