#include "animal.h"


using std::endl;
using std::ostream;


ostream& Animal::print(ostream& os) const
{
	os <<"Name: " << getName();
	os << "\nSpecies: " << getSpecies();
	os << "\nLife expectancy: " << static_cast<int>(getLifeExpectancy());
	os << "\nThe continent(s) where it is naturally found: ";
	
	size_t size=getContinents().size();
	for (long unsigned int i = 0; i < size; ++i) //print the vector of Continents
	{ 
        os << getContinents()[i]; 
        if (i !=size - 1)
        { 
            os << ", ";
        } 
	} 
	
	os<< "\nTypes of food: ";
	size=getTypesOfFood().size();
	for (long unsigned int i = 0; i < size; ++i) //print the vector of types of food
	{ 
        os << getTypesOfFood()[i];
        	 
       	if (i != size - 1) 
    	{
        	os << ", "; 
        }
	}
	
	os << "\nSpeed: "<<static_cast<int>(getSpeed()) << std::endl;
	return os;
}


