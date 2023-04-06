#pragma once

#include <cstdio>
#include <string>

class Logger
{
	Logger();
	static Logger* m_Instance;

	FILE* m_pStream;
	std::string m_Tag;

public:
	// Rule of three
	Logger(const Logger&) = delete;
	Logger& operator=(const Logger&) = delete;
	~Logger();

	static Logger& Instance();

	void WriteLog(const char*);
	void SetTag(const char*);
};

