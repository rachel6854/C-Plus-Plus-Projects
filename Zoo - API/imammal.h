#ifndef __I_MAMMAL_H__
#define __I_MAMMAL_H__

#include "animal.h"

class Imammal
{
public:
	virtual ~Imammal(){};
	virtual const unsigned char getDurationOfThePregnancy() const =0;
	virtual const unsigned char getNumberOfYoung() const =0;
//friend std::ostream& operator<<(std::ostream& os, const Imammal& imammal);

protected:
	virtual std::ostream& print(std::ostream& os) const=0;

};


#endif




