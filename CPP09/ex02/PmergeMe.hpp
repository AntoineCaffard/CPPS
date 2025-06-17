#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define GREEN   "\033[32m"

template <typename Container>
class PMergeMe
{
    private :
        clock_t                             _startTimer;
        clock_t                             _endTimer;
        double                              _sortTime;

        int                                _pairValue;

    public :
        PMergeMe();
        ~PMergeMe();
        PMergeMe(const PMergeMe &copy);
        PMergeMe &operator=(const PMergeMe &copy);

        void    _processVector(int ac, char **av);
        void    _processDeque(int ac, char **av);
    
    private :
        void    _verifyAndAppendInput(int ac, char **av, Container &cont);
        void    _checkValidNumber(const std::string &input);
        int     _calculateJacobsthal(int k);
        void    _fordJohnsonSort(Container &cont);
        void    _insert(Container &main, Container &pend, int odd, Container &left, Container &vec, bool is_odd, int order);
        
};

#include "PmergeMe.tpp"