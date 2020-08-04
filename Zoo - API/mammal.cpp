#include "mammal.h"

using std::endl;
using std::ostream;


ostream& Mammal::print(ostream& os) const 
{
	Animal::print(os); 
	return os<<"Duration of the pregancy: "<<static_cast<int>(getDurationOfThePregnancy())<<"\nNumber of young in each born: "<<static_cast<int>(getNumberOfYoung())<<endl;	
}
