#include "PmergeMe.hpp"

int main (int ac, char **av)
{
    try
    {
        if (ac < 2)
            return 1;
        PMergeMe<std::vector <int> > merger;
        merger.process(ac, av);
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}