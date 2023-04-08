#define _CRT_SECURE_NO_WARNINGS

#include "Logger.h"
#include <iostream>

Logger::Logger()
{
	std::cout << __FUNCSIG__ << std::endl;
	m_pStream = fopen("logger.log", "w");

	atexit([](){delete m_pInstance;});
}

Logger::~Logger()
{
	std::cout << __FUNCSIG__ << std::endl;
	fclose(m_pStream);
}

Logger& Logger::Instance()
{
	m_mutex.lock();
	if (nullptr == m_pInstance)
		m_pInstance = new Logger();
	m_mutex.unlock();

	return *m_pInstance;
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
