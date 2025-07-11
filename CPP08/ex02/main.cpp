#include "MutantStack.hpp"
#include <list>

int main()
{
    {
        std::cout << "== Mutant Stack Version ==" << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << "top :" << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "size :" <<mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
        std::stack<int> s(mstack);
    }
    {
        std::cout << "== List Stack Version ==" << std::endl;
        std::list<int> list;
        list.push_back(5);
        list.push_back(17);
        std::cout << "top :" << list.back() << std::endl;
        list.pop_back();
        std::cout << "size :" <<list.size() << std::endl;
        list.push_back(3);
        list.push_back(5);
        list.push_back(737);
        list.push_back(0);
        std::list<int>::iterator it = list.begin();
        std::list<int>::iterator ite = list.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
        std::list<int> s(list);
    }
}