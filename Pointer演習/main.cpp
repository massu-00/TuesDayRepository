#include<iostream>

using namespace std;

void Damage(int* Health)
{
	int damage = 20;
	*Health -= damage;
}

void Heal(int* Health)
{
	int heal = 30;
	*Health += heal;
}

int main()
{
	int hp = 100;

	Damage(&hp);
	Heal(&hp);
	cout << hp << endl;
}