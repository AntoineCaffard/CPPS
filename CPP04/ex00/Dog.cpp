#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "\e[1;32mDog : Default Constructor Called\e[0m" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "\e[1;32mDog : Copy Constructor Called\e[0m" << std::endl;
	*this = copy;
}

Dog::~Dog()
{
	std::cout << "\e[1;31mDog : Destructor Called\e[0m" << std::endl;
}

Dog& Dog::operator=(const Dog &copy)
{
	(void) copy;
	return(*this);
}

void	Dog::makeSound() const
{
	std::cout << "Wooof Wooof Woooooof Awoooooo" << std::endl;
}

std::ostream& operator<<(std::ostream &o, Dog const &dog)
{
	std::cout << std::endl << "----------------" << std::endl;
	std::cout << "-----Dog-----" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "type = " << dog.getType() << std::endl;
	std::cout << "----------------" << std::endl << std::endl;
	return o;
}
