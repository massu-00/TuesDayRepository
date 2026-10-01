#include "Player.h"
#include <iostream>
using namespace std;

void Player::SelectHand()
{
	cout << "あなたの手を選んでください(0:グー 1:チョキ 2:パー): ";
	while(true)
	{
		cin >> PlayerHand;
		if (PlayerHand >= 0 && PlayerHand <= 2)
		{
			break;
		}
		else
		{
			cout << "無効な入力です。もう一度選んでください(0:グー 1:チョキ 2:パー): ";
		}
	}
}

int Player::GetHand()
{
	return PlayerHand;
}