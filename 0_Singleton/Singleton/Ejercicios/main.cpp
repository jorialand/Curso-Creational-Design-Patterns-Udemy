#include "Logger.h"
#include <iostream>
#include <thread>
#include <mutex>
#include "BaseSingleton.h"

/*
	CRTP Curiosity Recurring Template Pattern - Multiple Singletons using a 
	BaseSingleton class.
*/
class StudyManager : public BaseSingleton<StudyManager>
{
//private:
//StudyManager() = default;
//friend class BaseSingleton<StudyManager>;
MAKE_SINGLETON(StudyManager);
public:
void methA() { 	std::cout << __FUNCSIG__ << std::endl; };
void methB() { 	std::cout << __FUNCSIG__ << std::endl; };
};

void OpenConnection()
{
	Logger& log = Logger::Instance();
	log.WriteLog("OpenConnection");

}
int main()
{
	// CRTP
	StudyManager& sm = StudyManager::Instance();
	sm.methA();
	sm.methB();
	//auto sm2 = sm;

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