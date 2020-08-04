#ifndef __GOOSE_H__
#define __GOOSE_H__


#include "bird.h"

class Goose:public Bird
{
public:
	Goose(const std::string& name):Bird(name){};
	~Goose(){};
	/*virtual*/ const std::string& getSpecies() const;
	/*virtual*/ const unsigned char getLifeExpectancy() const;
	/*virtual*/ const std::vector<std::string>& getContinents() const;
	/*virtual*/ const std::vector<std::string>& getTypesOfFood() const;
	/*virtual*/ const unsigned char getSpeed() const;
	/*virtual*/ const unsigned int getHeightCanReach() const;
	/*virtual*/ const unsigned char getWingSpan() const;
};


inline const std::string& Goose::getSpecies() const
{
	static const std::string s("Goose");
	
	return s;
}

inline const unsigned char Goose::getLifeExpectancy() const
{
	return 20;
}

inline const std::vector<std::string>& Goose::getContinents() const
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



inline const std::vector<std::string>& Goose::getTypesOfFood() const
{
	static std::vector<std::string> ret_vect;
	if (ret_vect.empty())
	{
		ret_vect.push_back(std::string("Vegetables"));
	}
	return ret_vect;
}

inline const unsigned char Goose::getSpeed() const
{
	return static_cast<char>(400);
}

inline const unsigned int Goose::getHeightCanReach() const
{
	return 5000;
}

inline const unsigned char Goose::getWingSpan() const
{
	return 150;	//cm
}



#endif
