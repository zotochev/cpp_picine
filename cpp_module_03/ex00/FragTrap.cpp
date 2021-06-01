#include "FragTrap.hpp"

std::string		FragTrap::get_health() const
{
	std::stringstream	temp;

	temp << BLU << "<" << "FR4G-TP: " << name_ << " "
		 << hit_points_ << "/"
		 << max_hit_points_ << "> " << RESET;
	return temp.str();
}

void	FragTrap::attack_1(std::string const & target)
{
	std::cout << YEL << "(vaulthunter dot exe 1. Target: " << target << ") " << RESET
			  << get_health()
			  << vaulthunter_dot_exe_list[0]
				<< std::endl;
}

void	FragTrap::attack_2(std::string const & target)
{
	std::cout << YEL << "(vaulthunter dot exe 2. Target: " << target << ") " << RESET
			  << get_health()
			  << vaulthunter_dot_exe_list[1]
				<< std::endl;
}

void	FragTrap::attack_3(std::string const & target)
{
	std::cout << YEL << "(vaulthunter dot exe 3. Target: " << target << ") " << RESET
			  << get_health()
			  << vaulthunter_dot_exe_list[2]
				<< std::endl;
}

void	FragTrap::attack_4(std::string const & target)
{
	std::cout << YEL << "(vaulthunter dot exe 4. Target: " << target << ") " << RESET
			  << get_health()
			  << vaulthunter_dot_exe_list[3]
				<< std::endl;
}

void	FragTrap::attack_5(std::string const & target)
{
	std::cout << YEL << "(vaulthunter dot exe 5. Target: " << target << ") " << RESET
			  << get_health()
			  << vaulthunter_dot_exe_list[4]
				<< std::endl;
}

void	FragTrap::attack_6(std::string const & target)
{
	std::cout << YEL << "(vaulthunter dot exe 6. Target: " << target << ") " << RESET
			  << get_health()
			  << vaulthunter_dot_exe_list[5]
				<< std::endl;
}

void	FragTrap::attacks_init()
{
	attacks[0] = &FragTrap::attack_1;
	attacks[1] = &FragTrap::attack_2;
	attacks[2] = &FragTrap::attack_3;
	attacks[3] = &FragTrap::attack_4;
	attacks[4] = &FragTrap::attack_5;
	attacks[5] = &FragTrap::attack_6;
}

FragTrap::FragTrap() :	hit_points_(100),
						max_hit_points_(100),
						energy_points_(100),
						level_(1),
						name_("No name"),
						melee_attack_damage_(30),
						ranged_attack_damage_(20),
						armor_damage_reduction_(5)
{
	std::cout	<< "(default constructor) " << get_health() << ": "
				<< creation_list[std::rand() % creation_list_len]
				<< std::endl;

	attacks_init();
}

FragTrap::FragTrap(std::string const & name) :	hit_points_(100),
												max_hit_points_(100),
												energy_points_(100),
												level_(1),
												name_(name),
												melee_attack_damage_(30),
												ranged_attack_damage_(20),
												armor_damage_reduction_(5)
{
	std::cout	<< "(name constructor) " << get_health() << ": "
				<< creation_list[std::rand() % creation_list_len]
				<< std::endl;

	attacks_init();
}

FragTrap::FragTrap(FragTrap const & other) :	hit_points_(other.hit_points_),
												max_hit_points_(other.max_hit_points_),
												energy_points_(other.energy_points_),
												level_(other.level_),
												name_(other.name_),
												melee_attack_damage_(other.melee_attack_damage_),
												ranged_attack_damage_(other.ranged_attack_damage_),
												armor_damage_reduction_(other.armor_damage_reduction_)
{
	std::cout	<< "(copy constructor) " << get_health() << ": "
				<< creation_list[std::rand() % creation_list_len]
				<< std::endl;

	attacks_init();
}

FragTrap &	FragTrap::operator = (FragTrap const & other)
{
	if (this != &other)
	{
		hit_points_ = other.hit_points_;
		max_hit_points_ = other.max_hit_points_;
		energy_points_ = other.energy_points_;
		level_ = other.level_;
		name_ = other.name_;
		melee_attack_damage_ = other.melee_attack_damage_;
		ranged_attack_damage_ = other.ranged_attack_damage_;
		armor_damage_reduction_ = other.armor_damage_reduction_;
	}
	std::cout	<< "(operator \"=\") used" << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << name_ << " destructed" << std::endl;
}

void	FragTrap::rangedAttack(const std::string &target)
{
	std::cout	<< get_health()
				<< "attacks " << target
				<< " at range, causing " << ranged_attack_damage_ << " points of damage"
				<< std::endl;
}

void	FragTrap::meleeAttack(std::string const & target)
{
	std::cout	<< get_health()
				<< "attacks " << target
				<< " at melee, causing " << melee_attack_damage_ << " points of damage"
				<< std::endl;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (amount > armor_damage_reduction_)
	{
		if (amount > armor_damage_reduction_ + hit_points_)
			hit_points_ = 0;
		else
			hit_points_ -= amount - armor_damage_reduction_;
	}

	std::cout	<< RED << "(taking " << amount << " points of damage) " << RESET
				<< get_health()
				<< take_damage_list[std::rand() % take_damage_list_len]
				<< std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (amount > max_hit_points_ - hit_points_)
		hit_points_ = max_hit_points_;
	else
		hit_points_ += amount;

	std::cout	<< GRN << "(" << amount << " points repaired) " << RESET
				<< get_health()
				<< be_repaired_list[std::rand() % be_repaired_list_len]
				<< std::endl;
}

void	FragTrap::vaulthunter_dot_exe(const std::string &target)
{
	if (energy_points_ < 25)
	{
		std::cout << YEL << "(vaulthunter dot exe) " << RESET << energy_points_ << " energy points is not enough"
				<< ". You need at least 25 energy points." << std::endl;
	}
	else
	{
		energy_points_ -= 25;

		(this->*attacks[rand() % 6])(target);
	}
}

unsigned int	FragTrap::creation_list_len = 6;

const char*	FragTrap::creation_list[] = {
	"Hey everybody! Check out my package!",
	"Let's get this party started!",
	"Glitching weirdness is a term of endearment, right?",
	"Recompiling my combat code!",
	"This time it'll be awesome, I promise!",
	"Look out everybody! Things are about to get awesome!"
};

unsigned int	FragTrap::take_damage_list_len = 6;

const char	*FragTrap::take_damage_list[] = {
	"Why do I even feel pain?!",
	"Why did they build me out of galvanized flesh?!",
	"Ow hohoho, that hurts! Yipes!",
	"My robotic flesh! AAHH!",
	"Woah! Oh! Jeez!",
	"If only my chassis... weren't made of recycled human body parts! Wahahaha!"
};

unsigned int	FragTrap::be_repaired_list_len = 6;

const char	*FragTrap::be_repaired_list[] = {
	"Health! Eww, what flavor is red?",
	"Health over here!",
	"Sweet life juice!",
	"I found health!",
	"Healsies!",
	"Get repaired!"
};

const char	*FragTrap::vaulthunter_dot_exe_list[] = {
	"Defragmenting!",
	"Recompiling my combat code!",
	"It's about to get magical!",
	"You can't just program this level of excitement!",
	"Glitchy weirdness is term of endearment, right?",
	"Push this button, flip this dongle, voila! Help me!"
};

