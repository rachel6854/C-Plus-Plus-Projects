#ifndef __LION_H__
#define __LION_H__

#include "mammal.h"

class Lion:public Mammal
{
public:
	Lion(const std::string& name) : Mammal(name){};
	~Lion(){};
	/*virtual*/ const std::string& getSpecies() const;
	/*virtual*/ const unsigned char getLifeExpectancy() const;
	/*virtual*/ const std::vector<std::string>& getContinents() const;
	/*virtual*/ const std::vector<std::string>& getTypesOfFood() const;
	/*virtual*/ const unsigned char getSpeed() const;
	/*virtual*/ const unsigned char getDurationOfThePregnancy() const;
	/*virtual*/ const unsigned char getNumberOfYoung() const;
	
/*private:
	static const vector<string> m_continents;
	static const vector<string> m_types_of_food;
	static const unsigned char m_life_expectancy;
	static const unsigned char m_speed;
	static unsigned char m_duration_of_the_pregnancy;
	static unsigned char m_number_of_young;*/
};



inline const std::string& Lion::getSpecies() const
{
	static std::string s("Lion");
	
	return s;
}

inline const unsigned char Lion::getLifeExpectancy() const
{
	return 12;
}

inline const std::vector<std::string>& Lion::getContinents() const
{
	static std::vector<std::string> ret_vect;
	if (ret_vect.empty())
	{
		ret_vect.push_back(std::string("Asia"));
		ret_vect.push_back(std::string("Africa"));
	}
	return ret_vect;
}

inline const std::vector<std::string>& Lion::getTypesOfFood() const
{
	static std::vector<std::string> ret_vect;
	if (ret_vect.empty())
	{
		ret_vect.push_back(std::string("Meat"));
	}
	return ret_vect;
}

inline const unsigned char Lion::getSpeed() const
{
	return 80;
}

inline const unsigned char Lion::getDurationOfThePregnancy() const
{
	return 110;
}
inline const unsigned char Lion::getNumberOfYoung() const
{
	return 4;
}


#endif
