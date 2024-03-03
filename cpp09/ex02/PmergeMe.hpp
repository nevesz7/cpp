#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <vector>

class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &rhs);
		~PmergeMe(void);

		void run(int quantity, const char **input);

	private:
		void					runList(int quantity, const char **input);
		static std::list<int>	sort(std::list<int> &list);
		static void				sortPairs(std::list<std::pair<int, int> > &list, size_t size);

		void					runVector(int quantity, const char **input);
		static std::vector<int>	sort(std::vector<int> &vector);
		static void				sortPairs(std::vector<std::pair<int, int> > &vector, size_t size);
};

template<typename T>
void printContainer(T& container) {
    std::cout << "[ ";
    for (typename T::iterator iter = container.begin(); iter != container.end(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << "]" << std::endl;
}

template<typename T>
void printContainer(const T& container) {
    std::cout << "[ ";
    for (typename T::const_iterator iter = container.begin(); iter != container.end(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << "]" << std::endl;
}

#endif