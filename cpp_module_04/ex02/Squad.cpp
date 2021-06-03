#include "Squad.hpp"

Squad::Squad() : _unit(nullptr), _unit_count(0)
{}

Squad::Squad(Squad const & other)
{
	if (other.getCount() != 0)
	{
		_unit = new ISpaceMarine* [other.getCount()];

		for (int i = 0; i < other.getCount(); ++i)
			_unit[i] = (other.getUnit(i))->clone();
		_unit_count = other.getCount();
	}
}

Squad::~Squad()
{
	vanish_squad();
}

void	Squad::vanish_squad()
{
	if (nullptr != _unit && _unit_count > 0) 
	{
		for (int i = 0; i < _unit_count; ++i)
		{
			if (nullptr != _unit[i])
				delete _unit[i];
			_unit[i] = nullptr;
		}
		delete [] _unit;
		_unit = nullptr;
	}
}

ISpaceMarine**	Squad::clone_squad() const
{
	ISpaceMarine**	temp;
	ISpaceMarine*	temp_unit;

	temp = nullptr;
	if (getCount() != 0)
	{
		temp = new ISpaceMarine* [_unit_count];
		for (int i = 0; i < _unit_count; ++i)
		{
			temp_unit = _unit[i];
			if (nullptr != temp_unit)
				temp[i] = temp_unit->clone();
			else
				temp[i] = nullptr;
		}
	}
	return temp;
}

bool	Squad::is_in_squad(ISpaceMarine* marine)
{
	if (marine != nullptr)
	{
		for (int i = 0; i < _unit_count; ++i)
		{
			if (_unit[i] == marine)
				return true;
		}
	}
	return false;
}

Squad & Squad::operator=(Squad const & right)
{
	ISpaceMarine**	temp;

	temp = nullptr;
	if (this != &right)
	{
		vanish_squad();
		_unit = right.clone_squad();
		_unit_count = right.getCount();
	}
	return *this;
}

int	Squad::push(ISpaceMarine* marine)
{
	ISpaceMarine**	temp;
	int				count = 0;

	if (marine != nullptr && !is_in_squad(marine))
	{
		temp = new ISpaceMarine* [_unit_count + 1];
		while (count < _unit_count)
		{
			temp[count] = _unit[count];
			count++;
		}
		temp[count] = marine;
		_unit_count += 1;
		delete [] _unit;
		_unit = temp;
	}
	return _unit_count;
}

int				Squad::getCount() const { return _unit_count; }
ISpaceMarine*	Squad::getUnit(int num) const
{
	if (num >= 0 && num < _unit_count)
		return _unit[num];
	else
		return nullptr;
}
