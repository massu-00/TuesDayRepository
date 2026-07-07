#include<iostream>
using namespace std;

void Game()
{
	//変数宣言
	int player[3], NPC[3];
	int ans[3], NPCans[3];//答えを書く配列

	int selectnum[3];//初期設定の数字が被らないようにする配列

	int playerHITcount = 0, NPCHITcount = 0;//予想が的中した回数を保存する変数（３になるとNPCのターンを飛ばして強制終了する）
	int NPCansstock[3];//的中した数字と場所を保存する変数
	int slot[3][10] = { {10}, {10} , {10} };//NPCが数字を絞るための配列

	cout << "NPCと数字当てゲームをします\n"
		<< "０～９のランダムに生成された数字を三つ(重複有り)をお互いに交互に当てていきます\n"
		<< "Hit:あっている　Blow:間違っている\n"
		<< "先行はあなたです" << endl;
	for (int i = 0; i < 3; i++)
	{
		Random(&player[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		Random(&NPC[i]);
	}
}

void Random(int num[])
{
//自分の数字をランダム入力
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 3; i++)
	{
		while (selectnum[i] == num[0] || selectnum[i] == num[1] || selectnum[i] == num[2])
		{
			selectnum[i] = rand() % 10;
		}
		player[i] = selectnum[i];
	}
}
int main()
{

	//ゲーム開始
	while (playerHITcount < 3 && NPCHITcount < 3)
	{
		cout << "\nあなたの数字:" << player[0] << player[1] << player[2] << "\n"
			<< "あなたの番です" << endl;

		//３つの数字の予想
		for (int i = 0; i < 3; i++)
		{
			cout << i + 1 << "個目の数字:";
			cin >> ans[i];
			while (ans[i] < 0 || 9 < ans[i])
			{
				cout << "入力に誤りがあります" << endl;
				cout << i + 1 << "個目の数字:";
				cin >> ans[i];
			}
		}

		//判定
		cout << "\n";
		for (int i = 0; i < 3; i++)
		{
			if (ans[i] == NPC[i])
			{
				cout << i + 1 << "個目:HIT" << endl;
				playerHITcount++;
			}
			else
			{
				cout << i + 1 << "個目:Blow" << endl;
			}
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
				if (NPCans[i] == player[i])
				{
					cout << i + 1 << "個目:HIT" << endl;
					NPCHITcount++;
					NPCansstock[i] = NPCans[i];//正解した数字の場所を覚える
				}
				else
				{
					cout << i + 1 << "個目:Blow" << endl;
					for (int j = 0; j < 3; j++)
					{
						slot[j][NPCans[j]] = NPCans[i];
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
//松