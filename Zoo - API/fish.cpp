#include "fish.h"

using std::endl;
using std::ostream;

class Fish;


ostream& Fish::print(ostream& os) const 
{
	Animal::print(os);
	os<<"The lowest depth he can reach: "<<getLowestDepth()<<endl;
	return os;	
}
