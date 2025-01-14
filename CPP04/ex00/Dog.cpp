#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog : Default Constructor Called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog : Copy Constructor Called" << std::endl;
	*this = copy;
}

Dog::~Dog()
{
	std::cout << "Dog : Destructor Called" << std::endl;
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
