#include "PmergeMe.hpp"

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
        _displayOriginalContainers();
        _createPairs();
        _processVector();
        _processDeque();
        _displayFinalContainers();
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Time to sort with vector : " << _vectorSortTime << "μs" << std::endl;
        std::cout << "Time to sort with deque: " << _dequeSortTime << "μs" << std::endl;
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

void PMergeMe::_GetMinsFromPairsVector()
{
    for(std::vector<std::pair<int, int> >::iterator it = _pairs.begin(); it != _pairs.end(); ++it)
        _resultVector.push_back(it->first);
}

void PMergeMe::_GetMinsFromPairsDeque()
{
    for(std::vector<std::pair<int, int> >::iterator it = _pairs.begin(); it != _pairs.end(); ++it)
        _resultDeque.push_back(it->first);
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

void PMergeMe::_startDequeTimer()
{
    _dequeStartTimer = clock();
}

void PMergeMe::_startVectorTimer()
{
    _vectorStartTimer = clock();
}

void PMergeMe::_stopDequeTimer()
{
    _dequeEndTimer = clock();
    _dequeSortTime = 1000000.0 * (_dequeEndTimer - _dequeStartTimer) / CLOCKS_PER_SEC;
}

void PMergeMe::_stopVectorTimer()
{
    _vectorEndTimer = clock();
    _vectorSortTime = 1000000.0 * (_vectorEndTimer - _vectorStartTimer) / CLOCKS_PER_SEC;
}

void    PMergeMe::_processVector()
{
    _startVectorTimer();
    _GetMinsFromPairsVector();
    _insertMaxsVector();
    _stopVectorTimer();
}
void    PMergeMe::_processDeque()
{
    _startDequeTimer();
    _GetMinsFromPairsDeque();
    _insertMaxsDeque();
    _stopDequeTimer();
}

void    PMergeMe::_displayOriginalContainers()
{
    std::cout << "VECTOR INPUT :" << std::endl;
    printVector(_vector);
    std::cout << "DEQUE INPUT :" << std::endl;
    printDeque(_deque);
}
void    PMergeMe::_displayFinalContainers()
{
    std::cout << "VECTOR OUTPUT :" << std::endl;
    printVector(_resultVector);
    std::cout << "DEQUE OUTPUT :" << std::endl;
    printDeque(_resultDeque);
}

void printDeque(std::deque<int> &deque)
{
    for(std::deque<int>::iterator it = deque.begin(); it < deque.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void printVector(std::vector<int> &vector)
{
    for(std::vector<int>::iterator it = vector.begin(); it < vector.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}