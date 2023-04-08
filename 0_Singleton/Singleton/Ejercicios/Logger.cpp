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
	// DCLP - Double Checking Locking Pattern
	if (nullptr == m_pInstance)
	{
		m_mutex.lock();
		if (nullptr == m_pInstance)
		{
			//m_pInstance = new Logger(); // This operation is splitted in 3, by the compiler.
			void* p = operator new(sizeof(Logger)); // Step 1 Memory allocation.
			m_pInstance = static_cast<Logger*>(p);// Step 3 Memory address assigned.
			new(p) Logger{}; // Step 2 Initialization.
			// The compiler can choose to reorder the instructions.
		}
		m_mutex.unlock();
	}
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
