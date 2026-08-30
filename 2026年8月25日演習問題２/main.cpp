#include<iostream>
#include"Calculator.h"
using namespace std;
Calculator calculator;

int main()
{
	while (true)
	{
		int num[2];//数字を入力
		int answer = 0;//計算結果
		int Select = 0;//計算方法選択

		cout << "数字を入力してください" << endl;

		for (int i = 0; i < 2; i++)
		{
			cout << i + 1 << "つ目　";
			cin >> num[i];
		}
		cout<<"\n０：足し算　１：引き算　２：掛け算　３：割り算\n"
	        << "計算方法を選んでください　";
		cin >> Select;

		switch (Select)
		{
		case 0:
		{
			answer = calculator.add(num[0],num[1]);
			break;
		}
		case 1:
		{
			answer = calculator.subtract(num[0], num[1]);
			break;
		}
		case 2:
		{
			answer = calculator.multiply(num[0], num[1]);
			break;
		}
		case 3:
		{
			answer = calculator.divide(num[0], num[1]);
			break;
		}
		}

		cout << "\n計算結果は" << answer << "です\n"
			<< "\n計算終了しますか？\n"
			<< "０：はい　　その他の数字：いいえ\n"
			<< "選択：";

		cin >> Select;
		cout << "\n";
		if (Select == 0)
		{
			break;//計算終了
		}
	}
}