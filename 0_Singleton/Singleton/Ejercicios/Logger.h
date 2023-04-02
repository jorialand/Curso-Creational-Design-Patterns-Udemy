#pragma once

#include <cstdio>
#include <string>

class Logger
{
	Logger();
	static Logger m_Instance;

	FILE* m_pStream;
	std::string m_Tag;

public:
	~Logger();
	static Logger& Instance();

	void WriteLog(const char*);
	void SetTag(const char*);
};

