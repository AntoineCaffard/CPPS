#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
class PmergeMe
{
  public:
    PmergeMe();
    PmergeMe(const PmergeMe& pm);
    PmergeMe& operator=(const PmergeMe& pm);
    ~PmergeMe();

    void sort_vec(std::vector<int>& vec);
    void sort_deque(std::deque<int>& deque);

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

    std::vector<Iterator> main;
    std::vector<Iterator> pend;

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

    std::vector<int> copy;
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
#endif