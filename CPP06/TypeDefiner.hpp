/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeDefiner.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:23:16 by acaffard          #+#    #+#             */
/*   Updated: 2025/02/20 09:36:40 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SPECIAL,
	IMPOSSIBLE
};

bool	isChar(std::string &value);
bool	isInt(std::string &value);
bool	isFloat(std::string &value);
bool	isDouble(std::string &value);
bool	isSpecial(std::string &value);
int		defineType(std::string &value);