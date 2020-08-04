#ifndef __SNOWY_OWL_H__
#define __SNOWY_OWL_H__

#include "bird.h"
#include "snowy_owl.h"

class SnowyOwl:public Bird
{
public:
	SnowyOwl(const std::string& name):Bird(name){};
	~SnowyOwl(){};
	/*virtual*/ const std::string& getSpecies() const;
	/*virtual*/ const unsigned char getLifeExpectancy() const;
	/*virtual*/ const std::vector<std::string>& getContinents() const;
	/*virtual*/ const std::vector<std::string>& getTypesOfFood() const;
	/*virtual*/ const unsigned char getSpeed() const;
	/*virtual*/ const unsigned int getHeightCanReach() const;
	/*virtual*/ const unsigned char getWingSpan() const;
};



inline const std::string& SnowyOwl::getSpecies() const
{
	static std::string s("Snowy Owl");
	
	return s;
}

inline const unsigned char SnowyOwl::getLifeExpectancy() const
{
	return 10;
}

inline const std::vector<std::string>& SnowyOwl::getContinents() const
{
	static std::vector<std::string> ret_vect;
	ret_vect.push_back(std::string("Alaska"));
	ret_vect.push_back(std::string("Northern Canada"));
	ret_vect.push_back(std::string("Eurosiberia"));
	return ret_vect;
}

inline const std::vector<std::string>& SnowyOwl::getTypesOfFood() const
{
	static std::vector<std::string> ret_vect;
	ret_vect.push_back(std::string("Lemmings"));
	return ret_vect;
}

inline const unsigned char SnowyOwl::getSpeed() const
{
	return 80;
}

inline const unsigned int SnowyOwl::getHeightCanReach() const
{
	return 30;
}

inline const unsigned char SnowyOwl::getWingSpan() const
{
	return 150;	//cm
}



#endif
