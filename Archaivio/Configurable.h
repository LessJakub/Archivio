#pragma once
#include "Configuration.h"
#include <memory>

template<class C>
class Configurable
{
public:

	std::unique_ptr<C> configuration;

	Configurable();

	~Configurable();

	void ApplyConfiguration(C configuration);
};

