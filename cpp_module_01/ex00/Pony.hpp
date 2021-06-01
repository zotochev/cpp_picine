#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Pony
{
	public:
		Pony(const std::string& name = "Unknown",
			 const std::string& fur_color = "Not specified",
			 const std::string& battle_scream = "Neigh!");
		~Pony();

		void	say();

	private:
		std::string name;
		std::string	fur_color;
		std::string	battle_scream;
};

#endif