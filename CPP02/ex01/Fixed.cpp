/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:28:43 by acaffard          #+#    #+#             */
/*   Updated: 2024/10/10 14:44:27 by acaffard         ###   ########.fr       */
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
	std::cout << "Int Constructor Called" << std::endl;
	_value = value << _nb_bits;
	return ;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float Constructor Called" << std::endl;
	_value = roundf((value * (1 << _nb_bits)));
	return ;
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
	return (this->_value >> this->_nb_bits);
}

float	Fixed::toFloat()const
{
	return ((float)this->_value / (float)(1 << this->_nb_bits));
}

std::ostream&	operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return o;
}