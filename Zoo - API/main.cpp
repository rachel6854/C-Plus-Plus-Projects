#include "lion.h"
#include "monkey.h"
#include "snowy_owl.h"
#include "goose.h"
#include "dog.h"
#include "shark.h"
#include "clownfish.h"
#include "whale.h"


using std::string;
using std::cout;
using std::vector;
using std::endl;

void printAnimals(vector<Animal*> animals)
{
	cout<<"We are printing our animals now..."<<endl;
	for(size_t i=0;i<animals.size();++i)
		{
		cout<<*animals[i]<<endl;
		}
}

int main()
{
	vector<Animal*> animals;
	Lion simba(string("Simba"));
	animals.push_back(&simba);

	Lion mufasa(string("Mufasa"));
	animals.push_back(&mufasa);

	Monkey rafiki(string("Rafiki"));
	animals.push_back(&rafiki);

	Goose akka(string("Akka"));
	animals.push_back(&akka);

	Goose morten(string("Morten"));
	animals.push_back(&morten);
	
	SnowyOwl hedwig(string("Hedwig"));
	animals.push_back(&hedwig);

	Dog toto(string("Toto"));
	animals.push_back(&toto);

	Shark jaws(string("Jaws"));
	animals.push_back(&jaws);

	Clownfish nemo(string("Nemo"));
	animals.push_back(&nemo);
	
	Whale whale(string("my whale"));
	animals.push_back(&whale);

	printAnimals(animals);

}
