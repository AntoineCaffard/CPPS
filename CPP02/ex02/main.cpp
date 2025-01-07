/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:56:41 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/07 08:05:43 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
Fixed  c(3);
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
a = b;
std::cout << a + c << std::endl;
std::cout << c - a << std::endl;
std::cout << c * a << std::endl;
std::cout << c / a << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
std::cout << Fixed::min( a, b ) << std::endl;
}
