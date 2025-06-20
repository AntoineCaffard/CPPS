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
void    PMergeMe<Container>::_verifyAndAppendInput(int ac, char **av, Container &cont)
{
    try
    {
        for (int i = 1; i < ac; ++i)
        {
            _checkValidNumber(av[i]);
            // if (std::find(cont.begin(), cont.end(), std::atoi(av[i])) != cont.end())
            //     throw std::runtime_error("Invalid Input : Dups are forbidden");
            cont.push_back(std::atoi(av[i]));
        }
    }
    catch(const std::exception& e)
    {
        throw std::runtime_error(e.what());
    }
}

template <typename Container>
void    PMergeMe<Container>::_processVector(int ac, char **av)
{
    try
    {
        std::cout << YELLOW << "PROCESSING VECTOR ..." << RESET << std::endl;
        std::vector<int> vec;
        _verifyAndAppendInput(ac, av, vec);
        print(vec);
        _startTimer = clock();
        _fordJohnsonSort(vec);
        _endTimer = clock();
        _sortTime = 1000000.0 * (_endTimer - _startTimer) / CLOCKS_PER_SEC;
        std::cout << GREEN;
        print(vec);
        std::cout << YELLOW << "Done in " << _sortTime << "μs" << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

template <typename Container>
void    PMergeMe<Container>::_processDeque(int ac, char **av)
{
    try
    {
        std::cout << YELLOW << "PROCESSING DEQUE ..." << RESET << std::endl;
        std::deque<int> dec;
        _verifyAndAppendInput(ac, av, dec);
        print(dec);
        _startTimer = clock();
        _fordJohnsonSort(dec);
        _endTimer = clock();
        _sortTime = 1000000.0 * (_endTimer - _startTimer) / CLOCKS_PER_SEC;
        std::cout << GREEN;
        print(dec);
        std::cout << YELLOW << "Done in " << _sortTime << "μs" << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

template <typename Container>
int PMergeMe<Container>::_calculateJacobsthal(int k)
{
    return round((pow(2, k + 1) + pow(-1, k)) /3);
}

template <typename Container>
void PMergeMe<Container>::_insert(Container &main, Container &pending, int odd, Container &left, Container &vec, bool is_odd, int order) {

    typename Container::iterator end;

    if (pending.size() == 1) {
        end = std::upper_bound(main.begin(), main.end(), *pending.begin());
        main.insert(end, *pending.begin());
    } else if (pending.size() > 1) {
        size_t jacobIndex = 3;
        size_t count = 0;
        size_t idx;
        size_t decrease;
        
        while (!pending.empty()) {
            idx = _calculateJacobsthal(jacobIndex) - _calculateJacobsthal(jacobIndex - 1);
            if (idx > pending.size())
                idx = pending.size();

            decrease = 0;
            while (idx) {
                end = main.begin();
                if (_calculateJacobsthal(jacobIndex + count) - decrease <= main.size())
                    end = main.begin() + _calculateJacobsthal(jacobIndex + count) - decrease;
                else
                    end = main.end();
                end = std::upper_bound(main.begin(), end, *(pending.begin() + idx - 1));
                main.insert(end, *(pending.begin() + idx - 1));
                pending.erase(pending.begin() + idx - 1);
                idx--;
                decrease++;
                count++;
            }
            jacobIndex++;
        }
    }

    Container tmp;
    
    if (is_odd) {
        end = std::upper_bound(main.begin(), main.end(), odd);
        main.insert(end, odd);
    }
    for (typename Container::iterator  i = main.begin(); i != main.end(); i++) {
        typename Container::iterator  it = std::find(vec.begin(), vec.end(), *i);
        std::cout << *(it )<< std::endl;
        tmp.insert(tmp.end(), it - (order - 1), it + 1);
    }
    tmp.insert(tmp.end(), left.begin(), left.end());
    vec = tmp;
}

template <typename Container>
void PMergeMe<Container>::_fordJohnsonSort(Container &vec) {

    int nbPairs = vec.size() / _pairValue;
    if (nbPairs < 2)
        return;

    bool is_odd = nbPairs % 2 == 1;
    typename Container::iterator  start = vec.begin();
    typename Container::iterator  end = vec.begin() + ((_pairValue * nbPairs) - (is_odd * _pairValue));

    for (typename Container::iterator  it = start; it < end; it += (_pairValue * 2))
    {
        if (*(it + (_pairValue - 1)) > *(it + ((_pairValue * 2) - 1)))
        {
            for (int i = 0; i < _pairValue; i++)
                std::swap(*(it + i), *(it + i + _pairValue));
        }
    }
    _pairValue *= 2; 
    _fordJohnsonSort(vec); 
    _pairValue /= 2;

    Container main;
    Container pending;
    Container left;
    int oddValue = 0;

    main.push_back(*(start + _pairValue - 1));
    main.push_back(*(start + _pairValue * 2 - 1));

    for (typename Container::iterator  it = start + _pairValue * 2; it < end; it += _pairValue)
    {
        pending.push_back(*(it + _pairValue - 1));
        it += _pairValue;
        main.push_back(*(it + _pairValue - 1));
    }

    if (is_odd)
        oddValue = *(end + _pairValue - 1);

    left.insert(left.end(), end + (_pairValue * is_odd), vec.end()); 

    if (is_odd || !pending.empty())
        _insert(main, pending, oddValue, left, vec, is_odd, _pairValue);
}
