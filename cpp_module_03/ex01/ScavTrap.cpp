#include "ScavTrap.hpp"

std::string		ScavTrap::get_health() const
{
	std::stringstream	temp;

	temp	<< CYN << "<" << "SC4V-TP: " << name_ << " "
			<< hit_points_ << "/"
			<< max_hit_points_ << "> " << RESET;
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

ScavTrap::ScavTrap() :	hit_points_(100),
						max_hit_points_(100),
						energy_points_(50),
						level_(1),
						name_("No name"),
						melee_attack_damage_(20),
						ranged_attack_damage_(15),
						armor_damage_reduction_(3)
{
	challenges_init();

	std::cout	<< "(default constructor) " << get_health() << ": "
				<< creation_list[std::rand() % creation_list_len]
				<< std::endl;
}

ScavTrap::ScavTrap(std::string const & name) :	hit_points_(100),
												max_hit_points_(100),
												energy_points_(100),
												level_(1),
												name_(name),
												melee_attack_damage_(30),
												ranged_attack_damage_(20),
												armor_damage_reduction_(5)
{
	challenges_init();

	std::cout	<< "(name constructor) " << get_health() << ": "
				<< creation_list[std::rand() % creation_list_len]
				<< std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & other) :	hit_points_(other.hit_points_),
												max_hit_points_(other.max_hit_points_),
												energy_points_(other.energy_points_),
												level_(other.level_),
												name_(other.name_),
												melee_attack_damage_(other.melee_attack_damage_),
												ranged_attack_damage_(other.ranged_attack_damage_),
												armor_damage_reduction_(other.armor_damage_reduction_)
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

ScavTrap::~ScavTrap()
{
	std::cout << name_ << " destructed" << std::endl;
}

void	ScavTrap::rangedAttack(const std::string &target)
{
	std::cout	<< MAG << "(ranged attack. Damage: " << ranged_attack_damage_ << ") " << RESET << get_health()
				<< "attacks " << target
				<< " at range, causing " << ranged_attack_damage_ << " points of damage"
				<< std::endl;
}

void	ScavTrap::meleeAttack(std::string const & target)
{
	std::cout	<< MAG << "(melle attack. Damage: " << melee_attack_damage_ << ") " << RESET << get_health()
				<< "attacks " << target
				<< " at melee, causing " << melee_attack_damage_ << " points of damage"
				<< std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
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

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (amount > max_hit_points_ - hit_points_)
		hit_points_ = max_hit_points_;
	else
		hit_points_ += amount;

	std::cout	<< GRN << "(" << amount << " points repaired) " << RESET
				<< this->get_health()
				<< be_repaired_list[std::rand() % be_repaired_list_len]
				<< std::endl;
}

void	ScavTrap::challengeNewcomer(const std::string &target)
{
	if (energy_points_ < 25)
	{
		std::cout << YEL << "(challenge newcomer) " << RESET << energy_points_ << " energy points is not enough"
				<< ". You need at least 25 energy points." << std::endl;
	}
	else
	{
		energy_points_ -= 25;

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

