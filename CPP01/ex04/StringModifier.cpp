/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringModifier.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:15:50 by acaffard          #+#    #+#             */
/*   Updated: 2024/10/07 19:16:26 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StringModifier.hpp"

StringModifier::StringModifier(std::string base_string, std::string value_to_modify, std::string new_value) :
	_base_string(base_string), _to_find(value_to_modify), _new_value(new_value)
{
	_modified_string = "";
	return ;
}

StringModifier::~StringModifier()
{
	return ;
}

int	StringModifier::modifyOnce()
{
	size_t	modify_index;
	modify_index = _base_string.find(_to_find);
	if (modify_index == std::string::npos)
	{
		_modified_string.append(_base_string);
		return (-1);
	}
	_modified_string.append(_base_string.substr(0, modify_index));
	_modified_string.append(_new_value);
	_base_string = _base_string.substr(modify_index + _to_find.length());
	return (0);
}
void	StringModifier::modify()
{
	int	test = 0;
	while(test == 0)
		test = this->modifyOnce();
}

std::string StringModifier::getModifiedString()
{
	return _modified_string;
}
