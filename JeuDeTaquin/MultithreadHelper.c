#pragma region GetCoresCount
// https://stackoverflow.com/q/8666378
#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#elif defined(__unix__)
#include <unistd.h>
#endif
#pragma endregion

#include <math.h>

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
