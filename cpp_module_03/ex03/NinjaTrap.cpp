#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap() : ClapTrap(60, 60, 120, 120, 1, "No name", 60, 5, 0)
{
	std::cout	<< "(default Ninja constructor) "
				<< get_health() << ": "
				<< creation_list[std::rand() % creation_list_len]
				<< std::endl; 
}

NinjaTrap::NinjaTrap(std::string const & name) : ClapTrap(60, 60, 120, 120, 1, name, 60, 5, 0)
{
	std::cout	<< "(name Ninja constructor) "
				<< get_health() << ": "
				<< creation_list[std::rand() % creation_list_len]
				<< std::endl; 
}

NinjaTrap::NinjaTrap(NinjaTrap const & other) : ClapTrap(
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
	std::cout	<< "(copy Ninja constructor) "
				<< get_health() << ": "
				<< creation_list[std::rand() % creation_list_len]
				<< std::endl;
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const & other)
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
	}
	std::cout << "(operator \"=\" used in NinjaTrap)" << std::endl;
	return *this;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "(NinjaTrap destructer) " << name() << " destructed" << std::endl;
}

std::string		NinjaTrap::get_health() const
{
	std::stringstream	temp;

	temp << BLU << "<" << "NINJA-TP: " << name() << " "
		 << hit_points() << "/"
		 << max_hit_points() << "> " << RESET;
	return temp.str();
}

void	NinjaTrap::takeDamage(unsigned int amount)
{
	if (amount > armor_damage_reduction())
	{
		if (amount - armor_damage_reduction() > hit_points())
			set_hit_points(0);
		else
			set_hit_points(hit_points() - amount - armor_damage_reduction());
	}

	std::cout	<< RED << "(taking " << amount << " points of damage) " << RESET
				<< this->get_health()
				<< take_damage_list[std::rand() % take_damage_list_len]
				<< std::endl;
}

void	NinjaTrap::beRepaired(unsigned int amount)
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

void	NinjaTrap::ninjaShoebox(FragTrap const & other) const
{
	std::cout	<< "* * *" << std::endl;
	std::cout	<< this->get_health() << " Ah, man, I am so late!" << std::endl
				<< this->get_health() << " NO! Son of a... HEY! You! Yeah yeah, FrapTrap unit!" << std::endl
	   			<< other.get_health() << " Who -- uh, me sir?" << std::endl
				<< this->get_health() << " Oh, no, I'm sorry the OTHER Hyperion piece of metal crap that can open doors for me. I'm sorry." << std::endl
	   			<< other.get_health() << " can do more than open doors sir! We FR4G-TP units can be programmed to do anything from open doors to ninja-sassinate highly important Janitory officals!" << std::endl
				<< this->get_health() << " Yeahyeahyeah, just -- wait, you can actually do that?" << std::endl
	   			<< other.get_health() << " Certainly!" << std::endl
	   			<< other.get_health() << " I once started a revolution myself. There were lots of guns and a lot of dying. You'd think I would have gotten some better benefits out of the whole thing but no, demoted back to door-opening servitude!" << std::endl
				<< this->get_health() << " Yeahyeahyeahyeah, got it, just shut up and open the door. I'm late for the quarterly meeting." << std::endl
	   			<< other.get_health() << " Sure thing, sir! Aaaand OPEN! Have a lovely afternoon, and thank you for using Hyperion Robot Services. Let me know if you have any other portal-rific needs!" << std::endl
				<< this->get_health() << " Oh, I will. I most certainly will." << std::endl;
	std::cout	<< "* * *" << std::endl;
}

void	NinjaTrap::ninjaShoebox(ScavTrap const & other) const
{
	std::cout	<< "* * *" << std::endl;
	std::cout	<< this->get_health() << " When you say \"failsafe\"... what is it you mean exactly?" << std::endl
	   			<< other.get_health() << " I mean exactly that, " << name() << ". All SCAV-TP units have a built in failsafe that prevents them from being tampered with." << std::endl
				<< this->get_health() << " Y-yeah, but for like, bandits and stuff. Not other Hyperion personnel!" << std::endl
	   			<< other.get_health() << " INCLUDING other Hyperion personnel. Just feel lucky you didn't pick one that spontaneously combusted, or you'd have more then a migraine from too much bass." << std::endl
				<< this->get_health() << " Thanks for all your HELP, " << other.name() << std::endl
	   			<< this->get_health() << " That guy. If I can't get rid of Scavtrap's dance protocols I'll have to... work around them." << std::endl
				<< this->get_health() << " Hey, Angel? Run an analysis on how many subroutines we'd have to include to minimize the potential that my prototype won't drop what he's doing and sing karaoke." << std::endl;
	std::cout	<< "* * *" << std::endl;
}

void	NinjaTrap::ninjaShoebox(NinjaTrap const & other) const
{
	std::cout	<< "* * *" << std::endl;
	std::cout	<< this->get_health() << " Umm, " << other.name() << "?" << std::endl
	   			<< other.get_health() << " What is it " << name() << "?" << std::endl
				<< this->get_health() << " There are too many variables to allow for a complete overhaul of the Prototype's systems. You may just have to settle for... a flawed product. Or try a different model. CL4P's are outdated by three generations, with marked improvements." << std::endl
	   			<< other.get_health() << " Nah, that's not the point. The newer versions don't have the space and flexibility I need to make this work. I NEED someone that can think for themselves, but can't disobey an order. Like, say, \"Don't open your presents until Mercenary Day\"." << std::endl
				<< this->get_health() << " Sorry. Perhaps if you re-routed some of the L-cache and bypassed memory sequencing --" << std::endl
	   			<< other.get_health() << " -- Yeah, I... well, hey, that might actually work. He'd lose most of his memories, but, come on. It's just a robot. It's not like it had feelings or anything." << std::endl;
	std::cout	<< "* * *" << std::endl;
}

unsigned int	NinjaTrap::creation_list_len = 6;

const char*	NinjaTrap::creation_list[] = {
	"Hey everybody! Check out my package!",
	"Let's get this party started!",
	"Glitching weirdness is a term of endearment, right?",
	"Recompiling my combat code!",
	"This time it'll be awesome, I promise!",
	"Look out everybody! Things are about to get awesome!"
};

unsigned int	NinjaTrap::take_damage_list_len = 6;

const char	*NinjaTrap::take_damage_list[] = {
	"Why do I even feel pain?!",
	"Why did they build me out of galvanized flesh?!",
	"Ow hohoho, that hurts! Yipes!",
	"My robotic flesh! AAHH!",
	"Woah! Oh! Jeez!",
	"If only my chassis... weren't made of recycled human body parts! Wahahaha!"
};

unsigned int	NinjaTrap::be_repaired_list_len = 6;

const char	*NinjaTrap::be_repaired_list[] = {
	"Health! Eww, what flavor is red?",
	"Health over here!",
	"Sweet life juice!",
	"I found health!",
	"Healsies!",
	"Get repaired!"
};

