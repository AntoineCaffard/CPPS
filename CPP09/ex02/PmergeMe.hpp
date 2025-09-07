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
    template <typename T> void _merge_insertion_sort(T& container, int pair_level);
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

template <typename T> void PmergeMe::_merge_insertion_sort(T& container, int pair_level)
{
    typedef typename T::iterator Iterator;

    int pair_units_nbr = container.size() / pair_level;
    if (pair_units_nbr < 2)
        return;
    bool is_odd = pair_units_nbr % 2 == 1;
    Iterator start = container.begin();

    Iterator last = next(container.begin(), pair_level * (pair_units_nbr));
    Iterator end = next(last, -(is_odd * pair_level));

    std::vector<Iterator> main;
    std::vector<Iterator> pend;
    std::vector<int> copy;

    for (Iterator it = start; it != end; std::advance(it, 2 * pair_level))
    {
        Iterator this_pair = next(it, pair_level - 1);
        Iterator next_pair = next(it, pair_level * 2 - 1);
        if (_comp(next_pair, this_pair))
        {
            _swap_pair(this_pair, pair_level);
        }
    }
    _merge_insertion_sort(container, pair_level * 2);
    main.insert(main.end(), next(container.begin(), pair_level - 1));
    main.insert(main.end(), next(container.begin(), pair_level * 2 - 1));
    for (int i = 4; i <= pair_units_nbr; i += 2)
    {
        pend.insert(pend.end(), next(container.begin(), pair_level * (i - 1) - 1));
        main.insert(main.end(), next(container.begin(), pair_level * i - 1));
    }
    if (is_odd)
        pend.insert(pend.end(), next(end, pair_level - 1));

    for (typename std::vector<Iterator>::iterator it = pend.begin(); it != pend.end(); it++)
        main.insert(std::upper_bound(main.begin(),main.end(), *it, _comp<Iterator>), *it);

    
    for (typename std::vector<Iterator>::iterator it = main.begin(); it != main.end(); ++it)
    {
        Iterator pair_start = *it;
        std::advance(pair_start, -(pair_level - 1));
        for (int i = 0; i < pair_level; ++i, ++pair_start)
            copy.push_back(*pair_start);
    }

    Iterator container_it = container.begin();
    std::vector<int>::iterator copy_it = copy.begin();
    while (copy_it != copy.end())
    {
        *container_it = *copy_it;
        container_it++;
        copy_it++;
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

