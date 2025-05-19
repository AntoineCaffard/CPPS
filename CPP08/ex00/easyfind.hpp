/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:12:05 by acaffard          #+#    #+#             */
/*   Updated: 2025/05/06 15:53:37 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <cstdlib>

class ValueNotFoundException : public std::exception
{
	virtual const char *what() const throw()
	{
		return ("Error : Value not found");
	};
};

void	print_int(int value)
{
	std::cout << value << std::endl;
};

template <typename T>
void	fill(T &container, unsigned int nb_elements, int range, typename T::iterator* = 0)
{
	for(unsigned int i = 0; i < nb_elements; ++i)
		container.push_back(rand() % range);
};

template <typename T>
void	fill(...)
{
	std::cerr << "Wololo" << std::endl;
};

template <typename T>
typename T::iterator	easyfind(T container, int to_find)
{
	typename T::iterator result;
	result = std::find(container.begin(), container.end(), to_find);
	if (result == container.end())
		throw ValueNotFoundException();
	return result;
};
