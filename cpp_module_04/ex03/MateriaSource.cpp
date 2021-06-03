#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	_sources = new AMateria* [4];
	for (int i = 0; i < 4; ++i)
		_sources[i] = nullptr;
}

MateriaSource::MateriaSource(MateriaSource const & other)
{
	*this = other;
}

MateriaSource::~MateriaSource()
{
	clean_materia_slots();
}

MateriaSource &	MateriaSource::operator=(MateriaSource const & right)
{
	if (this != &right)
	{
		clean_materia_slots();
		_sources = right.clone_materia_slots();
	}
	return *this;
}

void	MateriaSource::clean_materia_slots()
{
	if (_sources != nullptr)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (_sources [i] != nullptr)
			{
				delete _sources[i];
			}
			_sources[i] = nullptr;
		}
		delete [] _sources;
		_sources= nullptr;
	}
}

AMateria**	MateriaSource::clone_materia_slots() const
{
	if (_sources!= nullptr)
	{
		AMateria**	result = new AMateria* [4];

		for (int i = 0; i < 4; ++i)
		{
			if (nullptr != _sources[i])
				result[i] = _sources[i]->clone();
			else
				result[i] = nullptr;
		}
		return result;
	}
	else
		return nullptr;
}

void	MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (nullptr == _sources[i])
		{
			if (nullptr != m)
			{
				_sources[i] = m->clone();
			}
			return ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_sources[i] != nullptr && _sources[i]->getType() == type)
			return _sources[i]->clone();
	}
	return nullptr;
}

std::string	MateriaSource::getStatus() const
{
	std::stringstream	ss;

	ss << "< materia source [";
	for (int i = 0; i < 4; ++i)
	{
		ss << "[";
		if (nullptr != _sources[i])
		{
			ss << _sources[i]->getType();
			ss << ":" << _sources[i]->getXP();
		}
		else
			ss << "None";
		ss << "]";
	}
	ss << "] >";
	return ss.str();
}

std::ostream & operator<<(std::ostream & os, IMateriaSource const & obj)
{
	os << ((MateriaSource const &)obj).getStatus();

	return os;
}
