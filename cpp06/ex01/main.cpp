

#include "Serializer.hpp"


int	main()
{
	Data *data = new Data;
	Data *data2;
	uintptr_t raw;

	data->num = 5;
	data->str = "masum";

	std::cout << data << std::endl;
	raw = Serializer::serialize(data);
	std::cout << raw << std::endl;
	data2 = Serializer::deserialize(raw);
	std::cout << data2 << std::endl;
	std::cout << data2->num << std::endl;
	std::cout << data2->str << std::endl;
	
	delete data;
	return (0);
}