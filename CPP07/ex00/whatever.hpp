/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:27:11 by acaffard          #+#    #+#             */
/*   Updated: 2025/03/17 11:26:48 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T>
void	swap(T &x, T &y)
{
	T	buffer;
	buffer = x;
	x = y;
	y = buffer;
};

template<typename T>
T const &max(T const &x, T const &y)
{
	return (x >= y ? x : y);
};

template<typename T>
T const &min(T const &x, T const &y)
{
	return (x < y ? x : y);
};