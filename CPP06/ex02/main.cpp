#include "utils.hpp"

int main()
{
    srand(time(NULL));
    Base *ptr = generate();
    Base &ref = *ptr;
    identify(ptr);
    identify(ref);
    delete ptr;
    return 0;
}