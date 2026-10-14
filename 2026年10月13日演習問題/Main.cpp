#include<iostream>
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"
#include "Wizard.h"
#include "BattleManager.h"
int main(void)
{
	//コンストラクタ
	Player player("勇者マヒマヒ");
	Wizard wizard("魔法使い由地");
	Enemy enemy("モブAマッスー");
	Boss boss("魔王玲央");
	BattleManager manager;

	manager.StartBattle(&player);
	manager.StartBattle(&wizard);
	manager.StartBattle(&enemy);
	manager.StartBattle(&boss);

	return 0;
}
