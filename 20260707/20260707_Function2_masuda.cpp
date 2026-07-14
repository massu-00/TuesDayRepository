#include<iostream>
#include"20260707_Header2_masuda.h"
using namespace std;

void Game()
{
	//変数宣言
	int player[3], NPC[3];
	int ans[3], NPCans[3];//答えを書く配列

	int playerHITcount = 0, NPCHITcount = 0;//予想が的中した回数を保存する変数（３になるとNPCのターンを飛ばして強制終了する）
	int NPCansstock[3];//的中した数字と場所を保存する変数
	int slot[3][10] = { {10}, {10} , {10} };//NPCが数字を絞るための配列

	NUM PLAYER;
	NUM ENEMY;

	cout << "NPCと数字当てゲームをします\n"
		<< "０～９のランダムに生成された数字を三つ(重複なし)をお互いに交互に当てていきます\n"
		<< "Hit:あっている　Blow:間違っている\n"
		<< "先行はあなたです" << endl;
	
	//数字を重複せずにランダム入力
	for (int i = 0; i < 3; i++)
	{
		while (true)
		{
			Random(player[i]);
			if (player[i] != PLAYER.selectnum[player[i]])
			{
				PLAYER.selectnum[player[i]] = player[i];//一度決まった数字を保存して被らないようにする
				break;
			}

		}
	}
	for (int i = 0; i < 3; i++)
	{
		while (true)
		{
			Random(NPC[i]);
			if (NPC[i] != ENEMY.selectnum[NPC[i]])
			{
				ENEMY.selectnum[NPC[i]] = NPC[i];//プレイヤーと同様
				break;
			}
		}
	}


//ゲーム開始
	while (playerHITcount < 3 && NPCHITcount < 3)
	{
		cout << "\nあなたの数字:" << player[0] << player[1] << player[2] << "\n"
			<< "あなたの番です" << endl;
		
		//３つの数字の予想
		for (int i = 0; i < 3; i++)
		{
			cout << i + 1 << "個目の数字:";
			InputCheck(ans[i]);
		}
		
		//判定
		cout << "\n";
		for (int i = 0; i < 3; i++)
		{
			playerHITcount += Judge(ans[i] ,NPC[i]);
		}
		if (playerHITcount != 3)
		{
			playerHITcount = 0;
		}
		

		//NPCの予想
		if (playerHITcount != 3)
		{
			cout << "\nＮＰＣの番です" << endl;

			for (int i = 0; i < 3; i++)
			{
				NPCans[i] = rand() % 10;
				while (NPCans[i] == slot[i][NPCans[i]])//一度間違えた数字なら予想したことがない数字になるまでランダム生成する
				{
					NPCans[i] = rand() % 10;
				}
				if (player[i] == NPCansstock[i] && NPCans[i] != NPCansstock[i])//一度当てた場所は同じ数字を言い続けるようにする
				{
					NPCans[i] = NPCansstock[i];
				}
			}
			cout << "NPCの予想した数字:" << NPCans[0] << NPCans[1] << NPCans[2] << endl;

			//判定
			cout << "\n";
			for (int i = 0; i < 3; i++)
			{
				NPCHITcount += Judge(NPCans[i], player[i]);
			}

			//判定
			cout << "\n";
			for (int i = 0; i < 3; i++)
			{
				if (NPCans[i] == player[i])
				{
					NPCHITcount++;
					NPCansstock[i] = NPCans[i];//正解した数字の場所を覚える
				}
				else
				{
					for (int j = 0; j < 3; j++)
					{
						slot[j][NPCans[j]] = NPCans[i];//間違えた数字の場所を覚える
					}

				}
			}
			if (NPCHITcount != 3)
			{
				NPCHITcount = 0;
			}
		}
	}

	//勝敗
	cout << "\n";
	if (playerHITcount == 3)
	{
		cout << "あなたの勝ちです\n"
			<< "NPCの数字:" << NPC[0] << NPC[1] << NPC[2] << endl;
	}
	else
	{
		cout << "NPCの勝ちです" << endl;
	}
}

void Random(int &num)
{
	srand((unsigned int)time(NULL));
	num = rand() % 10;
}

void InputCheck(int &num)
{
	
	while (true)
	{
		cin >> num;
		if (num < 0 || 9 < num)
		{
			cout << "入力に誤りがあります" << endl;
		}
		else
		{
			break;
		}
	}
}

int Judge(int num,int num2)
{
//判定
	if (num == num2)
	{
		cout << "HIT" << endl;
		return 1;
	}
	else
	{
		cout << "Blow" << endl;
		return 0;
	}
		
}