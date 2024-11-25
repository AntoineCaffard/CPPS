/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:28:43 by acaffard          #+#    #+#             */
/*   Updated: 2024/11/05 09:15:47 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_nb_bits = 8;

Fixed::Fixed()
{
	std::cout << "Default Constructor Called" << std::endl;
	_value = 0;
	return ;
}

Fixed::Fixed(const int value)
{
}

Fixed::Fixed(const float value)
{
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy Constructor Called" << std::endl;
	*this = copy;
}

Fixed::~Fixed()
{
	std::cout << "Destructor Called" << std::endl;
	return ;
}

Fixed& Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy Assingnment Constructor Called" << std::endl;
	_value = copy._value;
	return (*this);
}

int	Fixed::getRawBits()const
{
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

int	Fixed::toInt()const
{
}

float	Fixed::toFloat()const
{
}

std::ostream&	operator<<(std::ostream &o, Fixed const &fixed)
{
	return o;
}