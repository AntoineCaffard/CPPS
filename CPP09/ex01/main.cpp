#include "RPN.hpp"

int main (int ac, char **av)
{
    try
    {
        if (ac != 2 || !(*av[1]))
            throw NotEnoughArgumentsException();
        initRPNCalculator(av[1]);
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}