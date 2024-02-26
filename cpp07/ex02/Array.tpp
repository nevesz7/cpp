#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template	<typename T>
Array<T>::Array() : _array(NULL), _size(0)
{}

template	<typename T>
Array<T>::Array(unsigned int n)
{
	this->_size = n;
	if (_size)
		this->_array = new T[n];
}

template	<typename T>
Array<T>::Array(Array const &src) : _array(NULL), _size(src.size())
{
	*this = src;
}

template	<typename T>
size_t Array<T>::size() const 
{
	return (this->_size);
}

template	<typename T>
Array<T>::~Array()
{
	delete [] this->_array;
}

template	<typename T>
Array<T> &Array<T>::operator=(Array const &src)
{
	if (this != &src)
	{
		this->_array = new T[src.size()];
		for (int i = 0; i < (int)this->_size; i++)
			this->_array[i] = src._array[i];
		this->_size = src._size;
	}
	return (*this);
}

template	<typename T>
T &Array<T>::operator[](int i)
{
	if (i < 0 || (unsigned int)i >= this->_size)
		throw Array<T>::OutOfLimitsException();
	return (this->_array[i]);
}

template	<typename T>
std::ostream& operator<<(std::ostream& output, Array<bool> & array)
{
	output << "Array of size " << array.size() << ": ";
	for (size_t i = 0; i < array.size(); i++) {
		if (array[i])
			output << "true  ";
		else
			output << "false ";
	}
	return output;
}

template	<typename T>
const char *Array<T>::OutOfLimitsException::what() const throw()
{
	return ("Index out of limits!");
}

#endif