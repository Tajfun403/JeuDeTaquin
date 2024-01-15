#pragma once
#include <windows.h>

/// <summary>
/// Character of the log call
/// </summary>
enum LogType {
	/// <summary>
	/// LogType: normal info
	/// </summary>
	LOGTYPE_OK,

	/// <summary>
	/// LogType: non-critical warning. Shows in orange.
	/// </summary>
	LOGTYPE_WARNING,

	/// <summary>
	/// LogType: critical error. Shows in red.
	/// </summary>
	LOGTYPE_ERROR
};

/// <summary>
/// Change color of the standard output.
/// </summary>
/// <param name="type">Type of log to take the color from</param>
void ChangeConsoleColor(enum LogType type);

/// <summary>
/// Log a message to standard output
/// </summary>
/// <param name="msg">Message</param>
/// <param name="type">Type of message</param>
/// <param name="line">Source line of code where the log was thrown</param>
/// <param name="file">Path to source file where the log was thrown</param>
void Log(const char* msg, enum LogType type, int line, const char* file);

/// <summary>
/// Log a standard message to standard output.
/// </summary>
/// <param name="msg">Message</param>
#define LOG(msg) Log(msg, LOGTYPE_OK, __LINE__, __FILE__)

/// <summary>
/// Log a critical error to standard output. It will be shown in red.
/// </summary>
/// <param name="msg">Message</param>
#define LOG_ERROR(msg) Log(msg, LOGTYPE_ERROR, __LINE__, __FILE__)

/// <summary>
/// Log a non-critical warning to standard output. It will be shown in orange.
/// </summary>
/// <param name="msg">Message</param>
#define LOG_WARNING(msg) Log(msg, LOGTYPE_WARNING, __LINE__, __FILE__)
