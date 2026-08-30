#include <iostream>
#include"Calculator.h"

using namespace std;

int Calculator::add(int num1,int num2)
{
	int answer = 0;
	answer = num1 + num2;

	return answer;
}

int Calculator::subtract(int num1,int num2)
{
	int answer = 0;
	answer = num1 - num2;

	return answer;
}

int Calculator::multiply(int num1,int num2)
{
	int answer = 0;
	answer = num1 * num2;

	return answer;
}

int Calculator::divide(int num1,int num2)
{
	int answer = 0;
	answer = num1 / num2;

	return answer;
}
