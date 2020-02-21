#include"StampingEquipmentAbstractFactory.h"
#include<conio.h>

int main()
{
	//// Bài toán ---------------------------------------------------------
	//FACTORY* factory = new SIMPLE_FIGURE_FACTORY();

	//FIGURE* F[3] = { factory->creatStraightFigure(), 
	//	factory->creatCurvedFigure(), 
	//	factory->creatStraightFigure() };

	//for (int i = 0; i < 3; i++)
	//	F[i]->draw();
	// VD1 -----------------------------------------------------------------
	FACTORY *factory = new STAMPING_WHEELS;
	EQUIPMENT_CAR* equipment[] = { factory->stampModel1(),
		factory->stampModel2(),
		factory->stampModel3() };
	int nEquipment = sizeof(equipment) / sizeof(*equipment);
	for (int i = 0; i < nEquipment; i++)
		equipment[i]->stamp();

	_getch();
	return 0;
}