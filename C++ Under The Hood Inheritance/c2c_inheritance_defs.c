#include <stdio.h>
#include "c2c_inheritance_defs.h"

/* Material_t */

/*Material_t(Types mat = OTHER): material(mat)*/
void _ZN10Material_tC1EN9Materials5TypesE(Material_t* const this,Types mat/* = OTHER*/)
{ 
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
	
	this->material=mat;
	
	/*printf("Material created, set to %s\n", name()); */
	printf("Material created, set to %s\n", names[this->material]); 
	
}

/* PhysicalBox Defs */

/*PhysicalBox::PhysicalBox(double l, double w, double h)*/
void _ZN11PhysicalBoxC1Eddd(PhysicalBox* const this, double l, double w, double h)
/*:   Box(l, w, h)*/
{
	_ZN3BoxC1Eddd(&this->boxBase,l,w,h);
	
	_ZN10Material_tC1EN9Materials5TypesE(&this->material,OTHER);
	
	/*printp();*/
	_ZNK11PhysicalBox6printpEv(this);
}

/*PhysicalBox::PhysicalBox(double l, double w, double h, Materials::Types t)*/
void _ZN11PhysicalBoxC1EdddN9Materials5TypesE(PhysicalBox* const this,double l, double w, double h, Types t)
/*:   Box(l, w, h)
,   material(t)*/
{
	_ZN3BoxC1Eddd(&this->boxBase,l,w,h);
	
	_ZN10Material_tC1EN9Materials5TypesE(&this->material,t);

	/*printp();*/
	_ZNK11PhysicalBox6printpEv(this);
}

/*PhysicalBox::PhysicalBox(Materials::Types t)*/
void _ZN11PhysicalBoxC2EN9Materials5TypesE(PhysicalBox* const this,Types t)
/*:   material(t)*/
{
	_ZN3BoxC2Ed(&this->boxBase,1);
	
	_ZN10Material_tC1EN9Materials5TypesE(&this->material,t);
	
	/*printp();*/
    	_ZNK11PhysicalBox6printpEv(this);
}

/*PhysicalBox::~PhysicalBox()*/
void _ZN11PhysicalBoxD1Ev(PhysicalBox* const this)
{
	/*printf("PhysicalBox dtor, %f x %f x %f, %s; ", getLength(), getWidth(), getHeight(), material.name());*/

	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };	
	printf("PhysicalBox dtor, %f x %f x %f, %s; ", this->boxBase.length, this->boxBase.width, this->boxBase.height,names[this->material.material]);
	
	_ZN3BoxD1Ev(&this->boxBase);
	
}

/*void PhysicalBox::printp() const*/
void _ZNK11PhysicalBox6printpEv(const PhysicalBox* const this) 
{
	/*printf("PhysicalBox, made of %s; ", material.name());*/
	const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
	printf("PhysicalBox, made of %s; ",names[this->material.material]);
	
	/*print();*/
	_ZNK3Box5printEv(&this->boxBase);
}


/* WeightBox Defs */



/*WeightBox::WeightBox(double l, double w, double h, double wgt)*/
void _ZN9WeightBoxC1Edddd(WeightBox* const this, double l, double w, double h, double wgt/* = 0.0*/)
/*:   Box(l, w, h)
,   weight(wgt)*/
{
	_ZN3BoxC1Eddd(&this->boxBase,l,w,h);
	
	this->weight=wgt;
	
	/*printw();*/
	_ZNK9WeightBox6printwEv(this);
}

/*WeightBox::WeightBox(const WeightBox& other)*/
void _ZN9WeightBoxC1ERKS_(WeightBox* const this, const WeightBox* other)
/*:   weight(other.weight)*/
{
	/*call ctor base instead of copy ctor*/
	_ZN3BoxC2Ed(&this->boxBase,1);
	
	this->weight=other->weight;
	
	/*printw();*/
    	_ZNK9WeightBox6printwEv(this);
}

/*WeightBox::~WeightBox()*/
void _ZN9WeightBoxD1Ev(WeightBox* const this)
{
	printf("Destructing WeightBox; ");
	
	/*printw();*/
    	_ZNK9WeightBox6printwEv(this);
    	
    	_ZN3BoxD1Ev(&this->boxBase);
}

/*WeightBox& WeightBox::operator=(const WeightBox& other)*/
WeightBox _ZN9WeightBoxaSERKS_(WeightBox* const this, const WeightBox* other)
{
	/*this->boxBase=this->boxBase;*/
	
	this->weight = other->weight;
	return *this;
}

/*void WeightBox::printw() const*/
void _ZNK9WeightBox6printwEv(const WeightBox* const this)
{
    printf("WeightBox, weight: %f; ", this->weight);
    /*print();*/
    _ZNK3Box5printEv(&this->boxBase);
}


