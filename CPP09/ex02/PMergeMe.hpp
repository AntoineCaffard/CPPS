#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

class PMergeMe
{
    private :
        std::vector<int>                    _vector;
        std::deque<int>                     _deque;
        std::vector<std::pair<int, int> >   _pairs;
        std::vector<int>                    _resultVector;
        std::deque<int>                     _resultDeque;

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
        void    _GetMinsFromPairs();
        void    _insertMaxsVector();
        void    _insertMaxsDeque();
};