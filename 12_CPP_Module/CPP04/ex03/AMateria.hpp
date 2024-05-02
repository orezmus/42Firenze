#ifndef AMATERIA_H
# define AMATERIA_H

#include <iostream>
#include <string>

class ICharacter;

class AMateria {
protected:
	std::string type_;
public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(const AMateria &copy);
	AMateria& operator=(const AMateria &copy);
	virtual ~AMateria();

	const std::string &getType() const;
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif
