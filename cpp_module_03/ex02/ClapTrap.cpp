#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "(default ClapTrap constructor)" << std::endl;
}

ClapTrap::ClapTrap(
		unsigned int hit_points,
		unsigned int max_hit_points,
		unsigned int energy_points,
		unsigned int level,
		std::string const & name,
		unsigned int melee_attack_damage,
		unsigned int ranged_attack_damage,
		unsigned int armor_damage_reduction
		) :	hit_points_(hit_points),
			max_hit_points_(max_hit_points),
			energy_points_(energy_points),
			level_(level),
			name_(name),
			melee_attack_damage_(melee_attack_damage),
			ranged_attack_damage_(ranged_attack_damage),
			armor_damage_reduction_(armor_damage_reduction)
{
	std::cout << "(name ClapTrap constructor)" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "\t(ClapTrap Destructor)" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & other) : 
		hit_points_(other.hit_points()),
		max_hit_points_(other.max_hit_points()),
		energy_points_(other.energy_points()),
		level_(other.level()),
		name_(other.name()),
		melee_attack_damage_(other.melee_attack_damage()),
		ranged_attack_damage_(other.ranged_attack_damage()),
		armor_damage_reduction_(other.armor_damage_reduction())
{
	std::cout << "(ClapTrap copy constructor)" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & other)
{
	if (this != &other)
	{
		hit_points_ = other.hit_points_;
		set_max_hit_points(other.max_hit_points());
		set_energy_points(other.energy_points());
		set_level(other.level());
		set_name(other.name());
		set_melee_attack_damage(other.melee_attack_damage());
		set_ranged_attack_damage(other.ranged_attack_damage());
		set_armor_damage_reduction(other.armor_damage_reduction());
	}

	std::cout << "(operator \"=\")" << std::endl;
	return *this;
}

unsigned int	ClapTrap::hit_points() const				{ return hit_points_; }
unsigned int	ClapTrap::max_hit_points() const			{ return max_hit_points_; }
unsigned int	ClapTrap::energy_points() const				{ return energy_points_; }
unsigned int	ClapTrap::level() const						{ return level_; }
std::string		ClapTrap::name() const						{ return name_; }
unsigned int	ClapTrap::melee_attack_damage() const		{ return melee_attack_damage_; }
unsigned int	ClapTrap::ranged_attack_damage() const		{ return ranged_attack_damage_; }
unsigned int	ClapTrap::armor_damage_reduction() const	{ return armor_damage_reduction_; }

void			ClapTrap::set_hit_points(unsigned int num)				{ hit_points_ = num; }
void			ClapTrap::set_max_hit_points(unsigned int num)			{ max_hit_points_ = num; }
void			ClapTrap::set_energy_points(unsigned int num)			{ energy_points_ = num; }
void			ClapTrap::set_level(unsigned int num)					{ level_ = num; }
void			ClapTrap::set_name(std::string name)					{ name_ = name; }
void			ClapTrap::set_melee_attack_damage(unsigned int num)		{ melee_attack_damage_ = num; }
void			ClapTrap::set_ranged_attack_damage(unsigned int num)	{ ranged_attack_damage_ = num; }
void			ClapTrap::set_armor_damage_reduction(unsigned int num)	{ armor_damage_reduction_ = num; }
