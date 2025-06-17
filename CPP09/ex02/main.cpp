#include "PmergeMe.hpp"

int main (int ac, char **av)
{
    try
    {
        if (ac < 2)
            return 1;
        PMergeMe<std::deque<int> > mergerDeq;
        mergerDeq._processDeque(ac, av);
        PMergeMe<std::vector<int> > mergerVec;
        mergerVec._processVector(ac, av);
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}