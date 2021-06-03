#include <sstream>

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(std::string const & name) : _name(name) 
{
	_materia_slots = new AMateria* [4];

	for (int i = 0; i < 4; ++i)
		_materia_slots[i] = nullptr;
}

Character::Character() 
	: _materia_slots(nullptr)
	, _name("")
{}

Character::Character(Character const & other)
	: _materia_slots(nullptr)
	, _name(other.getName())
{
	*this = other;
}

Character::~Character()
{
	clean_materia_slots();
}

void	Character::clean_materia_slots()
{
	if (_materia_slots != nullptr)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (_materia_slots[i] != nullptr)
			{
				delete _materia_slots[i];
			}
			_materia_slots[i] = nullptr;
		}
		delete [] _materia_slots;
		_materia_slots = nullptr;
	}
}

AMateria**	Character::clone_materia_slots() const
{
	if (_materia_slots != nullptr)
	{
		AMateria**	result = new AMateria* [4];

		for (int i = 0; i < 4; ++i)
		{
			if (nullptr != _materia_slots[i])
				result[i] = _materia_slots[i]->clone();
			else
				result[i] = nullptr;
		}
		return result;
	}
	else
		return nullptr;
}

int	Character::materia_available_count() const
{
	int count = 0;

	for (int i = 0; i < 4; ++i)
	{
		if (nullptr == _materia_slots[i])
			count++;
	}
	return count;
}

Character & Character::operator=(Character const & right)
{
	if (this != &right)
	{
		clean_materia_slots();
		_materia_slots = right.clone_materia_slots();
		_name = right.getName();
	}
	return *this;
}

std::string const &	Character::getName() const
{
	return _name;
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_materia_slots[i] == nullptr)
		{
			_materia_slots[i] = m->clone();
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	_materia_slots[idx] = nullptr;
}

void	Character::use(int idx, ICharacter & target)
{
	if (nullptr != _materia_slots[idx])
	{
		_materia_slots[idx]->use(target);
	}
}

std::string	Character::getStatus() const
{
	std::stringstream	ss;

	ss	<< "< " << _name << " [";
	for (int i = 0; i < 4; ++i)
	{
		if (nullptr != _materia_slots[i])
		{
			ss	<< "["
				<< _materia_slots[i]->getType()
				<< ":" << _materia_slots[i]->getXP()
				<< "]";
		}
		else
			ss	<< "[None]";
	}
	ss	<< "] >";

	return ss.str();
}

std::ostream &	operator<<(std::ostream & os, ICharacter const & obj)
{
	os << ((Character const &)obj).getStatus();

	return os;
}
