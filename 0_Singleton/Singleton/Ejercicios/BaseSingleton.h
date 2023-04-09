#pragma once
template<typename T>
class BaseSingleton
{
protected:
	BaseSingleton() = default;
	BaseSingleton(const BaseSingleton&) = delete;
	BaseSingleton operator=(const BaseSingleton&) = delete;

public:
	static T& Instance()
	{
		static T m_Instance; 
		return m_Instance;
	}
};
#define MAKE_SINGLETON(ClassName) private: ClassName() = default; \
friend class BaseSingleton<ClassName>;
