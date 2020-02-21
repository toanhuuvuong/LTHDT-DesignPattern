#include"VirtualMoneyFactory.h"
#include"FigureFactory.h"
#include"InjectionMoldFactory.h"
#include<conio.h>

int main()
{
	// VD1 ----------------------------------------------------------------------
	CLIENT *m_client = new CLIENT();
	INJECTION_MOLD* m_injecton_mold = m_client->get_injection_mold();
	m_injecton_mold->injection();
	// VD2 ----------------------------------------------------------------------
	VIRTUAL_MONEY* VF[] = { VIRTUAL_MONEY::getObject("BITCOIN"),
		VIRTUAL_MONEY::getObject("BITCOIN"),
		VIRTUAL_MONEY::getObject("ETHEREUM"),
		VIRTUAL_MONEY::getObject("BITCOIN"),
		VIRTUAL_MONEY::getObject("ETHEREUM") };
	int nVF = sizeof(VF) / sizeof(*VF);

	std::cout << toUSD(VF, nVF);

	//// Bài toán ----------------------------------------------------------------------
	//FIGURE* F[] = {new RECTANGLE(3, 4), 
	//	new SQUARE(4.2), 
	//	new RECTANGLE(3, 4), 
	//	new ELLIPSE(3.9, 9.4), 
	//	new CIRCLE(4.5), 
	//	new RECTANGLE(3, 4), 
	//	new SQUARE(8.4),
	//	new CIRCLE(4),
	//	new CIRCLE(4) };
	//int nF = sizeof(F) / sizeof(*F);

	//std::cout << sumAreaFigure(F, nF) << std::endl;

	_getch();
	return 0;
}