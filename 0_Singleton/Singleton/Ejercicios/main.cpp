#include "Logger.h"

void OpenConnection()
{
	Logger& log = Logger::Instance();
	log.WriteLog("OpenConnection");

}
int main()
{
	Logger& log = Logger::Instance();
	log.SetTag("INFO");
	log.WriteLog("App started.");
	OpenConnection();
	log.WriteLog("App shutting down.");
}