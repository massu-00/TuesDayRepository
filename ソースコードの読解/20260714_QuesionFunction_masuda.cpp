#include<iostream>
#include<cstdlib>
#include<ctime>
#include"20260714_QuesionHeader_masuda.h"
using namespace std;

void PitchingType(int pitching)//球種の画面表記
{
    switch (pitching)
    {
    case Straight:
        cout << "ストレート" << endl;
        break;

    case Curve:
        cout << "カーブ" << endl;
        break;

    case Slider:
        cout << "スライダー" << endl;
        break;

    case Sinker:
        cout << "シンカー" << endl;
        break;
    }
}

void Result(int out)//結果を表示
{
    if (out >= OUT_COUNT)
    {
        cout << "PLAYER WINNER!!" << endl;
    }
    else
    {
        cout << "CPU WINNER!!" << endl;
    }
}

int InputCheck(int min, int max)//プレイヤーの入力チェック
{
    int player;

    while (true)
    {
        cin >> player;

        if (player < PITCHING_MIN || player > PITCHING_MAX)
        {
            cout << "入力に誤りがあります。再入力してください。" << endl;
        }
        else
        {
            break;
        }
    }

    return player;
}