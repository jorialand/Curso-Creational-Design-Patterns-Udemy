#pragma once

#include <cstdio>
#include <string>
#include <memory>
#include <mutex>
#include "BaseSingleton.h"
 
class Logger : public BaseSingleton<Logger>
{
	Logger();
	friend class BaseSingleton<Logger>;
	// c++17 inline static initialization
	inline static Logger* m_pInstance {};

	FILE* m_pStream;
	std::string m_Tag;
	inline static std::mutex m_mutex {};
	~Logger();
public:
	void WriteLog(const char*);
	void SetTag(const char*);
};

