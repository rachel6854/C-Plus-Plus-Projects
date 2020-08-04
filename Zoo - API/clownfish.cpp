#include "fish.h"
#include "clownfish.h"

using std::ostream;

class Clownfish;

ostream& operator<<(ostream& os, const Clownfish& clownfish)
{
	return os << static_cast<const Fish &>(clownfish);   //os << (const Fish &)clownfish;
}
