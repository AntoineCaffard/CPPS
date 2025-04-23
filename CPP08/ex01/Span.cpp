/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:22:15 by acaffard          #+#    #+#             */
/*   Updated: 2025/03/25 12:52:40 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


Span::Span(unsigned int N)
{
	this->_N = N;
}

Span::Span(const Span &copy)
{
	*this = copy;
}

Span::~Span()
{}

Span&	Span::operator=(const Span &copy)
{
	if (this != &copy)
	{
		this->_N = copy._N;
		this->_content = copy._content;
	}
	return *this;
}

void Span::addNumber(int to_add)
{
	if (_content.size() + 1 > _N)
		throw SpanIsFullException();
	_content.push_back(to_add);
}

void	Span::addNumberRange(unsigned int range, unsigned int modulo)
{
	srand(time(NULL));
	for (unsigned int i = 0; i < range; ++i)
	{
		try
		{
			addNumber(rand() % modulo);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			return ;
		}
	}
}


void	print_int(int value)
{
	std::cout << value << std::endl;
};

int	Span::shortestSpan()
{
	if (_content.size() < 2)
		throw NotEnoughElementsException();
	std::deque<int>	tmp(_content);
	std::deque<int>	result;
	std::sort(tmp.begin(), tmp.end());
	for(std::deque<int>::iterator it = tmp.begin(); it != tmp.end() - 1; ++it)
		result.push_back(abs(*it - *(it + 1)));
	std::sort(result.begin(), result.end());
	return (result[0]);
}

int Span::longestSpan()
{
	if (_content.size() < 2)
		throw NotEnoughElementsException();
	std::deque<int> sorted(_content);
	std::sort(sorted.begin(), sorted.end());
	return (sorted[sorted.size()-1] - sorted[0]);
}

void Span::printContent()
{
	std::for_each(_content.begin(), _content.end(), print_int);
}

