#ifndef BRAIN_H
# define BRAIN_H

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