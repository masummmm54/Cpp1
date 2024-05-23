#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP


#include <iostream>
#include <string>
#include <stdint.h>


typedef struct s_Data
{
	int			num;
	std::string str;
}	Data;

class Serializer
{
private:
	Serializer();
	~Serializer();
	Serializer(const Serializer& p);
	Serializer& operator=(const Serializer& other);
public:
	static uintptr_t	serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};


#endif