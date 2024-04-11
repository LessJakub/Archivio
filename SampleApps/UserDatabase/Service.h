#pragma once
#include <vector>

template<class T>
class Service
{
protected:

	std::vector<T> ReadFromFile();

public:
	bool Create(T data);

	T Read(T data);

	T Update(T data);

	bool Delete(T data);
};

