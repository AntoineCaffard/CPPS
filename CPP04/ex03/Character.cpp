/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:46:50 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/22 13:13:46 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(const std::string &name) : _name(name), _unequiped_index(0)
{
	for (int i = 0; i < 4; ++i)
		_materias[i] = nullptr;
	for (int i = 0; i < 1024; ++i)
		_unequiped[i] = nullptr;
}

Character::Character(const Character &copy)
{
	for (int i = 0; i < 4; ++i)
		_materias[i] = nullptr;
	for (int i = 0; i < 1024; ++i)
		_unequiped[i] = nullptr;
	*this = copy;
}

Character& Character::operator=(const Character &copy)
{
	this->_name = copy._name;
	_unequiped_index = copy._unequiped_index;
	for (int i = 0; i < 4; ++i)
	{
		if (this->_materias[i] != nullptr)
				delete this->_materias[i];
		if(copy._materias[i])
			this->_materias[i] = copy._materias[i]->clone();
	}
	for (int i = 0; i < _unequiped_index; ++i)
	{
		if (this->_unequiped[i] != nullptr)
				delete this->_unequiped[i];
		if(copy._unequiped[i])
			this->_unequiped[i] = copy._unequiped[i]->clone();
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
	{
		if(_materias[i] != nullptr)
			delete _materias[i];
	}
	for (int i = 0; i < _unequiped_index; ++i)
	{
		if(_unequiped[i] != nullptr)
			delete _unequiped[i];
	}
}

std::string const &Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; ++i)
	{
		if (_materias[i] == nullptr)
		{
			_materias[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if(idx < 0 || idx > 4 || _materias[idx] == nullptr)
		return;
	_unequiped[_unequiped_index] = _materias[idx];
	_unequiped_index++;
	_materias[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
	if(idx < 0 || idx > 4 || _materias[idx] == nullptr)
		return;
	_materias[idx]->use(target);
}
