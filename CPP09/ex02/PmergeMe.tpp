#pragma once

#include "PmergeMe.hpp"
#include <cmath>
#include <iterator>

template <typename Container>
PMergeMe<Container>::PMergeMe() : _pairValue(1)
{}

template <typename Container>
PMergeMe<Container>::~PMergeMe()
{}

template <typename Container>
void print(Container &cont)
{
    for (typename Container::iterator it = cont.begin(); it != cont.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

template <typename Container>
void    PMergeMe<Container>::_checkValidNumber(const std::string &input)
{
    if (input.empty())
        throw std::runtime_error("Invalid Input");
    for (size_t i = 0; i < input.length(); ++i)
    {
        if(!isdigit(input[i]))
            throw std::runtime_error("Invalid Input");
    }
    if (std::atoi(input.c_str()) < 0)
        throw std::runtime_error("Invalid Input");
}

template <typename Container>
void    PMergeMe<Container>::_verifyAndAppendInput(int ac, char **av, std::vector<int> &vector)
{
    try
    {
        for (int i = 1; i < ac; ++i)
        {
            _checkValidNumber(av[i]);
            vector.push_back(std::atoi(av[i]));
        }
    }
    catch(const std::exception& e)
    {
        throw std::runtime_error("Invalid Input");
    }
}

template <typename Container>
void PMergeMe<Container>::process(int ac, char **av)
{
    try
    {
        std::vector<int> test;
        _verifyAndAppendInput(ac, av, test);
        print(test);
        _fordJohnsonSort(test);
        print(test);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

template <typename Container>
int PMergeMe<Container>::_calculateJacobsthal(int k)
{
    return round((pow(2, k + 1) + pow(-1, k))/3);
}

template <typename Container>
void PMergeMe<Container>::_insert(Container &main, Container &pend, int odd, Container &left, Container &vec, bool is_odd, int order) {

    typename Container::iterator end;

    if (pend.size() == 1) {
        end = std::upper_bound(main.begin(), main.end(), *pend.begin());
        main.insert(end, *pend.begin());
    } else if (pend.size() > 1) {
        size_t jc = 3;
        size_t count = 0;
        size_t idx;
        size_t decrease;
        
        while (!pend.empty()) {
            idx = _calculateJacobsthal(jc) - _calculateJacobsthal(jc - 1);
            if (idx > pend.size())
                idx = pend.size();

            decrease = 0;
            while (idx) {
                end = main.begin();
                if (_calculateJacobsthal(jc + count) - decrease <= main.size())
                    end = main.begin() + _calculateJacobsthal(jc + count) - decrease;
                else
                    end = main.end();
                end = std::upper_bound(main.begin(), end, *(pend.begin() + idx - 1));
                main.insert(end, *(pend.begin() + idx - 1));
                pend.erase(pend.begin() + idx - 1);

                idx--;
                decrease++;
                count++;
            }
            jc++;
        }
    }

    Container yaslam;
    
    if (is_odd) {
        end = std::upper_bound(main.begin(), main.end(), odd);
        main.insert(end, odd);
    }
    for (typename Container::iterator  i = main.begin(); i != main.end(); i++) {
        typename Container::iterator  it = std::find(vec.begin(), vec.end(), *i);
        yaslam.insert(yaslam.end(), it - (order - 1), it + 1);
    }
    yaslam.insert(yaslam.end(), left.begin(), left.end());
    vec = yaslam;
}

template <typename Container>
void PMergeMe<Container>::_fordJohnsonSort(Container &vec) {

    int nbPairs = vec.size() / _pairValue;
    if (nbPairs < 2)
        return;

    bool is_odd = nbPairs % 2 == 1;
    typename Container::iterator  start = vec.begin();
    typename Container::iterator  end = vec.begin() + ((_pairValue * nbPairs) - (is_odd * _pairValue));

    for (typename Container::iterator  it = start; it < end; it += (_pairValue * 2)) {
        if (*(it + (_pairValue - 1)) > *(it + ((_pairValue * 2) - 1))) {
            for (int i = 0; i < _pairValue; i++) {
                std::swap(*(it + i), *(it + i + _pairValue));
            }
        }
    }
    std::cout << _pairValue << " : ";
    print(vec);

    _pairValue *= 2; 
    _fordJohnsonSort(vec); 
    _pairValue /= 2;

    Container main;
    Container pend;
    int odd = 0;
    Container left;

    main.push_back(*(start + _pairValue - 1));
    main.push_back(*(start + _pairValue * 2 - 1));

    for (typename Container::iterator  it = start + _pairValue * 2; it < end; it += _pairValue) {
        pend.push_back(*(it + _pairValue - 1));
        it += _pairValue;
        main.push_back(*(it + _pairValue - 1));
    }

    if (is_odd)
        odd = *(end + _pairValue - 1);

    left.insert(left.end(), end + (_pairValue * is_odd), vec.end()); 

    if (is_odd || !pend.empty())
        _insert(main, pend, odd, left, vec, is_odd, _pairValue);
}
