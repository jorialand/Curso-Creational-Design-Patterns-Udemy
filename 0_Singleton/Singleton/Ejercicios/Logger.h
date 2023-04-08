#pragma once

#include <cstdio>
#include <string>
#include <memory>
#include <mutex>
 
class Logger
{
	Logger();
	// c++17 inline static initialization
	inline static Logger* m_pInstance {};

	FILE* m_pStream;
	std::string m_Tag;
	inline static std::mutex m_mutex {};
	~Logger();
public:
	// Rule of three
	Logger(const Logger&) = delete;
	Logger& operator=(const Logger&) = delete;

	static Logger& Instance();

	void WriteLog(const char*);
	void SetTag(const char*);
};

