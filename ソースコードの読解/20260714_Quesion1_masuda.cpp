#include <iostream>
#include <cstdlib>
#include <ctime>
#include "20260714_QuesionHeader_masuda.h"
using namespace std;


//====================================
// メイン
//====================================
int main()
{
    //変数宣言
    int player;
    int cpu;
    int probability;

    int strike = 0;
    int ball = 0;
    int out = 0;
    int hit = 0;

    srand((unsigned int)time(nullptr));

    cout << "野球盤ゲームスタートです" << endl;
    cout << "プレイヤーはピッチャーとなり、この回を守り切ってください" << endl;

    do
    {
        cout << endl;
        cout << "投げる球を選んでください" << endl;
        cout << "0:ストレート" << endl;
        cout << "1:カーブ" << endl;
        cout << "2:スライダー" << endl;
        cout << "3:シンカー" << endl;

        player = InputCheck(PITCHING_MIN, PITCHING_MAX);//プレイヤーの入力チェック
        
        PitchingType(player);//球種の画面表記

        cpu = rand() % PROBABILITY;//cpuの数字のランダム生成

        probability = rand() % PROBABILITY;//打たれるかの確率

        //判定
        if (player != cpu)//値が違った場合
        {
            if (probability == 0)
            {
                cout << "ボール！" << endl;
                ball++;//カウント
            }
            else
            {
                cout << "ストライク！！" << endl;
                strike++;//カウント
            }
        }
        else//値が一緒だった場合
        {
            strike = 0;
            ball = 0;

            if (probability == 1)
            {
                cout << "OUT!!" << endl;
                out++;//カウント
            }
            else
            {
                cout << "HIT!!" << endl;
                hit++;//カウント
            }
        }

        //ストライクもしくはボールのカウントが一定値を超えた場合
        if (strike >= STRIKE_COUNT || ball >= BALL_COUNT)
        {
            if (strike >= STRIKE_COUNT)//超えた値がストライクだった場合
            {
                cout << "三振アウト！" << endl;
                out++;//カウント
            }
            else//超えた値がボールだった場合
            {
                cout << "フォアボール！" << endl;
                hit++;//カウント
            }
            //カウントの初期化
            strike = 0;
            ball = 0;
        }
        //画面表示プレイヤーにわかりやすく
        cout << endl;
        cout << "B : " << ball << endl;
        cout << "S : " << strike << endl;
        cout << "O : " << out << endl;
        cout << "Runner : " << hit << endl;

    } while (out < OUT_COUNT && hit < HIT_COUNT);//繰り返し

    Result(out);

    return 0;
}