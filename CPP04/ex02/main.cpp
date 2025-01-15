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
#include "AAnimal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
	AAnimal *testCat = new Cat();
	AAnimal *testDog = new Dog();
	// AAnimal *testAnimal = new AAnimal();
	testDog->makeSound();
	testCat->makeSound();
	delete testCat;
	delete testDog;
}
