#include "Logger.h"

void OpenConnection()
{
	//Logger& log = Logger::Instance();
	Logger log;
	log.WriteLog("OpenConnection");

}
int main()
{
	//Logger& log = Logger::Instance();
	Logger log;
	log.SetTag("INFO");
	log.WriteLog("App started.");
	OpenConnection();
	log.WriteLog("App shutting down.");
}