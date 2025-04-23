/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typecheck.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:13:59 by acaffard          #+#    #+#             */
/*   Updated: 2025/03/25 15:28:27 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <limits>

bool	is_zero(std::string value);
bool	is_char(std::string value);
bool	is_int(std::string value);
bool	is_float(std::string value);
bool	is_double(std::string value);
bool	is_special(std::string value);