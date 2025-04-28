/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:02:20 by acaffard          #+#    #+#             */
/*   Updated: 2025/04/28 17:16:55 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "typecheck.hpp"
#include "prints.hpp"

class ScalarConverter
{
	public :
		ScalarConverter();
		virtual ~ScalarConverter();
		static void convert(std::string value);
	private :
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter *operator=(const ScalarConverter &copy);
};

class BadArgumentNumber : public std::exception
{
	virtual const char *what() const throw()
	{
		return ("Error : You need to have one argument");
	};
};	

void convert_char(std::string value);
void convert_int(std::string value);
void convert_float(std::string value);
void convert_double(std::string value);