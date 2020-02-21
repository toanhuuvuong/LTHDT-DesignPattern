#ifndef __VIRTUAL_MONEY_FACTORY_H__
#define __VIRTUAL_MONEY_FACTORY_H__

#include<iostream>

// Factory
class VIRTUAL_MONEY
{
public:
	static VIRTUAL_MONEY* getObject(const char* classNameType);
	virtual float getValue() const = 0;
};
// ProductOne
class BITCOIN : public VIRTUAL_MONEY
{
public:
	virtual float getValue() const { return 4534.13; }
};
// ProductTwo
class ETHEREUM : public VIRTUAL_MONEY
{
public:
	virtual float getValue() const { return 134.90; }
};
// Dùng factory giải quyết bài toán
float toUSD(VIRTUAL_MONEY* VF[], const int &nVF);

#endif