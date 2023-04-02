#include "Singleton.h"

int main()
{
	//Singleton singleton = Singleton(); // Ctor is private
	Singleton& s = Singleton::Instance();
	s.MethodA();
}