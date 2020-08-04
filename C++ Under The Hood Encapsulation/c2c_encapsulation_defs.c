#include <stdio.h>
#include "c2c_encapsulation_defs.h"

const char* DEF_MSG="The total volume held on the shelf is";
const char* message="The total volume held on the shelf is";

/* Box */

/*Box::Box(double dim)*/
void _ZN3BoxC2Ed(Box *this,double dim) 
{ 
	this->length=dim;
	this->width=dim;
	this->height=dim;

	_ZNK3Box5printEv(this);
}


/*Box::Box(double l, double w, double h) */
void _ZN3BoxC1Eddd(Box *this, double l, double w, double h)
{ 
	this->length=l;
	this->width=w;
	this->height=h;

	_ZNK3Box5printEv(this);
}

/*Box::~Box()*/
void _ZN3BoxD1Ev(Box* this)
{
    printf("Box destructor, %f x %f x %f\n", this->width, this->height, this->length);
}

/*Box* Box::operator*=(double mult)*/
Box _ZN3BoxmLEd(Box* this,double mult)
{
	this->width *= mult;
	this->height *= mult;
	this->length *= mult;

	return *this;
}

/*void Box::print() const*/
void _ZNK3Box5printEv(Box *this)
{
	/*printf("Box: %f x %f x %f\n", length, width, height); */
	printf("Box: %f x %f x %f\n", this->length, this->width, this->height); 
}



/*Shelf */


/*void Shelf::setBox(int index, const Box& dims)*/
void _ZN5Shelf6setBoxEiRK3Box(Shelf* this, int index, const Box* dims)
{
	this->boxes[index] = *dims;
}

/*double Shelf::getVolume() const*/
double _ZNK5Shelf9getVolumeEv(Shelf* this)
{
	double vol = 0;
	size_t i;
	for (i = 0; i < 3/*NUM_BOXES*/; ++i)
		/*vol += boxes[i].getVolume();*/
		vol += ((this->boxes[i]).length*(this->boxes[i]).width*(this->boxes[i]).height);

    return vol;
}

/*void Shelf::print() const*/
void _ZNK5Shelf5printEv(Shelf* this)
{
	/*printf("%s %f\n", message, getVolume());*/
	printf("%s %f\n", message, _ZNK5Shelf9getVolumeEv(this));
}




/* Box Defs */


Box _ZN2BoxaSEBox(Box* this,Box *other_box){
	this->length=other_box->length;
	this->width=other_box->width;
	this->height=other_box->height;
	return *this;
}



/* Shelf Defs */

/*default Constructor*/
void _ZN5ShelfC1Ev(Shelf* const this)
{
	Box box1;
	Box box2;
	Box box3;
	
	_ZN3BoxC2Ed(&box1,1);
	_ZN3BoxC2Ed(&box2,1);
	_ZN3BoxC2Ed(&box3,1);

	this->boxes[0]=box1;
	this->boxes[1]=box2;
	this->boxes[2]=box3;
}

/*default Distructor*/
void _ZN5ShelfD1Ev(Shelf* const this)
{
	_ZN3BoxD1Ev(&(this->boxes[2]));
	_ZN3BoxD1Ev(&(this->boxes[1]));
	_ZN3BoxD1Ev(&(this->boxes[0]));
}

