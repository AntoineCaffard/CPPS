/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by acaffard          #+#    #+#             */
/*   Updated: 2024/09/02 14:27:40 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <iostream>
# include <string>

typedef enum e_input_type
{
	ADD, SEARCH, EXIT
} t_input_type;

std::string inputValidPhoneNumber();
std::string inputString(std::string type);
bool		checkValue(std::string value);
int			skipSpaces(std::string str);

#endif
