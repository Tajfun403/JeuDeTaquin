#include <sys/timeb.h>

// https://stackoverflow.com/a/44616416
long GetCurrTimeMs() {
#if defined(_WIN32) || defined(_WIN64)
	struct timeb timebuffer;
	ftime(&timebuffer);
	return (long)(((timebuffer.time * 1000) + timebuffer.millitm));
#else
	struct timeb timebuffer;
	ftime(&timebuffer);
	return (long)(((timebuffer.time * 1000) + timebuffer.millitm));
#endif
}