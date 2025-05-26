#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

class PMergeMe
{
    private :
        std::vector<int>                    _vector;
        std::deque<int>                     _deque;
        std::vector<std::pair<int, int> >   _pairs;
        std::vector<int>                    _resultVector;
        std::deque<int>                     _resultDeque;
        clock_t                             _dequeStartTimer;
        clock_t                             _vectorStartTimer;
        clock_t                             _dequeEndTimer;
        clock_t                             _vectorEndTimer;
        double                              _vectorSortTime;
        double                              _dequeSortTime;

    public :
        PMergeMe();
        ~PMergeMe();
        PMergeMe(const PMergeMe &copy);
        PMergeMe &operator=(const PMergeMe &copy);

        void process(int ac, char **av);
    
    private :
        void    _verifyAndAppendInput(int ac, char **av);
        void    _checkValidNumber(const std::string &input);
        void    _createPairs();
        void    _GetMinsFromPairsDeque();
        void    _GetMinsFromPairsVector();
        void    _insertMaxsVector();
        void    _insertMaxsDeque();
        void    _startDequeTimer();
        void    _stopDequeTimer();
        void    _startVectorTimer();
        void    _stopVectorTimer();
        void    _processVector();
        void    _processDeque();
        void    _displayOriginalContainers();
        void    _displayFinalContainers();
};

void printDeque(std::deque<int> &deque);
void printVector(std::vector<int> &vector);