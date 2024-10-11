/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:14:46 by acaffard          #+#    #+#             */
/*   Updated: 2024/10/10 14:41:54 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Fixed
{
	private :
		int					_value;
		static const int	_nb_bits;
	public :
		Fixed();
		Fixed(const Fixed &copy);
		~Fixed();
		Fixed& operator=(const Fixed &copy);
	public :
		int		getRawBits(void)const;
		void	setRawBits(int const raw);
};