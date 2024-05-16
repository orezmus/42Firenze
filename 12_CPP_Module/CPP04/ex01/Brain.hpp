#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
protected:
	std::string ideas_[100];
public:
	Brain();
	Brain(const Brain &copy);
	Brain &operator=(const Brain &copy);
	~Brain();

	std::string identify() const;
};

#endif