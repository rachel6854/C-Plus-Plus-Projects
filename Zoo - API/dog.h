#ifndef __DOG_H__
#define __DOG_H__

#include "mammal.h"

class Dog:public Mammal
{
public:
	Dog(const std::string& name):Mammal(name){};
	~Dog(){};
	/*virtual*/ const std::string& getSpecies() const;
	/*virtual*/ const unsigned char getLifeExpectancy() const;
	/*virtual*/ const std::vector<std::string>& getContinents() const;
	/*virtual*/ const std::vector<std::string>& getTypesOfFood() const;
	/*virtual*/ const unsigned char getSpeed() const;
	/*virtual*/ const unsigned char getDurationOfThePregnancy() const;
	/*virtual*/ const unsigned char getNumberOfYoung() const;

};


inline const std::string& Dog::getSpecies() const
{
	static const std::string s("Dog");
	
	return s;
}

inline const unsigned char Dog::getLifeExpectancy() const
{
	return 12;
}

inline const std::vector<std::string>& Dog::getContinents() const
{
	static std::vector<std::string> ret_vect;
	if (ret_vect.empty())
	{
		ret_vect.push_back(std::string("Asia"));
		ret_vect.push_back(std::string("Africa"));
		ret_vect.push_back(std::string("America"));
		ret_vect.push_back(std::string("Australia"));
		ret_vect.push_back(std::string("Europe"));
	}
	return ret_vect;
}

inline const std::vector<std::string>& Dog::getTypesOfFood() const
{
	static std::vector<std::string> ret_vect;
	if (ret_vect.empty())
	{
		ret_vect.push_back(std::string("Meat"));
	}
	return ret_vect;
}

inline const unsigned char Dog::getSpeed() const
{
	return 20;
}

inline const unsigned char Dog::getDurationOfThePregnancy() const
{
	return 60;
}
inline const unsigned char Dog::getNumberOfYoung() const
{
	return 5;
}


#endif
