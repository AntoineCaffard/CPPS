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
		std::cout << "\e[1;33mAnimals Construction\e[0m" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << "\e[1;33mAnimals Types\e[0m" << std::endl;
		std::cout << "j : " << j->getType() << " " << std::endl;
		std::cout << "i : " << i->getType() << " " << std::endl;
		std::cout << "meta : " << meta->getType() << " " << std::endl;
		std::cout << "\e[1;33mAnimals Sounds\e[0m" << std::endl;
		std::cout << "i : ";
		i->makeSound(); //will output the cat sound!
		std::cout << "j : ";
		j->makeSound();
		std::cout << "meta : ";
		meta->makeSound();
		std::cout << "\e[1;33mAnimals Destruction\e[0m" << std::endl;
		delete meta;
		delete j;
		delete i;
	}
	{
		std::cout << "\e[1;33mWrongAnimals Construction\e[0m" << std::endl;
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		std::cout << "\e[1;33mWrongAnimals Types\e[0m" << std::endl;
		std::cout << "i : " << i->getType() << " " << std::endl;
		std::cout << "meta : " << meta->getType() << " " << std::endl;
		std::cout << "\e[1;33mWrongAnimals Sounds\e[0m" << std::endl;
		std::cout << "i : ";
		i->makeSound(); //will output the cat sound!
		std::cout << "meta : ";
		meta->makeSound();
		std::cout << "\e[1;33mWrongAnimals Destruction\e[0m" << std::endl;
		delete meta;
		delete i;
	}
	return 0;
}
