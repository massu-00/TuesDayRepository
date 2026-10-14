#pragma once
#include"Character.h"

//Wizard クラスを作成する。
//Character クラスを継承する。
//Attack() を呼び出すと「魔法で攻撃する」と表示する。
//Character* 型のポインタから、魔法使いの攻撃を実行する。

class Wizard:public Character
{
public:
	Wizard(std::string name);
	void Attack();
};

