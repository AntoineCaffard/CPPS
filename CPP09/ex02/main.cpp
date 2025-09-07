#include "PmergeMe.hpp"

int main (int ac, char **av)
{
    try
    {
        if (ac < 2)
            return 1;
        PmergeMe merger;
        merger.sort_vec(ac, av);
        merger.sort_deque(ac, av);
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}