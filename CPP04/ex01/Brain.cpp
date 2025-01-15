/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:50:49 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/15 10:55:04 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "\e[1;34mBrain : Default Constructor Called\e[0m" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "";
}

Brain::Brain(const Brain& copy)
{
	std::cout << "\e[1;34mBrain : Copy Constructor Called\e[0m" << std::endl;
	*this = copy;
}

Brain::~Brain()
{
	std::cout << "\e[1;34mBrain : Destructor Called\e[0m" << std::endl;
}

Brain& Brain::operator=(const Brain& copy)
{
	if (this != &copy)
	{
		for(unsigned int i = 0; i < 100; i++)
			this->_ideas[i] = copy.getIdea(i);
	}
	return *this;
}

const std::string Brain::getIdea(unsigned int index) const
{
	if (index < 100)
		return _ideas[index];
	return "";
}

void	Brain::setIdea(unsigned int index ,const std::string &idea)
{
	if (index < 100)
		_ideas[index] = idea;
}

