#include"FigureFactory.h"

std::vector<FIGURE*> FIGURE::sampleObject; // Khởi động
void FIGURE::addSample(FIGURE* sample)
{
	if (sample == NULL)
		return;
	int length = sampleObject.size();
	FIGURE* temp = NULL;
	while (--length >= 0)
	{
		temp = sampleObject[length];
		if (strcmp(temp->getClassName(), sample->getClassName()) == 0)
			break;
	}
	if (length < 0)
		sampleObject.push_back(sample);
}
FIGURE* FIGURE::creatObject(const char *className)
{
	if (className == NULL)
		return NULL;
	int length = sampleObject.size();
	FIGURE* temp;
	while (--length >= 0)
	{
		temp = sampleObject[length];
		if (temp == NULL)
			continue;
		if (strcmp(temp->getClassName(), className) == 0)
			break;
	}
	if (length >= 0)
		return sampleObject[length]->clone();
	return NULL;
}

RECTANGLE::RECTANGLE(const float &height, const float &width)
{
	m_height = height;
	m_width = width;
	addSample(this);
}
const char* RECTANGLE::getClassName()
{
	return "RECTANGLE";
}
FIGURE* RECTANGLE::clone()
{
	return (new RECTANGLE(m_height, m_width));
}
float RECTANGLE::area()
{
	return (m_height * m_width);
}

SQUARE::SQUARE(const float &size) : RECTANGLE(size, size)
{
	addSample(this);
}
const char* SQUARE::getClassName()
{
	return "SQUARE";
}
FIGURE* SQUARE::clone()
{
	return (new SQUARE(m_height));
}

ELLIPSE::ELLIPSE(const float &radiusA, const float &radiusB)
{
	m_radiusA = radiusA;
	m_radiusB = radiusB;
	addSample(this);
}
const char* ELLIPSE::getClassName()
{
	return "ELLIPSE";
}
FIGURE* ELLIPSE::clone()
{
	return new ELLIPSE(m_radiusA, m_radiusB);
}
float ELLIPSE::area()
{
	return (PI * m_radiusA * m_radiusB);
}

CIRCLE::CIRCLE(const float &radius) : ELLIPSE(radius, radius)
{
	addSample(this);
}
const char* CIRCLE::getClassName()
{
	return "CIRCLE";
}
FIGURE* CIRCLE::clone()
{
	return (new CIRCLE(m_radiusA));
}

float sumAreaFigure(FIGURE *F[], const int &nF)
{
	float sum = 0;
	for (int i = 0; i < nF; i++)
	{
		sum += F[i]->area();
	}
	return sum;
}
