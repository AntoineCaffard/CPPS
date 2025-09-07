#include "PmergeMe.hpp"
#include <cmath>
#include <deque>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& pm)
{
    (void)pm; 
}

PmergeMe& PmergeMe::operator=(const PmergeMe& pm)
{
    (void)pm;
    return *this;
}

PmergeMe::~PmergeMe() {}

void    checkValidNumber(const std::string &input)
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

void PmergeMe::sort_vec(int ac, char **av)
{
    try
    {
        std::cout << YELLOW << "PROCESSING VECTOR ..." << RESET << std::endl;
        std::vector<int> vec;
        verifyAndAppendInput(ac, av, vec);
        print(vec);
        clock_t startTimer = clock();
        _merge_insertion_sort(vec, 1);
        clock_t endTimer = clock();
        double sortTime = 1000000.0 * (endTimer - startTimer) / CLOCKS_PER_SEC;
        std::cout << GREEN;
        print(vec);
        std::cout << YELLOW << "Done in " << sortTime << "μs" << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void PmergeMe::sort_deque(int ac, char **av)
{
    try
    {
        std::cout << YELLOW << "PROCESSING DEQUE..." << RESET << std::endl;
        std::deque<int> deque;
        verifyAndAppendInput(ac, av, deque);
        print(deque);
        clock_t startTimer = clock();
        _merge_insertion_sort(deque, 1);
        clock_t endTimer = clock();
        double sortTime = 1000000.0 * (endTimer - startTimer) / CLOCKS_PER_SEC;
        std::cout << GREEN;
        print(deque);
        std::cout << YELLOW << "Done in " << sortTime << "μs" << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}