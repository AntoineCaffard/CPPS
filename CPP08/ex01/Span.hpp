/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:07:46 by acaffard          #+#    #+#             */
/*   Updated: 2025/03/24 15:44:09 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <list>
#include <iterator>
#include <deque>

class Span
{
	private :
		unsigned int	_N;
		std::deque<int>	_content;
	public :
		Span(unsigned int N);
		Span(const Span &copy);
		virtual	~Span();
		Span	&operator=(const Span &copy);
		
		void	addNumber(int to_add);
		void	addNumberRange(unsigned int range, unsigned int modulo);
		void	printContent();
		int		shortestSpan();
		int		longestSpan();
		
	public :
	class SpanIsFullException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return ("Error : Span is full");
		};
	};
	class NotEnoughElementsException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return ("Error : Span has not enough elements");
		};
	};
};