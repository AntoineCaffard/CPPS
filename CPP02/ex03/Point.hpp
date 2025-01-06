/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:56:44 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/06 13:26:42 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point
{
	private :
		const Fixed _x;
		const Fixed _y;
	public :
		Point();
		Point(Fixed x, Fixed y);
		~Point();
		Point(const Point &copy);
		Point& operator=(const Point &copy);
	public :
		Fixed getX() const;
		Fixed getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);