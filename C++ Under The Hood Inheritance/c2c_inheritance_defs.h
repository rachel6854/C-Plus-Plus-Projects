#ifndef __C2C_INHERITANCE_DEFS_H__
#define __C2C_INHERITANCE_DEFS_H__

#include <stdio.h>
#include "c2c_encapsulation_defs.h"

/* Materials */

enum Types
	{
	PLASTIC,
	METAL,
	WOOD,
	PAPER,
	OTHER
	};
	
typedef enum Types Types;

struct Materials
{
	char pad;
};

typedef struct Materials Materials;

struct Material_t
{	
	Types material;
};

typedef struct Material_t Material_t;

/*Material_t(Types mat = OTHER): material(mat)*/
void _ZN10Material_tC1EN9Materials5TypesE(Material_t* const this,Types mat/* = OTHER*/);


/* PhysicalBox */

struct PhysicalBox
{
	Box boxBase;/*the base part*/
	Material_t material;
};
typedef struct PhysicalBox PhysicalBox;

/*public:*/

/*PhysicalBox(double l, double w, double h);*/
void _ZN11PhysicalBoxC1Eddd(PhysicalBox* const this, double l, double w, double h);

/*PhysicalBox(double l, double w, double h, Materials::Types t);*/
void _ZN11PhysicalBoxC1EdddN9Materials5TypesE(PhysicalBox* const this,double l, double w, double h,Types t);

/*PhysicalBox(Materials::Types t);*/
void _ZN11PhysicalBoxC2EN9Materials5TypesE(PhysicalBox* const this,Types t);

/*~PhysicalBox();*/
void _ZN11PhysicalBoxD1Ev(PhysicalBox* const this);

/*Materials::Types getMaterial() const;*/
Types _ZNK11PhysicalBox11getMaterialEv(const PhysicalBox* const this);

/*void printp() const;*/
void _ZNK11PhysicalBox6printpEv(const PhysicalBox* const this) ;

/*bool operator==(const PhysicalBox&, const PhysicalBox&);*/
bool _ZeqRK11PhysicalBoxS1_(const PhysicalBox*, const PhysicalBox*);

/*bool operator!=(const PhysicalBox&, const PhysicalBox&);*/
bool _ZneRK11PhysicalBoxS1_(const PhysicalBox*, const PhysicalBox*);


/* WeightBox */

struct WeightBox
{
	Box boxBase;/*the base part*/
	double weight;
};

typedef struct WeightBox WeightBox;


/*public:*/

/*WeightBox(double l, double w, double h, double wgt = 0.0);*/
void _ZN9WeightBoxC1Edddd(WeightBox* const this, double l, double w, double h, double wgt /*= 0.0*/);

/*WeightBox(const WeightBox& other);*/
void _ZN9WeightBoxC1ERKS_(WeightBox* const this, const WeightBox* other);

/*~WeightBox();*/
void _ZN9WeightBoxD1Ev(WeightBox* const this);

/*WeightBox& operator=(const WeightBox& other);*/
WeightBox _ZN9WeightBoxaSERKS_(WeightBox* const this, const WeightBox* other);

/*double getWeight() const;*/
double _ZNK9WeightBox9getWeightEv(const WeightBox* const this);

/*void printw() const;*/
void _ZNK9WeightBox6printwEv(const WeightBox* const this);


/*global*/

/*bool operator==(const WeightBox&, const WeightBox&);*/
bool _ZeqRK9WeightBoxS1_(const WeightBox*, const WeightBox*);

/*bool operator!=(const WeightBox&, const WeightBox&);*/
bool _ZneRK9WeightBoxS1_(const WeightBox*, const WeightBox*);

#endif /* __CPP2C_INHERITANCE_DEFS_H__*/


