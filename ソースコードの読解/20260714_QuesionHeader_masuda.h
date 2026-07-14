#pragma once

const int PITCHING_MIN = 0;//最低値
const int PITCHING_MAX = 3;//最高値
const int PROBABILITY = 4;//確率（4分の１）

const int STRIKE_COUNT = 3;//ストライクカウント
const int BALL_COUNT = 4;//ボールカウント
const int OUT_COUNT = 3;//アウトカウント
const int HIT_COUNT = 4;//ヒットカウント

enum PitchType//列挙
{
	Straight,
	Curve,
	Slider,
	Sinker
};
//プロトタイプ宣言
void PitchingType(int pitching);

void Result(int out);

int InputCheck(int min, int max);

