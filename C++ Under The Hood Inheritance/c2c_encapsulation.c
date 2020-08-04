#include <stdio.h>
#include "c2c_encapsulation_defs.h"

extern const char* DEF_MSG;
extern const char* message;

static Box box99;
static Box box88;
static Box largeBox;

static size_t sum_this=0;
static size_t sum_that=0;

void _GLOBAL_thisFuncv()
{

	
	printf("\n--- thisFunc() ---\n\n"); 
	
	/*static Box box99(99, 99, 99);*/
	if (sum_this++==0)
		_ZN3BoxC1Eddd(&box99,99,99,99);

	/*box99 *= 10;*/
	_ZN3BoxmLEd(&box99,10);
}

void _GLOBAL_thatFuncv()
{

	printf("\n--- thatFunc() ---\n\n"); 
	
	/*static Box box88(88, 88, 88);*/
	if (sum_that++==0)
		_ZN3BoxC1Eddd(&box88,88,88,88);

	_ZN3BoxmLEd(&box88,10);
}

void doBoxes()
{
	Box b1;
	Box b2;
	Box b3;
	Box b4;
	
	printf("\n--- Start doBoxes() ---\n\n");

	_ZN3BoxC2Ed(&b1,3);
	_ZN3BoxC1Eddd(&b2,4,5,6);

	/*printf("b1 volume: %f\n", b1.getVolume());*/
	printf("b1 volume: %f\n",b1.length*b1.width*b1.height);
	
	/*printf("b2 volume: %f\n", b2.getVolume());*/
	printf("b2 volume: %f\n", b2.length*b2.width*b2.height);


	_ZN3BoxmLEd(&b1,1.5);
	_ZN3BoxmLEd(&b2,0.5);

	/*printf("b1 volume: %f\n", b1.getVolume());*/
	printf("b1 volume: %f\n", b1.length*b1.width*b1.height);
	
	/*printf("b2 volume: %f\n", b2.getVolume());*/
	printf("b2 volume: %f\n",b2.length*b2.width*b2.height);

	/*Box b3 = b2;
	assigment operator*/
	_ZN2BoxaSEBox(&b3,&b2);
	
	/*Box b4 = 3 * b2;*/
	b4=_ZN3BoxmLEd(&b2,3);

	/*printf("b3 %s b4\n", b3 == b4 ? "equals" : "does not equal");*/
	printf("b3 %s b4\n",(b3.width == b4.width && b3.height == b4.height && b3.length == b4.length)? "equals" : "does not equal");


	_ZN3BoxmLEd(&b3,1.5);
	_ZN3BoxmLEd(&b4,0.5);
	/*printf("Now, b3 %s b4\n", b3 == b4 ? "equals" : "does not equal");*/
	printf("Now, b3 %s b4\n", (b3.width == b4.width && b3.height == b4.height && b3.length == b4.length)? "equals" : "does not equal");

	printf("\n--- End doBoxes() ---\n\n");
    
	/*DTOR*/
	_ZN3BoxD1Ev(&b1);
	_ZN3BoxD1Ev(&b2);
	_ZN3BoxD1Ev(&b3);
	_ZN3BoxD1Ev(&b4);
}


void doShelves()
{
	Box aBox;
	Box tmp1;
	Box tmp2;
	Shelf aShelf;
	
	printf("\n--- start doShelves() ---\n\n");

	/*Box aBox = 5;*/
	_ZN3BoxC2Ed(&aBox,5);

	/*Shelf aShelf;*/
	/*default Constructor*/
	_ZN5ShelfC1Ev(&aShelf);

	/*aShelf.print();*/
	_ZNK5Shelf5printEv(&aShelf);
	
	/*aShelf.setBox(1, largeBox);*/
	_ZN5Shelf6setBoxEiRK3Box(&aShelf,1, &largeBox);
	
	/*aShelf.setBox(0, aBox);*/
	_ZN5Shelf6setBoxEiRK3Box(&aShelf,0, &aBox);

	/*aShelf.print();*/
	_ZNK5Shelf5printEv(&aShelf);
	
	/*aShelf.setMessage("This is the total volume on the shelf:");*/
	message = "This is the total volume on the shelf:";
	
	/*aShelf.print();*/
	_ZNK5Shelf5printEv(&aShelf);
	
	/*Shelf::setMessage("Shelf's volume:");*/
	message = "Shelf's volume:";
	
	/*aShelf.print();*/
	_ZNK5Shelf5printEv(&aShelf);

	/*aShelf.setBox(1, Box(2, 4, 6));*/
	_ZN3BoxC1Eddd(&tmp1,2,4,6);
        _ZN5Shelf6setBoxEiRK3Box(&aShelf,1, &tmp1);

	/*aShelf.setBox(2, 2);*/
	_ZN3BoxC2Ed(&tmp2,2);
	_ZN5Shelf6setBoxEiRK3Box(&aShelf,2, &tmp2);
	
	/*aShelf.print();*/
	_ZNK5Shelf5printEv(&aShelf);

	printf("\n--- end doShelves() ---\n\n");
	

    	/*??????_ZN3BoxD1Ev(&tmp1);
    	??????_ZN3BoxD1Ev(&tmp2);*/
    	
    	/*default Distructor*/
	_ZN5ShelfD1Ev(&aShelf);
	
	/*DTOR*/
    	_ZN3BoxD1Ev(&aBox);
    
}

/*int main()
{
	_ZN3BoxC1Eddd(&largeBox,10, 20, 30);
	printf("\n--- Start main() ---\n\n");

	doBoxes();


	_GLOBAL_thisFuncv();
	_GLOBAL_thisFuncv();
	_GLOBAL_thisFuncv();
	_GLOBAL_thatFuncv();
	_GLOBAL_thatFuncv();

	doShelves();

	printf("\n--- End main() ---\n\n");*/
	
	/*DTOR*/
	/*if(sum_this)
		_ZN3BoxD1Ev(&box88);
	if(sum_that)
		_ZN3BoxD1Ev(&box99);
	_ZN3BoxD1Ev(&largeBox);

	return 0;
}*/


