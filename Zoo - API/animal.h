//created by racheli weinstein

#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <string>
#include <vector>
#include <iostream>


class Animal
{
public:
	Animal(const std::string& name);
	virtual ~Animal(){}
	virtual const std::string& getName() const;
	virtual const std::string& getSpecies() const = 0; 
	virtual const unsigned char getLifeExpectancy() const = 0;
	virtual const std::vector<std::string>& getContinents() const = 0;
	virtual const std::vector<std::string>& getTypesOfFood() const = 0;
	virtual const unsigned char getSpeed() const = 0;

	friend std::ostream& operator<<(std::ostream& os, const Animal& animal);

protected:
	virtual std::ostream& print(std::ostream& os) const;
	
private:
		const std::string m_name;
};

 inline Animal::Animal(const std::string& name) : m_name(name)
 {
 }
 
inline  const std::string& Animal::getName() const
{
	return m_name;
}

inline std::ostream& operator<<(std::ostream& os, const Animal& animal)
{

	return animal.print(os); 
}

#endif
