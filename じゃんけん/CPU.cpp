#include "CPU.h"
#include <iostream>

using namespace std;

void CPU::SelectHand()
{
	CPUHand = rand() % 3; // 0:グー 1:チョキ 2:パー
	cout << "CPUの手は: " << CPUHand << endl;
}

int CPU::GetHand()
{
	return CPUHand;
}