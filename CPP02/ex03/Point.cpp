/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:02:25 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/06 13:28:08 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{}

Point::Point(Fixed x, Fixed y) : _x(x), _y(y)
{}

Point::~Point()
{}

Point::Point(const Point &copy)
{
	*this = copy;
}

Point& Point::operator=(const Point &copy)
{
	const_cast<Fixed&>(_x) = copy._x;
	const_cast<Fixed&>(_y) = copy._y;
	return (*this);
}

Fixed Point::getX() const
{
	return _x;
}

Fixed Point::getY() const
{
	return _y;
}