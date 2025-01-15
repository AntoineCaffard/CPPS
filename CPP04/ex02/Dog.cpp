#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
	std::cout << "\e[1;32mDog : Default Constructor Called\e[0m" << std::endl;
	_brain = new(std::nothrow) Brain;
}

Dog::Dog(const Dog &copy) : AAnimal(copy)
{
	std::cout << "\e[1;32mCat : Copy Constructor Called\e[0m" << std::endl;
	_brain = new(std::nothrow) Brain(*copy._brain);
}

Dog::~Dog()
{
	if (_brain)
		delete _brain;
	std::cout << "\e[1;31mDog : Destructor Called\e[0m" << std::endl;
}

Dog& Dog::operator=(const Dog &copy)
{
	if (this != &copy)
	{
		if (_brain)
			delete _brain;
		_brain = (copy._brain) ? new(std::nothrow) Brain(*copy._brain) : copy._brain;
	}
	return(*this);
}

void	Dog::makeSound() const
{
	std::cout << "Wooof Wooof Woooooof Awoooooo" << std::endl;
}

Brain* Dog::getBrain() const
{
	return this->_brain;
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
