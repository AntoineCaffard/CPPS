/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:14:46 by acaffard          #+#    #+#             */
/*   Updated: 2024/10/11 15:05:32 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>

class Fixed
{
	private :
		int					_value;
		static const int	_nb_bits;
	public :
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &copy);
		~Fixed();
		Fixed& operator=(const Fixed &copy);
	public :
		int		getRawBits(void)const;
		void	setRawBits(int const raw);
		int		toInt()const;
		float 	toFloat()const;
		static Fixed& min(Fixed &a, Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);
	public :
		bool operator<(const Fixed &src);
		bool operator>(const Fixed &src);
		bool operator<=(const Fixed &src);
		bool operator>=(const Fixed &src);
		bool operator==(const Fixed &src);
		bool operator!=(const Fixed &src);
		float operator+(const Fixed &src);
		float operator-(const Fixed &src);
		float operator*(const Fixed &src);
		float operator/(const Fixed &src);
		Fixed operator++();
		Fixed operator--();
		Fixed operator--(int);
		Fixed operator++(int);
};

std::ostream&	operator<<(std::ostream &o, Fixed const &fixed);