#ifndef __FIGURE_FACTORY_H__
#define __FIGURE_FACTORY_H__

#include<iostream>
#include<vector>

#define PI 3.14159

// Factory
class FIGURE
{
private:
	static std::vector<FIGURE*> sampleObject;
protected:
	static void addSample(FIGURE* sample);
public:
	virtual const char* getClassName() = 0;
	virtual FIGURE* clone() = 0;

	virtual float area() = 0;
	static FIGURE* creatObject(const char *className);
};
// Product One
class RECTANGLE : public FIGURE
{
protected:
	float m_height, m_width;
public:
	RECTANGLE(const float &height, const float &width);
	virtual const char* getClassName();
	virtual FIGURE* clone();

	virtual float area();
};
// Product Two
class SQUARE : public RECTANGLE
{
public:
	SQUARE(const float &size);

	virtual const char* getClassName();
	virtual FIGURE* clone();
};
// Product Three
class ELLIPSE : public FIGURE
{
protected:
	float m_radiusA, m_radiusB;
public:
	ELLIPSE(const float &radiusA, const float &radiusB);

	virtual float area();
	virtual const char* getClassName();
	virtual FIGURE* clone();
};
// Product Four
class CIRCLE : public ELLIPSE
{
public:
	CIRCLE(const float &radius);

	virtual const char* getClassName();
	virtual FIGURE* clone();
};
// Dùng factory giải quyết bài toán
float sumAreaFigure(FIGURE *F[], const int &nF);

#endif