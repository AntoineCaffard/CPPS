/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:10:41 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/06 14:09:36 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Fixed calculateArea ( Point const a, Point const b, Point const c)
{
	Fixed sum1 = a.getX() * (b.getY() - c.getY());
	Fixed sum2 = b.getX() * (c.getY() - a.getY());
	Fixed sum3 = c.getX() * (a.getY() - b.getY());
	Fixed sum = sum1 + sum2 + sum3;
	sum = (sum < 0) ? sum * -1 : sum;
	return (sum / 2);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed big_area = calculateArea(a , b, c);
	Fixed small_area1 = calculateArea(a, b, point);
	Fixed small_area2 = calculateArea(a, c, point);
	Fixed small_area3 = calculateArea(c, b, point);
	if (small_area1 == 0 || small_area2 == 0 || small_area3 == 0 || big_area == 0)
		return false;
	if (big_area == small_area1 + small_area2 + small_area3)
		return true;
	return false;
}