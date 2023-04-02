#define _CRT_SECURE_NO_WARNINGS

#include "Logger.h"

Logger Logger::m_Instance;

Logger::Logger()
{
	m_pStream = fopen("logger.log", "w");

}

Logger::~Logger()
{
fclose(m_pStream);
}

Logger& Logger::Instance()
{
	return m_Instance;
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
