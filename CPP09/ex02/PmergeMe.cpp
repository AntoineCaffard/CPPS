#include "PmergeMe.hpp"
#include <cmath>
#include <deque>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& pm) { (void)pm; }
PmergeMe& PmergeMe::operator=(const PmergeMe& pm)
{
    (void)pm;
    return *this;
}
PmergeMe::~PmergeMe() {}

void PmergeMe::sort_vec(std::vector<int>& vec) { _merge_insertion_sort<std::vector<int> >(vec, 1); }

void PmergeMe::sort_deque(std::deque<int>& deque)
{
    _merge_insertion_sort<std::deque<int> >(deque, 1);
}