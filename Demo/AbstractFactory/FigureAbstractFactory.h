#ifndef __FIGURE_ABSTRACT_FACTORY_H__
#define __FIGURE_ABSTRACT_FACTORY_H__

#include<iostream>

// Abstract Product
class FIGURE
{
protected:
	static unsigned int m_count;
	unsigned int m_id;
public:
	FIGURE() { m_id = m_count++; }

	virtual void draw() = 0;
};
unsigned int FIGURE::m_count = 0;
//------------------------------------------
class RECTANGLE : public FIGURE
{
public:
	virtual void draw()
	{
		std::cout << m_id << ": Rectangle" << std::endl;
	}
};
class SQUARE : public RECTANGLE
{
public:
	virtual void draw()
	{
		std::cout << m_id << ": Square" << std::endl;
	}
};
class ELLIPSE : public FIGURE
{
public:
	virtual void draw()
	{
		std::cout << m_id << ": Ellipse" << std::endl;
	}
};
class CIRCLE : public ELLIPSE
{
public:
	virtual void draw()
	{
		std::cout << m_id << ": Circle" << std::endl;
	}
};
//-------------------------------------------
// Abstract Factory
class FACTORY
{
public:
	virtual FIGURE* creatStraightFigure() = 0; // creatProductOne
	virtual FIGURE* creatCurvedFigure() = 0; // creatProductTwo
};
// Factory One
class SIMPLE_FIGURE_FACTORY : public FACTORY // PlatformOne
{
public:
	virtual FIGURE* creatStraightFigure()
	{
		// ProductOnePlatformOne
		return new SQUARE();
	}
	virtual FIGURE* creatCurvedFigure()
	{
		// ProductTwoPlatformOne
		return new CIRCLE();
	}
};
// Factory Two
class ROBUST_FIGURE_FACTORY : public FACTORY // PlatformTwo
{
public:
	virtual FIGURE* creatStraightFigure()
	{
		// ProductOnePlatformTwo
		return new RECTANGLE();
	}
	virtual FIGURE* creatCurvedFigure()
	{
		// ProductTwoPlatformTwo
		return new ELLIPSE();
	}
};
#endif