#include "Judge.h"
#include <iostream>

using namespace std;

void Judge::JudgeResult(Player* playerPtr, CPU* cpuPtr)
{
	int playerHand = playerPtr->GetHand();
	int cpuHand = cpuPtr->GetHand();

	if (playerHand == cpuHand)
	{
		cout << "ˆø‚«•ª‚¯‚Å‚·B" << endl;
	}
	else if ((playerHand == 0 && cpuHand == 1) || (playerHand == 1 && cpuHand == 2) || (playerHand == 2 && cpuHand == 0))
	{
		cout << "‚ ‚È‚½‚ÌŸ‚¿‚Å‚·I" << endl;
	}
	else
	{
		cout << "CPU‚ÌŸ‚¿‚Å‚·B" << endl;
	}
}