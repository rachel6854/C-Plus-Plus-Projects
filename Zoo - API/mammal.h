#ifndef __MAMMAL_H__
#define __MAMMAL_H__

#include "animal.h"
#include "imammal.h"

class Mammal :public Animal,public Imammal
{
public:
	Mammal(const std::string& name);
	virtual ~Mammal(){};
	virtual const unsigned char getDurationOfThePregnancy() const =0;
	virtual const unsigned char getNumberOfYoung() const =0;
friend std::ostream& operator<<(std::ostream& os, const Mammal& mammal);

protected:
	virtual std::ostream& print(std::ostream& os) const;

};

inline Mammal::Mammal(const std::string& name):Animal(name)
{
}


inline std::ostream& operator<<(std::ostream& os, const Mammal& mammal)
{
	return mammal.print(os);
}


#endif




