#pragma once
#include "Exceptions.h"
#include <stdio.h>

void ChangeConsoleColor(enum LogType type) {
	// https://stackoverflow.com/a/4053879
	// https://learn.microsoft.com/en-us/windows/console/console-screen-buffers
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int color;
	switch (type)
	{
	case LOGTYPE_OK:
		color = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
		break;
	case LOGTYPE_WARNING:
		color = FOREGROUND_GREEN | FOREGROUND_RED;
		break;
	case LOGTYPE_ERROR:
		color = FOREGROUND_RED;
		break;
	default:
		break;
	}

	SetConsoleTextAttribute(hConsole, color);
}

void Log(const char* msg, enum LogType type, int line, const char* file) {
	ChangeConsoleColor(type);
	printf("%s:%i: %s", file, line, msg);
	ChangeConsoleColor(LOGTYPE_OK);
}