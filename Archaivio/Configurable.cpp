#include "pch.h"
#include "Configurable.h"

template<class C>
Configurable<C>::Configurable()
{
}
template<class C>
Configurable<C>::~Configurable()
{
}
template<class C>
void Configurable<C>::ApplyConfiguration(C configuration)
{
}


Configurable<LoggerConfiguration>::Configurable()
{
#if DEBUG
	std::cout << "Configurable<LoggerConfiguration>::Configurable\n";
#endif
}

Configurable<LoggerConfiguration>::~Configurable()
{
}

void Configurable<LoggerConfiguration>::ApplyConfiguration(LoggerConfiguration conf)
{
#if DEBUG
	std::cout << "Applying configuration LoggerConfiguration\n";
#endif
	configuration = std::make_unique<LoggerConfiguration>(conf);
}

Configurable<Configuration>::Configurable()
{
#if DEBUG
	std::cout << "Configurable<Configuration>::Configurable\n";
#endif
}

Configurable<Configuration>::~Configurable()
{
}

void Configurable<Configuration>::ApplyConfiguration(Configuration conf)
{
#if DEBUG
	std::cout << "Applying configuration Configuration\n";
#endif
	configuration = std::make_unique<Configuration>(conf);

}

Configurable<HttpLoggerConfiguration>::Configurable()
{
#if DEBUG
	std::cout << "Configurable<Configuration>::Configurable\n";
#endif
}

Configurable<HttpLoggerConfiguration>::~Configurable()
{
}

void Configurable<HttpLoggerConfiguration>::ApplyConfiguration(HttpLoggerConfiguration conf)
{
#if DEBUG
	std::cout << "Applying configuration HttpLoggerConfiguration\n";
#endif
	configuration = std::make_unique<HttpLoggerConfiguration>(conf);
}