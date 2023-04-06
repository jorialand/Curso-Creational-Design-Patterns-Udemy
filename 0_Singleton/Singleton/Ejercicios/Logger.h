#pragma once

#include <cstdio>
#include <string>
#include <memory>
 
class Logger
{
	struct Deleter
	{
		void operator()(Logger* p)
		{
			delete p;
		}
	};

	Logger();
	// c++17 inline static initialization
	inline static std::unique_ptr<Logger, Deleter> m_pInstance{};

	FILE* m_pStream;
	std::string m_Tag;

	~Logger();
public:
	// Rule of three
	Logger(const Logger&) = delete;
	Logger& operator=(const Logger&) = delete;

	static Logger& Instance();

	void WriteLog(const char*);
	void SetTag(const char*);
};

