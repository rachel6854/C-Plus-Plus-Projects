#include <stdio.h>
#include "c2c_inheritance_defs.h"




/*void doMaterials()*/
void _Z11doMaterialsv()
{
	Material_t mat1,mat2;
	Materials mat;
	
	struct MatTest { Materials mat; Material_t mat_t; };
	typedef struct MatTest MatTest;
	
	printf("\n--- Start doMaterials() ---\n\n");


	printf("Size of Materials: %lu\n", sizeof(Materials));
	printf("Size of mat: %lu\n", sizeof(mat));
	printf("Size of Materials::Types: %lu\n", sizeof(Types));
	printf("Size of Material_t: %lu\n", sizeof(Material_t));

	printf("Size of Materials + Material_t: %lu\n", sizeof(MatTest));

	/*Material_t mat1;*/
	_ZN10Material_tC1EN9Materials5TypesE(&mat1,OTHER);
	
	/*Material_t mat2(METAL);*/
	 _ZN10Material_tC1EN9Materials5TypesE(&mat2,METAL);

	printf("\n--- End doMaterials() ---\n\n");
}

/*void doPhysicalBox()*/
void _Z13doPhysicalBoxv()
{
	PhysicalBox pb1,pb2,pb3,pb4;
	printf("\n--- Start doPhysicalBox() ---\n\n");

	/*PhysicalBox pb1(8, 6, 4, Materials::PLASTIC);*/
	_ZN11PhysicalBoxC1EdddN9Materials5TypesE(&pb1,8, 6, 4,PLASTIC);
	
	/*PhysicalBox pb2(Materials::WOOD);*/
	_ZN11PhysicalBoxC2EN9Materials5TypesE(&pb2,WOOD);

	/*PhysicalBox pb3(7, 7, 7);*/
	_ZN11PhysicalBoxC1Eddd(&pb3,7, 7, 7);

	printf("\npb4 is copy-constructed from pb1\n");
	
	/*PhysicalBox pb4 = pb1;*/
	pb4 = pb1;
	
	/*pb4.printp();*/
	_ZNK11PhysicalBox6printpEv(&pb4);
	
	/*pb1.printp();*/
	_ZNK11PhysicalBox6printpEv(&pb1);
	
	printf("pb4 %s pb1\n",pb4.boxBase.length == pb1.boxBase.length && pb4.boxBase.width == pb1.boxBase.width && pb4.boxBase.height == pb1.boxBase.height &&pb4.material.material== pb1.material.material ? "equals" : "does not equal");


	printf("\npb4 is copy-assigned from pb3\n");
	pb4 = pb3;
	
	/*pb4.printp();*/
	_ZNK11PhysicalBox6printpEv(&pb4);
	/*pb3.printp();*/
	_ZNK11PhysicalBox6printpEv(&pb3);
	printf("pb4 %s pb3\n", pb4.boxBase.length == pb3.boxBase.length && pb4.boxBase.width == pb3.boxBase.width && pb4.boxBase.height == pb3.boxBase.height && pb4.material.material== pb3.material.material? "equals" : "does not equal");

	printf("\n--- End doPhysicalBox() ---\n\n");
	
	/*DTOR*/
	_ZN11PhysicalBoxD1Ev(&pb4);
	_ZN11PhysicalBoxD1Ev(&pb3);
	_ZN11PhysicalBoxD1Ev(&pb2);
	_ZN11PhysicalBoxD1Ev(&pb1);
}

/*void doWeightBox()*/
void _Z11doWeightBoxv()
{
	WeightBox pw1,pw2,pw3,pw4;
	
	printf("\n--- Start doWeightBox() ---\n\n");

	/*WeightBox pw1(8, 6, 4, 25);*/
	_ZN9WeightBoxC1Edddd(&pw1,8, 6, 4, 25);
	
	/*WeightBox pw2(1, 2, 3);*/
	_ZN9WeightBoxC1Edddd(&pw2,1,2,3,0.0);
	
	/*WeightBox pw3(10, 20, 30, 15);*/
	_ZN9WeightBoxC1Edddd(&pw3,10, 20, 30, 15);
    
    
	printf("\npw4 is copy-constructed from pw1\n");

	/*WeightBox pw4 = pw1;*/
	_ZN9WeightBoxC1ERKS_(&pw4,&pw1);
	
	/*pw4.printw();*/
	_ZNK9WeightBox6printwEv(&pw4);
	
	/*pw1.printw();*/
	_ZNK9WeightBox6printwEv(&pw1);
	
	printf("pw4 %s pw1\n", pw4.boxBase.length == pw1.boxBase.length && pw4.boxBase.width == pw1.boxBase.width && pw4.boxBase.height == pw1.boxBase.height && pw4.weight== pw1.weight ? "equals" : "does not equal");
	

	printf("\npw4 is copy-assigned from pw3\n");
	/*pw4 = pw3;*/
	_ZN9WeightBoxaSERKS_(&pw4,&pw3);
	
	/*pw4.printw();*/
	_ZNK9WeightBox6printwEv(&pw4);
	
	/*pw3.printw();*/
	_ZNK9WeightBox6printwEv(&pw3);
	
	printf("pw4 %s pw3\n", pw4.boxBase.length == pw3.boxBase.length && pw4.boxBase.width == pw3.boxBase.width && pw4.boxBase.height == pw3.boxBase.height && pw4.weight== pw3.weight ? "equals" : "does not equal");

	
	printf("\n--- End doWeightBox() ---\n\n");
	
	/*DTOR*/
	_ZN9WeightBoxD1Ev(&pw4);
	_ZN9WeightBoxD1Ev(&pw3);
	_ZN9WeightBoxD1Ev(&pw2);
	_ZN9WeightBoxD1Ev(&pw1);
}





int main()
{
	printf("\n--- Start main() ---\n\n");

	/*doMaterials();*/
	_Z11doMaterialsv();

	_Z13doPhysicalBoxv();

	_Z11doWeightBoxv();

	printf("\n--- End main() ---\n\n");
	
	return 0;

}
