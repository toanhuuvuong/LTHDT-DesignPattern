#ifndef __INJECTION_MOLD_FACTORY_H__
#define __INJECTION_MOLD_FACTORY_H__

#include <iostream>
#include <string>

class INJECTION_MOLD
{
public:
	virtual void injection() = 0;
	static INJECTION_MOLD* getObject(const std::string &type);
};
class TOY_DUCK_MOLD :public INJECTION_MOLD
{
public:
	virtual void injection()
	{
		std::cout << "Creat toy duck" << std::endl;
	}
};
class TOY_CAR_MOLD :public INJECTION_MOLD
{
public:
	virtual void injection()
	{
		std::cout << "Creat toy car" << std::endl;
	}
};
INJECTION_MOLD* INJECTION_MOLD::getObject(const std::string &type)
{
	if (type == "TOY_DUCK")
		return new TOY_DUCK_MOLD;
	else if (type == "TOY_CAR")
		return new TOY_CAR_MOLD;
	else
		return NULL;
}
class CLIENT
{
private:
	INJECTION_MOLD *m_injection;
public:
	CLIENT()
	{
		m_injection = INJECTION_MOLD::getObject("TOY_CAR");
	}
	~CLIENT()
	{
		if (m_injection)
			delete[] m_injection;
	}
	INJECTION_MOLD* get_injection_mold()
	{
		return m_injection;
	}
};

#endif