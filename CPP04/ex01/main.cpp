/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:26:25 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/14 12:26:25 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
	{
		std::cout << "\e[1;35mDEEP COPY TESTS\e[0m" << std::endl;
		std::cout << "\e[1;33mAnimals Construction\e[0m" << std::endl;
		Dog	*i = new Dog();
		i->getBrain()->setIdea(30, "Manger de la patee");
		Dog *j = new Dog(*i);
		std::cout << "\e[1;33mCats Ideas\e[0m" << std::endl;
		std::cout << "j : " << j->getBrain()->getIdea(30) << " " << std::endl;
		std::cout << "i : " << i->getBrain()->getIdea(30) << " " << std::endl;
		std::cout << "\e[1;33mi Destruction\e[0m" << std::endl;
		delete i;
		std::cout << "\e[1;33mj Ideas\e[0m" << std::endl;
		std::cout << "j : " << j->getBrain()->getIdea(30) << " " << std::endl;
		std::cout << "\e[1;33mj Destruction\e[0m" << std::endl;
		delete j;
	}
	{
		Animal* tab[10];
		std::cout << "\e[1;35mARRAY TEST\e[0m" << std::endl;
		std::cout << "\e[1;33mAnimals Construction\e[0m" << std::endl;
		for (int i = 0; i < 10; i++)
		{
			std::cout << "\e[1;35m--------------------------------------------------------\e[0m" << std::endl;
			tab[i] = (i % 2 == 0) ? (Animal *)(new(std::nothrow) Cat()) : (Animal *)(new(std::nothrow) Dog());
			if (!tab[i])
			{
				for (int j = 0; j < i; ++i)
				{
					delete tab[j];
				}
				return (0);
			}
			std::cout << "\e[1;35m--------------------------------------------------------\e[0m" << std::endl;
		}
		for (int i = 0; i < 10; i++)
		{
			std::cout << "\e[1;35m--------------------------------------------------------\e[0m" << std::endl;
			delete tab[i];
			std::cout << "\e[1;35m--------------------------------------------------------\e[0m" << std::endl;
		}
		return 0;
	}
}
