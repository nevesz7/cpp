#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T> class MutantStack : public std::stack<T>
{
  public:
		typedef typename std::stack<T>::container_type::iterator				iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator		rev_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_rev_iterator;

		MutantStack();
		MutantStack(MutantStack const &copy);
		MutantStack<T> &operator=(MutantStack const &rhs);
		~MutantStack();

		iterator			begin();
		iterator			end();
		rev_iterator		revBegin();
		rev_iterator		revEnd();

		const_iterator		begin() const;
		const_iterator		end() const;
		const_rev_iterator	revBegin() const;
		const_rev_iterator	revEnd() const;
};

#endif