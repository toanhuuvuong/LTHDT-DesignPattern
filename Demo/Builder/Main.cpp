#include"GameScheduleBuilder.h"
#include<conio.h>

int main()
{
	// VD1 ----------------------------------------------------------------------------
	GAME_SCHEDULE_BUILDER* builder = new SPORT_GAME_SCHEDULE_BUILDER();

	DIRECTOR director;
	director.setBuilder(builder);
	director.construct();

	builder->getResult()->display();
	//// Bài toán ----------------------------------------------------------------------------
	//HOUSE_BUILDER* builder = new LAVISH_HOUSE_BUILDER();

	//DIRECTOR director;
	//director.setBuilder(builder);
	//director.construct();
	//std::cout << builder->getResult()->getDescription() << std::endl;

	//builder = new NORMAL_HOUSE_BUILDER();

	//director.setBuilder(builder);
	//director.construct();
	//std::cout << builder->getResult()->getDescription() << std::endl;


	_getch();
	return 0;
}