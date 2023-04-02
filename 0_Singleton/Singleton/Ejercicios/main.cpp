#include "Logger.h"


int main()
{
	Logger& log = Logger::Instance();
	log.SetTag("INFO");
	log.WriteLog("App started.");
	log.WriteLog("App shutting down.");
}