#include "whale.h"

using std::ostream;
using std::endl;

ostream& Whale::print(ostream& os) const 
{
	Fish::print(os);
	return os<<"Duration of the pregancy: "<<static_cast<int>(getDurationOfThePregnancy())<<"\nNumber of young in each born: "<<static_cast<int>(getNumberOfYoung());	
}
