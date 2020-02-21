#include"VirtualMoneyFactory.h"

VIRTUAL_MONEY* VIRTUAL_MONEY::getObject(const char* classNameType)
{
	if (classNameType == "BITCOIN")
		return new BITCOIN();
	else if (classNameType == "ETHEREUM")
		return new ETHEREUM();
	else
		return NULL;
}
float toUSD(VIRTUAL_MONEY* VF[], const int &nVF)
{
	float sum = 0;
	for (int i = 0; i < nVF; i++)
		sum += VF[i]->getValue();
	return sum;
}