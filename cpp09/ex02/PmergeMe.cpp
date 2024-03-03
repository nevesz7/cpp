#include "PmergeMe.hpp"

// =========== CONSTRUCTORS AND DESTRUCTORS ===========

PmergeMe::PmergeMe(void)
{
	// std::cout << "Default PmergeMe constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	// std::cout << "Copy PmergeMe constructor called" << std::endl;
	*this = copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &rhs)
{
	// std::cout << "Copy PmergeMe assignation called" << std::endl;
	if (this != &rhs)
	{}
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
	// std::cout << "Destructor for PmergeMe called" << std::endl;
}

void PmergeMe::run(int quantity, const char **input)
{
	runList(quantity, input);
	runVector(quantity, input);
}

// =========== List ===========

void PmergeMe::sortPairs(std::list<std::pair<int, int> > &list, size_t size)
{
	if (size <= 1)
		return ;
	std::list<std::pair<int, int> >				left;
	std::list<std::pair<int, int> >				right;
	std::list<std::pair<int, int> >::iterator	it = list.begin();
	for (size_t i = 0; i < size / 2; i++)
		left.push_back(*it++);
	for (size_t i = size / 2; i < size; i++)
		right.push_back(*it++);
	list.clear();
	sortPairs(left, left.size());
	sortPairs(right, right.size());
	while (right.size() && left.size()) 
	{
		if (left.front().first < right.front().first)
		{
			list.push_back(left.front());
			left.pop_front();
		}
		else
		{
			list.push_back(right.front());
			right.pop_front();
		}
	}
	while (left.size())
	{
		list.push_back(left.front());
		left.pop_front();
	}
	while (right.size())
	{
		list.push_back(right.front());
		right.pop_front();
	}
	return ;
}

std::list<int> PmergeMe::sort(std::list<int> &list)
{
	if (list.size() <= 1)
		return (list);
	int last = -1;
	if (list.size() % 2 != 0)
	{
		last = list.back();
		list.pop_back();
	}
	std::list<std::pair<int, int> >	pairs;
	for (std::list<int>::iterator	it = list.begin(); it != list.end(); it++)
	{
		int first = *it++;
		int second = *it;
		if (first < second)
			pairs.push_back(std::make_pair(second, first));
		else
			pairs.push_back(std::make_pair(first, second));
	}
	sortPairs(pairs, pairs.size());
	std::list<int>	sorted;
	std::list<int>	unsorted;
	for (std::list<std::pair<int, int> >::iterator	it = pairs.begin(); it != pairs.end(); it++)
	{
		sorted.push_back(it->first);
		unsorted.push_back(it->second);
	}
	if (last != -1)
		unsorted.push_back(last);
	sorted.push_front(unsorted.front());
	unsorted.pop_front();
    for (std::list<int>::iterator itp = unsorted.begin(); itp != unsorted.end(); ++itp) {
		int element = *itp;
		if (element < sorted.front())
		{
			sorted.push_front(element);
		}
		else
		{
			std::list<int>::iterator it_lower = std::lower_bound(sorted.begin(), sorted.end(), element);
			sorted.insert(it_lower, element);
		}
    }
	return (sorted);
}

void PmergeMe::runList(int quantity, const char **input)
{
	std::list<int>	inputSeq;
	clock_t			start = clock();

	for (int i = 1; i < quantity; i++)
		inputSeq.push_back(std::atoi(input[i]));
	std::cout << "Before : ";
	printContainer(inputSeq);
	std::list<int>	finalSeq = sort(inputSeq);
	std::cout << "After : ";
	printContainer(finalSeq);
	clock_t end = clock();
	double duration = double(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << finalSeq.size()
			<< " elements with std::list : " << std::fixed << duration
			<< " seconds" << std::endl;
}

// =========== Vector ===========

void PmergeMe::sortPairs(std::vector<std::pair<int, int> > &vector, size_t size)
{
	if (size <= 1)
		return ;
	std::vector<std::pair<int, int> >				left;
	std::vector<std::pair<int, int> >				right;
	std::vector<std::pair<int, int> >::iterator	it = vector.begin();
	for (size_t i = 0; i < size / 2; i++)
		left.push_back(*it++);
	for (size_t i = size / 2; i < size; i++)
		right.push_back(*it++);
	vector.clear();
	sortPairs(left, left.size());
	sortPairs(right, right.size());
	while (right.size() && left.size()) 
	{
		if (left.front().first < right.front().first)
		{
			vector.push_back(left.front());
			left.erase(left.begin());
		}
		else
		{
			vector.push_back(right.front());
			right.erase(right.begin());
		}
	}
	while (left.size())
	{
		vector.push_back(left.front());
		left.erase(left.begin());
	}
	while (right.size())
	{
		vector.push_back(right.front());
		right.erase(right.begin());
	}
	return ;
}

std::vector<int> PmergeMe::sort(std::vector<int> &vector)
{
	if (vector.size() <= 1)
		return (vector);
	int last = -1;
	if (vector.size() % 2 != 0)
	{
		last = vector.back();
		vector.pop_back();
	}
	std::vector<std::pair<int, int> >	pairs;
	for (std::vector<int>::iterator	it = vector.begin(); it != vector.end(); it++)
	{
		int first = *it++;
		int second = *it;
		if (first < second)
			pairs.push_back(std::make_pair(second, first));
		else
			pairs.push_back(std::make_pair(first, second));
	}
	sortPairs(pairs, pairs.size());
	std::vector<int>	sorted;
	std::vector<int>	unsorted;
	for (std::vector<std::pair<int, int> >::iterator	it = pairs.begin(); it != pairs.end(); it++)
	{
		sorted.push_back(it->first);
		unsorted.push_back(it->second);
	}
	if (last != -1)
		unsorted.push_back(last);
	sorted.insert(sorted.begin(), unsorted.front());
	unsorted.erase(unsorted.begin());
    for (std::vector<int>::iterator itp = unsorted.begin(); itp != unsorted.end(); ++itp) {
		int element = *itp;
		if (element < sorted.front())
		{
			sorted.insert(sorted.begin(), element);
		}
		else
		{
			std::vector<int>::iterator it_lower = std::lower_bound(sorted.begin(), sorted.end(), element);
			sorted.insert(it_lower, element);
		}
    }
	return (sorted);
}

void PmergeMe::runVector(int quantity, const char **input)
{
	std::vector<int>	inputSeq;
	clock_t			start = clock();

	for (int i = 1; i < quantity; i++)
		inputSeq.push_back(std::atoi(input[i]));
	std::cout << "Before : ";
	printContainer(inputSeq);
	std::vector<int>	finalSeq = sort(inputSeq);
	std::cout << "After : ";
	printContainer(finalSeq);
	clock_t end = clock();
	double duration = double(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << finalSeq.size()
			<< " elements with std::vector : " << std::fixed << duration
			<< " seconds" << std::endl;
}
