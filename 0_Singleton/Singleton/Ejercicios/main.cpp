#include "Logger.h"
#include <iostream>
#include <thread>
#include <mutex>

void OpenConnection()
{
	Logger& log = Logger::Instance();
	log.WriteLog("OpenConnection");

}
int main()
{
	std::thread t1 {
		[](){
		Logger& log = Logger::Instance();
		log.WriteLog("Thread 1 has started.");
		}
	};

	std::thread t2{
		[](){
		Logger& log = Logger::Instance();
		log.WriteLog("Thread 2 has started.");
		}
	};
	t1.join();
	t2.join();
}