/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:09:29 by acaffard          #+#    #+#             */
/*   Updated: 2025/03/17 11:31:21 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T>
void iter(T *array, unsigned int N, void (&foo)(T&))
{
	for (int i = 0; i < N; ++i)
		foo(array[i]);
};

template<typename T>
void print(T &value)
{
	std::cout << value << std::endl;	
};

template<typename T>
void addOne(T &value)
{
	value += 1;
};