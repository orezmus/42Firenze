#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {
private:
	std::string name_;
	AMateria *slot_[4];
	AMateria *floor_[100];
public:
	Character();
	Character(const std::string name_);
	Character(const Character &copy);
	Character &operator=(const Character &copy);
	~Character();

	const std::string &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};

#endif
