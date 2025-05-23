#include "PMergeMe.hpp"

PMergeMe::PMergeMe()
{}

PMergeMe::~PMergeMe()
{}

PMergeMe::PMergeMe(const PMergeMe &copy)
{
    *this = copy;
}

PMergeMe &PMergeMe::operator=(const PMergeMe &copy)
{
    if (this != &copy)
    {
        this->_vector = copy._vector;
        this->_deque = copy._deque;
        this->_pairs = copy._pairs;
        this->_resultVector = copy._resultVector;
        this->_resultDeque = copy._resultDeque;
    }
    return *this;
}

void    PMergeMe::process(int ac, char **av)
{
    try
    {
        _verifyAndAppendInput(ac, av);
        _createPairs();
        _GetMinsFromPairs();
        _insertMaxsVector();
        _insertMaxsDeque();
        std::cout << "VECTOR :" << std::endl;
        for(size_t i = 0; i < _resultVector.size(); ++i)
        std::cout << _resultVector[i] << " ";
        std::cout << std::endl << "DEQUE :" << std::endl;
        for(size_t i = 0; i < _resultDeque.size(); ++i)
        std::cout << _resultDeque[i] << " ";
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void    PMergeMe::_checkValidNumber(const std::string &input)
{
    if (input.empty())
        throw std::runtime_error("Invalid Input");
    for (size_t i = 0; i < input.length(); ++i)
    {
        if(!isdigit(input[i]))
            throw std::runtime_error("Invalid Input");
    }
}

void PMergeMe::_verifyAndAppendInput(int ac, char **av)
{
    try
    {
        for (int i = 1; i < ac; ++i)
        {
            _checkValidNumber(av[i]);
            _vector.push_back(std::atoi(av[i]));
            _deque.push_back(std::atoi(av[i]));
        }
    }
    catch(const std::exception& e)
    {
        throw std::runtime_error("Invalid Input");
    }
}

void PMergeMe::_createPairs()
{
    for (size_t i = 0; i < _vector.size(); i += 2)
    {   
        if (i + 1 >= _vector.size())
            _pairs.push_back(std::make_pair(-42, _vector[i]));
        else
            _pairs.push_back(std::make_pair(std::min(_vector[i], _vector[i + 1]), std::max(_vector[i], _vector[i + 1])));
    }
}

void PMergeMe::_GetMinsFromPairs()
{
    for(std::vector<std::pair<int, int> >::iterator it = _pairs.begin(); it != _pairs.end(); ++it)
    {
        _resultVector.push_back(it->first);
        _resultDeque.push_back(it->first);
    }
}

void PMergeMe::_insertMaxsVector()
{
    std::sort(_resultVector.begin(), _resultVector.end());
    for(std::vector<std::pair<int, int> >::iterator it = _pairs.begin(); it != _pairs.end(); ++it)
        _resultVector.insert(std::lower_bound(_resultVector.begin(), _resultVector.end(), it->second), it->second);
    if (_resultVector[0] == -42)
        _resultVector.erase(_resultVector.begin());
}

void PMergeMe::_insertMaxsDeque()
{
    std::sort(_resultDeque.begin(), _resultDeque.end());
    for(std::vector<std::pair<int, int> >::iterator it = _pairs.begin(); it != _pairs.end(); ++it)
        _resultDeque.insert(std::lower_bound(_resultDeque.begin(), _resultDeque.end(), it->second), it->second);
    if (_resultDeque[0] == -42)
        _resultDeque.erase(_resultDeque.begin());
}