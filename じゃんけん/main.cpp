#include<iostream>
#include"Player.h"
#include"CPU.h"
#include"Judge.h"

using namespace std;

int main()
{
	Player player;
	CPU cpu;
	Judge judge;

	Player* playerPtr = &player;
	CPU* cpuPtr = &cpu;

	player.SelectHand();
	cpu.SelectHand();
	judge.JudgeResult(playerPtr, cpuPtr);
}