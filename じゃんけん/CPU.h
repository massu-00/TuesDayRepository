#pragma once
class CPU
{
private:
	int CPUHand = 0;// 0:グー 1:チョキ 2:パー

public:
	void SelectHand();
	int GetHand();	
};

