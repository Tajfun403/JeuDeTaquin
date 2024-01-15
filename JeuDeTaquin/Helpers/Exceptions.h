#pragma once
#include <windows.h>

enum LogType {
	LOGTYPE_OK,
	LOGTYPE_WARNING,
	LOGTYPE_ERROR
};

void ChangeConsoleColor(enum LogType type);

void Log(const char* msg, enum LogType type, int line, const char* file);

#define LOG(msg) Log(msg, LOGTYPE_OK, __LINE__, __FILE__)
#define LOG_ERROR(msg) Log(msg, LOGTYPE_ERROR, __LINE__, __FILE__)
#define LOG_WARNING(msg) Log(msg, LOGTYPE_WARNING, __LINE__, __FILE__)
