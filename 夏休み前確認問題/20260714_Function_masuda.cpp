#include<iostream>
#include"20260714_Header_masuda.h"
using namespace std;

int Dealcards()
{
	int num = 0;
	num = rand() % 51;
	return num;
}

void InputCheck(int &player)
{
	while (true)
	{
		cin >> player;
		if (player < SelectnumMin || SelectnumMax < player)
		{
			cout << "“ü—Í‚ÉŒë‚è‚ª‚ ‚è‚Ü‚·" << endl;
		}
		else
		{
			break;
		}
	}
}

int Judge(int player, int enemy)
{
	if (player > enemy)
	{
		cout << "‚o‚k‚`‚x‚d‚q‚v‚h‚m" << endl;
		return 1;
	}
	else if (player < enemy)
	{
		cout << "‚b‚o‚t‚v‚‰‚" << endl;
		return 0;
	}
	else
	{
		cout << "‚c‚’‚‚—" << endl;
		return 2;
	}
}