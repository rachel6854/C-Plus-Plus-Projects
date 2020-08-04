#include "bird.h"

using std::endl;
using std::ostream;


ostream& Bird::print(ostream& os) const 
{
	Animal::print(os);
	os<<"Typical height he can reach: "<<this->getHeightCanReach()<<"\nWing-span: "<< static_cast<int>(this->getWingSpan())<<std::endl;
	return os;	
}
