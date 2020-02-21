#ifndef __STAMPING_EQUIPMENT_ABSTRACT_FACTORY_H__
#define __STAMPING_EQUIPMENT_ABSTRACT_FACTORY_H__

#include <iostream>
#include <string>

// Abstract Product
class EQUIPMENT_CAR
{
public:
	virtual void stamp() = 0;
};
class MODEL_1_WHEELS : public EQUIPMENT_CAR
{
public:
	void stamp()
	{
		std::cout << " Stamping model 1 wheel" << std::endl;
	}
};
class MODEL_2_WHEELS : public EQUIPMENT_CAR
{
public:
	void stamp()
	{
		std::cout << " Stamping model 2 wheel" << std::endl;
	}
};
class MODEL_3_WHEELS : public EQUIPMENT_CAR
{
public:
	void stamp()
	{
		std::cout << " Stamping model 3 wheel" << std::endl;
	}
};
class MODEL_1_HOOD : public EQUIPMENT_CAR
{
public:
	void stamp()
	{
		std::cout << " Stamping model 1 hood" << std::endl;
	}
};
class MODEL_2_HOOD : public EQUIPMENT_CAR
{
public:
	void stamp()
	{
		std::cout << " Stamping model 2 hood" << std::endl;
	}
};
class MODEL_3_HOOD : public EQUIPMENT_CAR
{
public:
	void stamp()
	{
		std::cout << " Stamping model 3 hood" << std::endl;
	}
};
class MODEL_1_DOOR : public EQUIPMENT_CAR
{
public:
	void stamp()
	{
		std::cout << " Stamping model 1 door" << std::endl;
	}
};
class MODEL_2_DOOR : public EQUIPMENT_CAR
{
public:
	void stamp()
	{
		std::cout << " Stamping model 2 door" << std::endl;
	}
};
class MODEL_3_DOOR : public EQUIPMENT_CAR
{
public:
	void stamp()
	{
		std::cout << " Stamping model 3 door" << std::endl;
	}
};
//--------------------------------------------------------------------------------------------
// Abstract Factory
class FACTORY
{
public:
	virtual EQUIPMENT_CAR* stampModel1() = 0;
	virtual EQUIPMENT_CAR* stampModel2() = 0;
	virtual EQUIPMENT_CAR* stampModel3() = 0;
};
class STAMPING_WHEELS : public FACTORY
{
public:
	EQUIPMENT_CAR* stampModel1()
	{
		return new MODEL_1_WHEELS;
	}
	EQUIPMENT_CAR* stampModel2()
	{
		return new MODEL_2_WHEELS;
	}
	EQUIPMENT_CAR* stampModel3()
	{
		return new MODEL_3_WHEELS;
	}
};
class STAMPING_HOOD : public FACTORY
{
public:
	EQUIPMENT_CAR* stampModel1()
	{
		return new MODEL_1_HOOD;
	}
	EQUIPMENT_CAR* stampModel2()
	{
		return new MODEL_2_HOOD;
	}
	EQUIPMENT_CAR* stampModel3()
	{
		return new MODEL_3_HOOD;
	}
};
class STAMPING_DOOR : public FACTORY
{
public:
	EQUIPMENT_CAR* stampModel1()
	{
		return new MODEL_1_DOOR;
	}
	EQUIPMENT_CAR* stampModel2()
	{
		return new MODEL_2_DOOR;
	}
	EQUIPMENT_CAR* stampModel3()
	{
		return new MODEL_3_DOOR;
	}
};

#endif