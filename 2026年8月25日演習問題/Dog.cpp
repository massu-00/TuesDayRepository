#include<iostream>
#include "Dog.h"

using namespace std;

void Dog::ShowProfile()
{
	cout << "名前を入力するのじゃ　";
	cin >> Name;
	cout << "ほう、" << Name << "というんだな？" << endl;
}