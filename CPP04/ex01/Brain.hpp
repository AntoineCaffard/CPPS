/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:18:05 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/15 10:55:08 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Brain
{
	private :
		std::string	_ideas[100];
	public :
		Brain();
		Brain(const Brain &copy);
		virtual ~Brain();
		Brain &operator=(const Brain &copy);
		
		const std::string	getIdea(unsigned int index) const;
		void				setIdea(unsigned int index , const std::string &idea);
};