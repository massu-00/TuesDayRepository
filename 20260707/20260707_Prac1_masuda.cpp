#include<iostream>
using namespace std;

void Showodd(int num[], int index);
void Showeven(int num[], int index);

int main()
{
	int num[10] = {};
	cout << "”Žš‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢" << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> num[i];
	}
	Showeven(num,10);
	Showodd(num,10);
}

void Showeven(int num[], int index)
{
	cout << "‹ô”:" << endl;

	for (int i = 0; i < index; i++)
	{
		if (num[i] % 2 == 0)
		{
			cout << num[i] << "A" << endl;
		}
	}
}

void Showodd(int num[], int index)
{
	cout << "Šï”:" << endl;
	for (int i = 0; i < index; i++)
	{
		if (num[i] % 2 == 1)
		{
			cout << num[i] << "A" << endl;
		}
	}
}