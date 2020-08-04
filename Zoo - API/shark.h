#ifndef __SHARK_H__
#define __SHARK_H__

#include "fish.h"
#include "shark.h"

class Shark:public Fish
{
public:
	Shark(const std::string& name):Fish(name){};
	~Shark(){};
	/*virtual*/ const std::string& getSpecies() const;
	/*virtual*/ const unsigned char getLifeExpectancy() const;
	/*virtual*/ const std::vector<std::string>& getContinents() const;
	/*virtual*/ const std::vector<std::string>& getTypesOfFood() const;
	/*virtual*/ const unsigned char getSpeed() const;
	/*virtual*/ const unsigned int getLowestDepth() const;

};



inline const std::string& Shark::getSpecies() const
{
	static const std::string s("Shark");
	
	return s;
}

inline const unsigned char Shark::getLifeExpectancy() const
{
	return 25;
}

inline const std::vector<std::string>& Shark::getContinents() const
{
	static std::vector<std::string> ret_vect;
	if (ret_vect.empty())
	{
		ret_vect.push_back(std::string("Atlantic ocean"));
		ret_vect.push_back(std::string("Pacific ocean"));
		ret_vect.push_back(std::string("Indian ocean"));
		ret_vect.push_back(std::string("Southern ocean"));
	}
	return ret_vect;
}

inline const std::vector<std::string>& Shark::getTypesOfFood() const
{
	static std::vector<std::string> ret_vect;
	if (ret_vect.empty())
	{
		ret_vect.push_back(std::string("Fish"));
	}
	return ret_vect;
}

inline const unsigned char Shark::getSpeed() const
{
	return 50;
}

inline const unsigned int Shark::getLowestDepth() const
{
	return 2000;	//metres
}


#endif
