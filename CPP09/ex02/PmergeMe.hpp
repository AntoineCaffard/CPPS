#pragma once

#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"

class PmergeMe
{
  public:
    PmergeMe();
    PmergeMe(const PmergeMe& pm);
    PmergeMe& operator=(const PmergeMe& pm);
    ~PmergeMe();

    void sort_vec(int ac, char **av);
    void sort_deque(int ac, char **av);

  private:
    void _merge_insertion_sort_vector(std::vector<int>& container, int pair_level);
    void _pair_swap_vector(std::vector<int>::iterator start, std::vector<int>::iterator end, int pair_level);
    void _insert_vector(std::vector<int>& container, int pair_level, bool is_odd, std::vector<int>::iterator end);
    template <typename T> void _swap_pair(T it, int pair_level);
};

template <typename T> bool _comp(T lv, T rv) {
	return *lv < *rv;
}

template <typename T> T next(T it, int steps)
{
    std::advance(it, steps);
    return it;
}

template <typename T> void PmergeMe::_swap_pair(T it, int pair_level)
{
    T start = next(it, -pair_level + 1);
    T end = next(start, pair_level);
    while (start != end)
    {
        std::iter_swap(start, next(start, pair_level));
        start++;
    }
}

template <typename Container>
void print(Container &cont)
{
    for (typename Container::iterator it = cont.begin(); it != cont.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void    checkValidNumber(const std::string &input);

template <typename Container>
void    verifyAndAppendInput(int ac, char **av, Container &cont)
{
    try
    {
        for (int i = 1; i < ac; ++i)
        {
            checkValidNumber(av[i]);
            if (std::find(cont.begin(), cont.end(), std::atoi(av[i])) != cont.end())
                throw std::runtime_error("Invalid Input : Dups are forbidden");
            cont.push_back(std::atoi(av[i]));
        }
    }
    catch(const std::exception& e)
    {
        throw std::runtime_error(e.what());
    }
}

