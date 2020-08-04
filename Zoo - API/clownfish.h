#ifndef __CLOWNFISH_H__
#define __CLOWNFISH_H__

#include "fish.h"
#include "clownfish.h"

class Clownfish:public Fish
{
public:
	Clownfish(const std::string& name):Fish(name){};
	~Clownfish(){};
	/*virtual*/ const std::string& getSpecies() const;
	/*virtual*/ const unsigned char getLifeExpectancy() const;
	/*virtual*/ const std::vector<std::string>& getContinents() const;
	/*virtual*/ const std::vector<std::string>& getTypesOfFood() const;
	/*virtual*/ const unsigned char getSpeed() const;
	/*virtual*/ const unsigned int getLowestDepth() const;
	
friend std::ostream& operator<<(std::ostream& os, const Clownfish& clownfish);

};



inline const std::string& Clownfish::getSpecies() const
{
	static const std::string s("Clownfish");
	return s;
}

inline const unsigned char Clownfish::getLifeExpectancy() const
{
	return 4;
}

inline const std::vector<std::string>& Clownfish::getContinents() const
{
	static std::vector<std::string> ret_vect;
	ret_vect.push_back(std::string("Australia"));
	ret_vect.push_back(std::string("Southeast Asia"));
	ret_vect.push_back(std::string("southern Japan"));
	return ret_vect;
}

inline const std::vector<std::string>& Clownfish::getTypesOfFood() const
{
	static std::vector<std::string> ret_vect;
	ret_vect.push_back(std::string("Fish"));
	ret_vect.push_back(std::string("Vegetables"));
	return ret_vect;
}

inline const unsigned char Clownfish::getSpeed() const
{
	return 0;
}

inline const unsigned int Clownfish::getLowestDepth() const
{
	return 4;	//metres
}
std::ostream& operator<<(std::ostream& os, Clownfish const& clownfish);

#endif
