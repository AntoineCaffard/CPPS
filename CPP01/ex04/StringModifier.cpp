/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringModifier.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:15:50 by acaffard          #+#    #+#             */
/*   Updated: 2024/11/05 09:01:12 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StringModifier.hpp"

StringModifier::StringModifier(std::string base_string, std::string value_to_modify, std::string new_value) :
	_base_string(base_string), _to_find(value_to_modify), _new_value(new_value)
{
	_modified_string = "";
}

StringModifier::~StringModifier()
{

}

int	StringModifier::modifyOnce()
{
	size_t modify_index = _base_string.find(_to_find);
	if (modify_index == std::string::npos)
	{
		_modified_string.append(_base_string);
		_base_string.clear();
		return (-1);
	}
	_modified_string.append(_base_string, 0, modify_index);
	_modified_string.append(_new_value);
	_base_string = _base_string.erase(0, modify_index + _to_find.length());
	return (0);
}
void	StringModifier::modify()
{
	while(this->modifyOnce() == 0);	
}

std::string StringModifier::getModifiedString()
{
	return _modified_string;
}
