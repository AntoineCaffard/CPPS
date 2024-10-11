/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:28:43 by acaffard          #+#    #+#             */
/*   Updated: 2024/10/11 15:08:19 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_nb_bits = 8;

Fixed::Fixed()
{
	_value = 0;
	return ;
}

Fixed::Fixed(const int value)
{
	_value = value << _nb_bits;
	return ;
}

Fixed::Fixed(const float value)
{
	_value = roundf((value * (1 << _nb_bits)));
	return ;
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::~Fixed()
{
	return ;
}

Fixed& Fixed::operator=(const Fixed &copy)
{
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

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return (a.toFloat() < b.toFloat() ? a : b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return (a.toFloat() > b.toFloat() ? a : b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a.toFloat() < b.toFloat() ? a : b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a.toFloat() > b.toFloat() ? a : b);
}

bool Fixed::operator<(const Fixed &src)
{
	return (this->toFloat() < src.toFloat());
}

bool Fixed::operator>(const Fixed &src)
{
	return (this->toFloat() > src.toFloat());
}

bool Fixed::operator<=(const Fixed &src)
{
	return (this->toFloat() <= src.toFloat());
}

bool Fixed::operator>=(const Fixed &src)
{
	return (this->toFloat() >= src.toFloat());
}

bool Fixed::operator==(const Fixed &src)
{
	return (this->toFloat() == src.toFloat());
}

bool Fixed::operator!=(const Fixed &src)
{
	return !(this->toFloat() == src.toFloat());
}

float Fixed::operator+(const Fixed &src)
{
	return this->toFloat() + src.toFloat();
}

float Fixed::operator-(const Fixed &src)
{
	return this->toFloat() - src.toFloat();
}

float Fixed::operator*(const Fixed &src)
{
	return this->toFloat() * src.toFloat();
}

float Fixed::operator/(const Fixed &src)
{
	return this->toFloat() / src.toFloat();
}

Fixed Fixed::operator++()
{
	++this->_value;
	return *this;
}

Fixed Fixed::operator--()
{
	--this->_value;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed	tmp = *this;
	++this->_value;
	return tmp;
}

Fixed Fixed::operator--(int)
{
	Fixed	tmp = *this;
	--this->_value;
	return tmp;
}

std::ostream&	operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return o;
}