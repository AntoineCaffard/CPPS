/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:29:54 by acaffard          #+#    #+#             */
/*   Updated: 2024/09/26 14:40:52 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string	_name;
public:
	Zombie();
	~Zombie();
	void announce(void);
	void setName(std::string name);
};

Zombie* zombieHorde( int N, std::string name );
