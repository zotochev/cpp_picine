#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include <iostream>
#include <sstream>

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria**	_sources;
	
	public:
		MateriaSource();
		MateriaSource(MateriaSource const & other);
		~MateriaSource();

		MateriaSource & operator=(MateriaSource const & right);

		void		learnMateria(AMateria* m);
		AMateria*	createMateria(std::string const & type);

		void		clean_materia_slots();
		AMateria**	clone_materia_slots() const;

		std::string	getStatus() const;
};

std::ostream & operator<<(std::ostream & os, IMateriaSource const & obj);

#endif
