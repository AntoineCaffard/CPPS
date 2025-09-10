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
        _merge_insertion_sort_vector(vec, 1);
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
        // _merge_insertion_sort(deque, 1);
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

long _jacobsthal_number(long n) 
{
     return round((pow(2, n + 1) + pow(-1, n)) / 3);
}

void PmergeMe::_pair_swap_vector(std::vector<int>::iterator start, std::vector<int>::iterator end, int pair_level)
{
    int jump = 2 * pair_level;
    for (std::vector<int>::iterator it = start; it != end; std::advance(it, jump))
    {
        std::vector<int>::iterator this_pair = next(it, pair_level - 1);
        std::vector<int>::iterator next_pair = next(it, pair_level * 2 - 1);
        if (_comp(next_pair, this_pair))
        {
            _swap_pair(this_pair, pair_level);
        }
    }
}

void PmergeMe::_insert_vector(std::vector<int>& container, int pair_level, bool is_odd, std::vector<int>::iterator end)
{
       std::vector<std::vector<int>::iterator> main;
       std::vector<std::vector<int>::iterator> pend;
   
       main.insert(main.end(), next(container.begin(), pair_level - 1));
       main.insert(main.end(), next(container.begin(), pair_level * 2 - 1));
   
       for (size_t i = 4; i <= container.size() / 2; i += 2)
       {
           pend.insert(pend.end(), next(container.begin(), pair_level * (i - 1) - 1));
           main.insert(main.end(), next(container.begin(), pair_level * i - 1));
       }
       if (is_odd)
           pend.insert(pend.end(), next(end, pair_level - 1));
   
    //    JACOBSTHAL INSERT
       int prev_jacobsthal = _jacobsthal_number(1);
       int inserted_numbers = 0;
       for (int k = 2;; k++)
       {
           int curr_jacobsthal = _jacobsthal_number(k);
           int jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;
           int offset = 0;
           if (jacobsthal_diff > static_cast<int>(pend.size()))
               break;
           int nbr_of_times = jacobsthal_diff;
           typename std::vector<std::vector<int>::iterator>::iterator pend_it = next(pend.begin(), jacobsthal_diff - 1);
           typename std::vector<std::vector<int>::iterator>::iterator bound_it =
               next(main.begin(), curr_jacobsthal + inserted_numbers);
           while (nbr_of_times)
           {
               typename std::vector<std::vector<int>::iterator>::iterator idx =
                   std::upper_bound(main.begin(), bound_it, *pend_it, _comp<std::vector<int>::iterator>);
               typename std::vector<std::vector<int>::iterator>::iterator inserted = main.insert(idx, *pend_it);
               nbr_of_times--;
               pend_it = pend.erase(pend_it);
               std::advance(pend_it, -1);
               /* Sometimes the inserted number in inserted at the exact index of where the bound should be.
                  When this happens, it eclipses the bound of the next pend, and it does more comparisons
                  than it should. We need to offset when this happens. */
               offset += (inserted - main.begin()) == curr_jacobsthal + inserted_numbers;
               bound_it = next(main.begin(), curr_jacobsthal + inserted_numbers - offset);
           }
           prev_jacobsthal = curr_jacobsthal;
           inserted_numbers += jacobsthal_diff;
           offset = 0;
       }
   
       /* Insert the remaining elements in the reversed order. Here we also want to
          perform as less comparisons as possible, so we calculate the starting bound
          to insert pend number to be the pair of the first pend number. If the first
          pend number is b8, the bound is a8, if the pend number is b7, the bound is a7 etc.
          With the way I do it the index of bound is
          size_of_main - size_of_pend + index_of_current_pend. */
       for (ssize_t i = pend.size() - 1; i >= 0; i--)
       {
           typename std::vector<std::vector<int>::iterator>::iterator curr_pend = next(pend.begin(), i);
           typename std::vector<std::vector<int>::iterator>::iterator curr_bound =
               next(main.begin(), main.size() - pend.size() + i + is_odd);
           typename std::vector<std::vector<int>::iterator>::iterator idx =
               std::upper_bound(main.begin(), curr_bound, *curr_pend, _comp<std::vector<int>::iterator>);
           main.insert(idx, *curr_pend);
       }
   
       /* Use copy vector to store all the numbers, in order not to overwrite the
          original iterators. */
       std::vector<int> copy;
       copy.reserve(container.size());
       for (typename std::vector<std::vector<int>::iterator>::iterator it = main.begin(); it != main.end(); it++)
       {
           for (int i = 0; i < pair_level; i++)
           {
               std::vector<int>::iterator pair_start = *it;
               std::advance(pair_start, -pair_level + i + 1);
               copy.insert(copy.end(), *pair_start);
           }
       }
   
       /* Replace values in the original container. */
       std::vector<int>::iterator container_it = container.begin();
       std::vector<int>::iterator copy_it = copy.begin();
       while (copy_it != copy.end())
       {
           *container_it = *copy_it;
           container_it++;
           copy_it++;
       }
}

void PmergeMe::_merge_insertion_sort_vector(std::vector<int>& container, int pair_level)
{
    bool    is_odd;
    int     pair_units_nbr;

    std::vector<int>::iterator start;
    std::vector<int>::iterator last;
    std::vector<int>::iterator end;

    pair_units_nbr = container.size() / pair_level;
    is_odd = pair_units_nbr % 2 == 1;
    if (pair_units_nbr < 2)
        return;

    start = container.begin();
    last = next(container.begin(), pair_level * (pair_units_nbr));
    end = next(last, -(is_odd * pair_level));

    _pair_swap_vector(start, end, pair_level);
    _merge_insertion_sort_vector(container, pair_level * 2);
    _insert_vector(container, pair_level, is_odd, end);

}