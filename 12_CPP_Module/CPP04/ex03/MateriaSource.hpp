#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
public:
    MateriaSource();
    MateriaSource(const MateriaSource &copy);
    MateriaSource &operator=(const MateriaSource &copy);
    ~MateriaSource();
    void learnMateria(AMateria*);
    AMateria *createMateria(std::string const &type);
};

#endif