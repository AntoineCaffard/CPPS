/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringModifier.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:58:44 by elvondir          #+#    #+#             */
/*   Updated: 2024/10/07 19:15:55 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <iostream>

class StringModifier
{
	private :
		std::string	_base_string;
		std::string	_modified_string;
		std::string	_to_find;
		std::string	_new_value;
		int		modifyOnce();
	public :
		StringModifier(std::string base_string, std::string value_to_modify, std::string new_value);
		~StringModifier();
		void		modify();
		std::string	getModifiedString();
};
