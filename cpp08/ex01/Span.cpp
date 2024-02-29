#include "Span.hpp"

// ======= CONSTRUCTORS AND DESTRUCTOR =======

Span::Span() : max(0), elements(std::vector<int>())
{
	std::cout << "Default Span constructor called" << std::endl;
}

Span::Span(size_t n) : max(n), elements(std::vector<int>())
{
	std::cout << "Span parameter constructor was called!" << std::endl;
}

Span::Span(const Span &copy)
{
	std::cout << "Copy Span constructor called" << std::endl;
	*this = copy;
}

Span &Span::operator=(const Span &rhs)
{
	std::cout << "Copy Span assignation called" << std::endl;
	if (this != &rhs)
	{
		max = rhs.max;
		elements = rhs.elements;
	}
	return (*this);
}

Span::~Span()
{
	std::cout << "Destructor for Span called" << std::endl;
}

// ======= FUNCTIONS =======

void Span::addNumber(int n) {
	if (elements.size() >= max) {
		throw Span::FullSpanException();
	}
	if (elements.empty() || n > elements.back()) {
        elements.push_back(n);
    } else {
		std::vector<int>::iterator iter = std::lower_bound(elements.begin(), elements.end(), n);
        elements.insert(iter, n);
	}
}

void Span::addRange(const int* first, const int* last) {
	while (first != last)
		addNumber(*first++);
	std::sort(elements.begin(), elements.end());
}

int Span::shortestSpan() const {
	if (elements.size() < 2)
		throw Span::LessThanTwoElementsException();

	int shortestSpan = INT_MAX;
	for (size_t i = 0; i < elements.size(); ++i) {
		int currentSpan = elements[i] - elements[i - 1];
		shortestSpan = (currentSpan < shortestSpan) ? currentSpan : shortestSpan;
	}
	return shortestSpan;
}

int Span::longestSpan() const {
	if (elements.size() < 2)
		throw Span::LessThanTwoElementsException();
	return elements.back() - elements.front();
}

std::vector<int> const &Span::getElements(void) const 
{ 
	return (this->elements); 
}

// ======= EXCEPTIONS ======= 

const char *Span::LessThanTwoElementsException::what() const throw()
{
	return "2 or more elements needed to calculate Span";
}

const char *Span::FullSpanException::what() const throw()
{
	return "Vector is full, no element can be added";
}