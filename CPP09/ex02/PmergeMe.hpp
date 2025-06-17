#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

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

        void process(int ac, char **av);
    
    private :
        void    _verifyAndAppendInput(int ac, char **av, std::vector<int> &vector);
        void    _checkValidNumber(const std::string &input);
        int     _calculateJacobsthal(int k);
        void    _fordJohnsonSort(Container &cont);
        void    _insert(Container &main, Container &pend, int odd, Container &left, Container &vec, bool is_odd, int order);
        void    _processVector();
        void    _processDeque();
};

void printDeque(std::deque<int> &deque);
void printVector(std::vector<int> &vector);

#include "PmergeMe.tpp"