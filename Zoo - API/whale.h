#ifndef __WHALE__
#define __WHALE__

#include "mammal.h"
#include "fish.h"

class Whale : public Imammal,public Fish
{
public:
	Whale(const std::string& name) : Fish(name){};
	~Whale(){};
	/*virtual*/ const std::string& getSpecies() const;
	/*virtual*/ const unsigned char getLifeExpectancy() const;
	/*virtual*/ const std::vector<std::string>& getContinents() const;
	/*virtual*/ const std::vector<std::string>& getTypesOfFood() const;
	/*virtual*/ const unsigned char getSpeed() const;
	/*virtual*/ const unsigned char getDurationOfThePregnancy() const;
	/*virtual*/ const unsigned char getNumberOfYoung() const;
	/*virtual*/ const unsigned int getLowestDepth() const;
	
friend std::ostream& operator<<(std::ostream& os, const Whale& whale);

protected:
	virtual std::ostream& print(std::ostream& os) const;
};



inline const std::string& Whale::getSpecies() const
{
	static std::string s("Whale");
	
	return s;
}

inline const unsigned char Whale::getLifeExpectancy() const
{
	return 60;
}

inline const std::vector<std::string>& Whale::getContinents() const
{
	static std::vector<std::string> ret_vect;
	if (ret_vect.empty())
	{
		ret_vect.push_back(std::string("Arctic oceans"));
		ret_vect.push_back(std::string("Antarctic oceans"));
		ret_vect.push_back(std::string("ropical waters in and around the center of the equator"));
	}
	return ret_vect;
}

inline const std::vector<std::string>& Whale::getTypesOfFood() const
{
	static std::vector<std::string> ret_vect;
	if (ret_vect.empty())
	{
		ret_vect.push_back(std::string("Fish"));
	}
	return ret_vect;
}

inline const unsigned char Whale::getSpeed() const
{
	return 50;	//km
}

inline const unsigned char Whale::getDurationOfThePregnancy() const
{
	return 13;
}
inline const unsigned char Whale::getNumberOfYoung() const
{
	return 1;
}

inline const unsigned int Whale::getLowestDepth() const
{
	return 3000;	//metres
}
inline std::ostream& operator<<(std::ostream& os, const Whale& whale)
{
	return whale.print(os);
}

#endif
