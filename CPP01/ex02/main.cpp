/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:27:20 by acaffard          #+#    #+#             */
/*   Updated: 2024/09/26 15:37:24 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string my_string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &my_string;
	std::string stringREF = my_string;

	std::cout << "------ADRESSES------" << std::endl;
	std::cout << "my_string : " << &my_string << std::endl;
	std::cout << "stringPTR : " << stringPTR << std::endl;
	std::cout << "stringREF : " << &stringREF << std::endl;
	std::cout << std::endl << "------CONTENT------" << std::endl;
	std::cout << "my_string : " << my_string << std::endl;
	std::cout << "stringPTR : " << *stringPTR << std::endl;
	std::cout << "stringREF : " << stringREF << std::endl;
	return (0);
}