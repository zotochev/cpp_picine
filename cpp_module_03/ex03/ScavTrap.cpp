#include "ScavTrap.hpp"

std::string		ScavTrap::get_health() const
{
	std::stringstream	temp;

	temp << CYN << "<" << "SC4V-TP: " << name() << " "
		 << hit_points() << "/"
		 << max_hit_points() << "> " << RESET;
	return temp.str();
}

void	ScavTrap::challenge_1(std::string const & target)
{
	std::cout	<< YEL << "(challenge newcomer 1. Target: " << target << ") " << RESET
			 	<< get_health()
			 	<< challengeNewcomer_list[0]
				<< std::endl;
}

void	ScavTrap::challenge_2(std::string const & target)
{
	std::cout	<< YEL << "(challenge newcomer 2. Target: " << target << ") " << RESET
			 	<< get_health()
			 	<< challengeNewcomer_list[1]
				<< std::endl;
}

void	ScavTrap::challenge_3(std::string const & target)
{
	std::cout	<< YEL << "(challenge newcomer 3. Target: " << target << ") " << RESET
			 	<< get_health()
			 	<< challengeNewcomer_list[2]
				<< std::endl;
}

void	ScavTrap::challenge_4(std::string const & target)
{
	std::cout	<< YEL << "(challenge newcomer 4. Target: " << target << ") " << RESET
			 	<< get_health()
			 	<< challengeNewcomer_list[3]
				<< std::endl;
}

void	ScavTrap::challenge_5(std::string const & target)
{
	std::cout	<< YEL << "(challenge newcomer 5. Target: " << target << ") " << RESET
			 	<< get_health()
			 	<< challengeNewcomer_list[4]
				<< std::endl;
}

void	ScavTrap::challenge_6(std::string const & target)
{
	std::cout	<< YEL << "(challenge newcomer 6. Target: " << target << ") " << RESET
			 	<< get_health()
			 	<< challengeNewcomer_list[5]
				<< std::endl;
}

void	ScavTrap::challenges_init()
{
	challenges[0] = &ScavTrap::challenge_1;
	challenges[1] = &ScavTrap::challenge_2;
	challenges[2] = &ScavTrap::challenge_3;
	challenges[3] = &ScavTrap::challenge_4;
	challenges[4] = &ScavTrap::challenge_5;
	challenges[5] = &ScavTrap::challenge_6;
}

ScavTrap::ScavTrap() :	ClapTrap(100, 100, 50, 50, 1, "No name", 20, 15, 3)
{
	challenges_init();

	std::cout	<< "(default constructor) " << get_health() << ": "
				<< creation_list[std::rand() % creation_list_len]
				<< std::endl;
}

ScavTrap::ScavTrap(std::string const & name) :	ClapTrap(100, 100, 50, 50, 1, name, 20, 15, 3)
{
	challenges_init();

	std::cout	<< "(name constructor) " << get_health() << ": "
				<< creation_list[std::rand() % creation_list_len]
				<< std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & other) :	ClapTrap(
												other.hit_points(),
												other.max_hit_points(),
												other.energy_points(),
												other.max_energy_points(),
												other.level(),
												other.name(),
												other.melee_attack_damage(),
												other.ranged_attack_damage(),
												other.armor_damage_reduction())
{
	challenges_init();

	std::cout	<< "(copy constructor) " << get_health() << ": "
				<< creation_list[std::rand() % creation_list_len]
				<< std::endl;
}

ScavTrap &	ScavTrap::operator = (ScavTrap const & other)
{
	if (this != &other)
	{
		set_hit_points(other.hit_points());
		set_max_hit_points(other.max_hit_points());
		set_energy_points(other.energy_points());
		set_max_energy_points(other.max_energy_points());
		set_level(other.level());
		set_name(other.name());
		set_melee_attack_damage(other.melee_attack_damage());
		set_ranged_attack_damage(other.ranged_attack_damage());
		set_armor_damage_reduction(other.armor_damage_reduction());
	}
	std::cout	<< "(operator \"=\") used" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "(ScavTrap destructer) " << name() << " destructed" << std::endl;
}

void	ScavTrap::rangedAttack(const std::string &target)
{
	std::cout	<< MAG << "(ranged attack. Damage: " << ranged_attack_damage() << ") " << RESET << get_health()
				<< "attacks " << target
				<< " at range, causing " << ranged_attack_damage() << " points of damage"
				<< std::endl;
}

void	ScavTrap::meleeAttack(std::string const & target)
{
	std::cout	<< MAG << "(melle attack. Damage: " << melee_attack_damage() << ") " << RESET << get_health()
				<< "attacks " << target
				<< " at melee, causing " << melee_attack_damage() << " points of damage"
				<< std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (amount > armor_damage_reduction())
	{
		if (amount - armor_damage_reduction() > hit_points())
			set_hit_points(0);
		else
			set_hit_points(hit_points() - amount - armor_damage_reduction());
	}

	std::cout	<< RED << "(taking " << amount << " points of damage) " << RESET
				<< get_health()
				<< take_damage_list[std::rand() % take_damage_list_len]
				<< std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (amount + hit_points() > max_hit_points())
		set_hit_points(max_hit_points());
	else
		set_hit_points(hit_points() + amount);

	std::cout	<< GRN << "(" << amount << " points repaired) " << RESET
				<< get_health()
				<< be_repaired_list[std::rand() % be_repaired_list_len]
				<< std::endl;
}

void	ScavTrap::challengeNewcomer(const std::string &target)
{
	if (energy_points() < 25)
	{
		std::cout << YEL << "(challenge newcomer) " << RESET << energy_points() << " energy points is not enough"
				<< ". You need at least 25 energy points." << std::endl;
	}
	else
	{
		set_energy_points(energy_points() - 25);

		(this->*challenges[rand() % 6])(target);
	}
}

unsigned int	ScavTrap::creation_list_len = 6;

const char*	ScavTrap::creation_list[] = {
	"I'm a sexy dinosaur! Rawr!",
	"Just point me in the right direction!",
	"Here I come to save the day!",
	"Ooh yeah, watch me! Watch me go!",
	"Who's a badass robot? This guy!",
	"I am so impressed with myself!"
};

unsigned int	ScavTrap::take_damage_list_len = 6;

const char	*ScavTrap::take_damage_list[] = {
	"Oh my God, I'm leaking!",
	"I think I'm leaking! Ahhhh, I'm leaking!",
	"There's oil everywhere!",
	"I can see through time...",
	"My servos... are seizing...",
	"I can see... the code"
};

unsigned int	ScavTrap::be_repaired_list_len = 6;

const char	*ScavTrap::be_repaired_list[] = {
	"Good as new, I think. Am I leaking?",
	"Poof, all better, doll!",
	"Sugar, this won't hurt a bit!",
	"Take these, gorgeous, you'll feel better!",
	"I feel... complete!.. That's weird.",
	"At least I still have my teeth!"
};

unsigned int	ScavTrap::challengeNewcomer_list_len = 6;

const char	*ScavTrap::challengeNewcomer_list[] = {
	"You versus me! Me versus you! Either way!",
	"Dance battle! Or, you know... regular battle.",
	"Man versus machine! Very tiny streamlined machine!",
	"Please open the box.",
	"Scary Badass dude, over there! Take him!",
	"That guy looks an awful lot like a Badass! Make him dead!"
};

