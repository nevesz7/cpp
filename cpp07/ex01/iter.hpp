#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template	<typename T>
void	iter(T* array, size_t len, void (*fptr)(T& elem))
{
	if (!array || len <= 0)
		return ;
	for (size_t i = 0; i < len; i++)
		fptr(array[i]);
}

template<typename T>
void iter(T* array, size_t len, void (*fptr)(T&, T&))
{
    if (!array || len <= 0)
        return;
    for (size_t i = 0; i < len - 1; i++)
        fptr(array[i], array[i + 1]);
}

template	<typename T>
void	iter(T* array, size_t len, void (*fptr)(const T& elem))
{
	if (!array || len <= 0)
		return ;
	for (size_t i = 0; i < len; i++)
		fptr(array[i]);
}


template <typename T>
void	plusTen(T& elem)
{
	elem += 10;
}

template	<typename T>
void	printing(const T& elem)
{
	std::cout << elem << " ";
}

template <typename T>
void fibonacci(T& current, T& next) {
    T temp = current;
    current = next;
    next += temp;
}

#endif