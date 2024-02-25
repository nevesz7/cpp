#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
# include <iostream>
# include <string>
# include <stdint.h>

class	Serializer
{
	private:
		Serializer();
		Serializer(Serializer const& copy);
		~Serializer();

	public:
		Serializer& operator=(Serializer const& serializer);
		static Data*		deserialize(uintptr_t raw);
		static uintptr_t	serialize(Data* ptr);
};

#endif