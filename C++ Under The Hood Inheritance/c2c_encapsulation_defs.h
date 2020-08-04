#ifndef __C2C_ENCAPSULATION_DEFS_H__
#define __C2C_ENCAPSULATION_DEFS_H__
#include <stdbool.h>

/*Box */

struct Box{
	double length;
	double width;
	double height;
};
typedef struct Box Box;

/*public:*/
    
/*Box(double dim = 1);*/
void _ZN3BoxC2Ed(Box* const this,double dim);

/*Box(double l, double w, double h);*/
void _ZN3BoxC1Eddd(Box* const this,double l, double w, double h);

/*~Box();*/
void _ZN3BoxD1Ev(Box* const this);

/*default assigment operator*/
Box _ZN2BoxaSEBox(Box* const this,Box *other_box);

/*Box& operator*=(double mult);*/
Box _ZN3BoxmLEd(Box* const this,double mult);


/*protected:*/

/*void print() const;*/
void _ZNK3Box5printEv();

/*global*/

/*Box operator*(double mult, const Box& box);*/
Box _ZmldRK3Box(double mult, const Box* box);


/* Shelf */

struct Shelf{
/*private:*/
	Box boxes[3];
};

typedef struct Shelf Shelf;


/*public:*/

/*default functions:*/

/*default Constructor*/
void _ZN5ShelfC1Ev(Shelf* const this);

/*default Distructor*/
void _ZN5ShelfD1Ev(Shelf* const this);

/*void setBox(int index, const Box& dims);*/
void _ZN5Shelf6setBoxEiRK3Box(Shelf* const this, int index, const Box* dims);

/*double getVolume() const;*/
double _ZNK5Shelf9getVolumeEv(Shelf* const this);

/*void print() const;*/
void _ZNK5Shelf5printEv(Shelf* const this) ;


#endif /* __C2C_ENCAPSULATION_DEFS_H__*/

