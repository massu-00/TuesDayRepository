#pragma once
class Player
{
private:
	int PlayerHand = 0;// 0:グー 1:チョキ 2:パー	

public:
	void SelectHand();
	int GetHand();
};

