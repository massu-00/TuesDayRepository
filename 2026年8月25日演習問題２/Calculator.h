#pragma once
class Calculator
{
public:

	int add(int num1, int num2);//足し算
	int subtract(int num1, int num2);//引き算
	int multiply(int num1, int num2);//掛け算
	int divide(int num1, int num2);//割り算(0で割るとエラーを吐く)
};