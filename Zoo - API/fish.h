#ifndef __FISH_H__
#define __FISH_H__

#include "animal.h"

class Fish : public Animal
{
public:
	Fish(const std::string& name):Animal(name){};
	virtual ~Fish(){};
	virtual const unsigned int getLowestDepth() const =0;
	
friend std::ostream& operator<<(std::ostream& os, const Fish& fish);

protected:
	virtual std::ostream& print(std::ostream& os) const;

};


inline std::ostream& operator<<(std::ostream& os, const Fish& fish)
{
	return fish.print(os);

}


#endif

