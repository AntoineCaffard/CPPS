/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:14:46 by acaffard          #+#    #+#             */
/*   Updated: 2024/10/10 14:41:27 by acaffard         ###   ########.fr       */
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
};

std::ostream&	operator<<(std::ostream &o, Fixed const &fixed);