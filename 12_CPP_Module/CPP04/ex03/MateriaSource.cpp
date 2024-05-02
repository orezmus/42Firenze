#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		materia_[i] = NULL; 
}

MateriaSource::MateriaSource(const MateriaSource &copy) {
	for (int i = 0; i < 4; i++)
	{    
		materia_[i] = NULL;
		if (copy.materia_[i])
			materia_[i] = copy.materia_[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource &copy){
	if (this != &copy)
	{
		for (int i = 0; i < 4; i++)
		{
			if (materia_[i]) 
			{
				delete materia_[i];
				materia_[i] = NULL;
			}
			if (copy.materia_[i])
				materia_[i] = copy.materia_[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < 4; i++)
	{
		if (materia_[i]) 
		{
			delete materia_[i];
			materia_[i] = NULL;
		}
	}
}

void MateriaSource::learnMateria(AMateria *m) {
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!materia_[i])
		{
			materia_[i] = m;
			break ;
		}
	}
}   

AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++)
	{
		if (materia_[i] && materia_[i]->getType() == type)
			return materia_[i]->clone();
	}
	return 0;
}


