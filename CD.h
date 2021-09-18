#pragma once
#include"Map.h"
#include"Player.h"

class CD :public Map, public Player
{
public:
	void CD1();

	//
	// 当たり判定を行う関数
	// 
	// 緑のキャラ 左   x1
	// 　　　　　 上   y1
	// 　　　　　 横幅 w1
	// 　　　　　 縦幅 h1
	// 黄のキャラ 左   x2
	// 　　　　　 上   y2
	// 　　　　　 横幅 w2
	// 　　　　　 縦幅 h2
	//
	int CheckHit(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
	{
		int L1 = x1;      // 左
		int R1 = x1 + w1; // 右(左+横幅)
		int L2 = x2;      // 左
		int R2 = x2 + w2; // 右(左+横幅)

		if (R1 <= L2) return 0; //< 線上も当たらないことにする
		if (R2 <= L1) return 0; //< 線上も当たらないことにする

		int U1 = y1;      // 上
		int D1 = y1 + h1; // 下(上+縦幅)
		int U2 = y2;      // 上
		int D2 = y2 + h2; // 下(上+縦幅)

		if (D1 <= U2) return 0; //< 線上も当たらないことにする
		if (D2 <= U1) return 0; //< 線上も当たらないことにする

		// それ以外の場合は当たっている
		return 1;
	}

protected:
	const int CHARA_WIDTH = 32;
	const int CHARA_HEIGHT = 32;
	float old_x = x;
	float old_y = y;

};