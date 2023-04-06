#define _CRT_SECURE_NO_WARNINGS

#include "Logger.h"
#include <iostream>

Logger* Logger::m_Instance;

Logger::Logger()
{
	std::cout << __FUNCSIG__ << std::endl;
	m_pStream = fopen("logger.log", "w");
}

Logger::~Logger()
{
	std::cout << __FUNCSIG__ << std::endl;
	fclose(m_pStream);
}

Logger& Logger::Instance()
{
	if (nullptr == m_Instance)
		m_Instance = new Logger();
	return *m_Instance;
}


void Logger::WriteLog(const char* sMsg)
{
	fprintf(m_pStream, "[%s] %s\n", m_Tag.c_str(), sMsg);
	fflush(m_pStream);
}

void Logger::SetTag(const char* sTag)
{
	m_Tag = sTag;
}
