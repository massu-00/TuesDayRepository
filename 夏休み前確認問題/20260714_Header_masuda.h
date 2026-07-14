#pragma once
const int Winpoint = 3;
const int Drawpoint = 1;
const int Card = 10;
const int Maxmatch = 7;
const int SelectnumMin = 0;
const int SelectnumMax = 10;

int Dealcards();
void InputCheck(int &player);
int Judge(int player, int enemy);
