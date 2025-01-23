/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:21:44 by acaffard          #+#    #+#             */
/*   Updated: 2025/01/23 10:55:38 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		_known_materias[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	for (int i = 0; i < 4; ++i)
		_known_materias[i] = nullptr;
	*this = copy;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (_known_materias[i])
				delete _known_materias[i];
			if (copy._known_materias[i])
				_known_materias[i] = copy._known_materias[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		if (_known_materias[i] != nullptr)
			delete _known_materias[i];
	}
}

void MateriaSource::learnMateria(AMateria *materia)
{
	if (!materia)
		return;
	for (int i = 0; i < 4; ++i)
	{
		if (!_known_materias[i])
		{
			_known_materias[i] = materia;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_known_materias[i] != nullptr && type == _known_materias[i]->getType())
			return _known_materias[i]->clone();
	}
	return nullptr;
}