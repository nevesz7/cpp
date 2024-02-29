#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <climits>
# include <iostream>
# include <vector>

class Span
{
	private:
		size_t				max;
		std::vector<int>	elements;
	public:
		Span();
		Span(const Span &copy);
		Span(size_t n);
		Span &operator=(const Span &rhs);
		~Span();

		int  shortestSpan(void) const;
		int  longestSpan(void) const;

		void addNumber(int num);
		void addRange(const int* first, const int* last);

		std::vector<int> const &getElements(void) const;

		class LessThanTwoElementsException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class FullSpanException : public std::exception
		{
			virtual const char *what() const throw();
		};
};

#endif
