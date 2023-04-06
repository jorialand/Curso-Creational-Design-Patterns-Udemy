#pragma once

#include <cstdio>
#include <string>
#include <memory>
 
class Logger
{
	Logger();
	// c++17 inline static initialization
	inline static std::unique_ptr<Logger> m_pInstance{};

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

