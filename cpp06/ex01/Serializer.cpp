#include "Serializer.hpp"

Serializer::Serializer(void) {
	std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::Serializer(Serializer const &copy) {
	std::cout << "Serializer copy constructor called" << std::endl;
	*this = copy;
}

Serializer&	Serializer::operator=(Serializer const &serializer) {
	std::cout << "Serializer copy assigment operator called" << std::endl;
	(void)serializer;
	return (*this);
}

Serializer::~Serializer(void) {
	std::cout << "Serializer destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}