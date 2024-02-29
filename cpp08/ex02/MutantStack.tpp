#ifndef MUTANT_STACK_TPP
#define MUTANT_STACK_TPP

#include "MutantStack.hpp"
#include <iostream>

// ======= CONSTRUCTORS AND DESTRUCTOR =======

template <typename T> MutantStack<T>::MutantStack(void) : std::stack<T>() 
{
	// std::cout << "Default MutantStack constructor called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &copy) : std::stack<T>(copy)
{
	// std::cout << "Copy MutantStack constructor called" << std::endl;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &copy)
{
	// std::cout << "Copy MutantStack assignation called" << std::endl;
	std::stack<T>::operator=(copy);
	return *this;
}

template <typename T> MutantStack<T>::~MutantStack(void)
{
	// std::cout << "Destructor for MutantStack called" << std::endl;
}

// ======= ITERATORS =======

template <typename T> typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T> typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::rev_iterator MutantStack<T>::revBegin()
{
	return (this->c.revBegin());
}

template <typename T>
typename MutantStack<T>::rev_iterator MutantStack<T>::revEnd()
{
	return (this->c.revEnd());
}


// ======= CONST ITERATORS =======

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_rev_iterator MutantStack<T>::revBegin() const
{
	return (this->c.revBegin());
}

template <typename T>
typename MutantStack<T>::const_rev_iterator MutantStack<T>::revEnd() const
{
	return (this->c.revEnd());
}

#endif