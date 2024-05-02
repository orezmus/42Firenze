#ifndef CURE_H
# define CURE_H

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class Cure : public AMateria {
public:
	Cure();
	Cure(std::string const &type);
	Cure(const Cure &copy);
	Cure &operator=(const Cure &copy);
	~Cure();

	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif
