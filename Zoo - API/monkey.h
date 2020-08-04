#ifndef __MONKEY_H__
#define __MONKEY_H__


#include "mammal.h"

class Monkey:public Mammal
{
public:
	Monkey(const std::string& name):Mammal(name){};
	~Monkey(){};
	/*virtual*/ const std::string& getSpecies() const;
	/*virtual*/ const unsigned char getLifeExpectancy() const;
	/*virtual*/ const std::vector<std::string>& getContinents() const;
	/*virtual*/ const std::vector<std::string>& getTypesOfFood() const;
	/*virtual*/ const unsigned char getSpeed() const;
	/*virtual*/ const unsigned char getDurationOfThePregnancy() const;
	/*virtual*/ const unsigned char getNumberOfYoung() const;

};



inline const std::string& Monkey::getSpecies() const
{
	static const std::string s("Monkey");
	
	return s;
}

inline const unsigned char Monkey::getLifeExpectancy() const
{
	return 50;
}

inline const std::vector<std::string>& Monkey::getContinents() const
{
	static std::vector<std::string> ret_vect;
	if (ret_vect.empty())
	{
		ret_vect.push_back(std::string("Asia"));
		ret_vect.push_back(std::string("Africa"));
		ret_vect.push_back(std::string("South America"));
	}
	return ret_vect;
}

inline const std::vector<std::string>& Monkey::getTypesOfFood() const
{
	static std::vector<std::string> ret_vect;
	if (ret_vect.empty())
	{
		ret_vect.push_back(std::string("Leaves"));
		ret_vect.push_back(std::string("Fruits"));
	}
	return ret_vect;
}

inline const unsigned char Monkey::getSpeed() const
{
	return 34;
}

inline const unsigned char Monkey::getDurationOfThePregnancy() const
{
	return 150;
}
inline const unsigned char Monkey::getNumberOfYoung() const
{
	return 1;
}


#endif
