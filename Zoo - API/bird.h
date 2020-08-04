#ifndef __BIRD_H__
#define __BIRD_H__

#include "animal.h"


class Bird : public Animal
{
public:
	Bird(const std::string& name):Animal(name){};
	virtual ~Bird(){};
	virtual const unsigned int getHeightCanReach() const =0;
	virtual const unsigned char getWingSpan() const =0;
	
friend std::ostream& operator<<(std::ostream& os, const Bird& bird);

private:
	virtual std::ostream& print(std::ostream& os) const;

};

inline std::ostream& operator<<(std::ostream& os, const Bird& bird)
{
	return bird.print(os);
}

#endif
