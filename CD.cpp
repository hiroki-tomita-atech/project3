#include "Player.h"
#include "Map.h"
#include <algorithm> // std::maxを使用するため
#define NOMINMAX
#include "CD.h"

// void CD::CD1(float x, float y)
void CD::CD1(Player *player)
{
	float x = player->x;
	float y = player->y;

	// ブロックの当たり判定
	for (int j = 0; j < NUM_MAP_Y; j++)
	{
		for (int i = 0; i < NUM_MAP_X; i++)
		{
			int no = data[i + j * NUM_MAP_X];
			if (no >= 10 && no < 20)
			{
				// プレイヤーキャラの壁当たり判定
				if (CheckHit(i * SIZE_MAP_X, j * SIZE_MAP_Y, SIZE_MAP_X, SIZE_MAP_Y,
					x, y, CHARA_WIDTH, CHARA_HEIGHT))
				{
					// 上下から当たっている
					if (y != old_y)
					{
						int _y = std::max(y, old_y);
						_y /= SIZE_MAP_Y;
						_y *= SIZE_MAP_Y;
						y = _y;
						// y や yadd のsetterを呼び出し、値を更新する
						player->setY(y);
						yadd = 0.0f;
						player->setYAdd(yadd);
					}
					else
						// 左右から当たっている
						if (x != old_x)
						{
							int _x = std::max(x, old_x);
							_x /= SIZE_MAP_X;
							_x *= SIZE_MAP_X;
							x = _x;
							player->setX(x);
						}
				}
				//// 敵キャラの壁当たり判定
				//if (CheckHit(i * SIZE_MAP_X, j * SIZE_MAP_Y, SIZE_MAP_X, SIZE_MAP_Y,
				//	ex, ey, CHARA_WIDTH, CHARA_HEIGHT))
				//{
				//	// 上下から当たっている
				//	if (ey != old_ey)
				//	{
				//		int _ey = std::max(ey, old_ey);
				//		_ey /= SIZE_MAP_Y;
				//		_ey *= SIZE_MAP_Y;
				//		ey = _ey;
				//		eyadd = 0.0f;
				//	}
				//	else
				//		// 左右から当たっている
				//		if (ex != old_ex)
				//		{
				//			int _ex = std::max(ex, old_ex);
				//			_ex /= SIZE_MAP_X;
				//			_ex *= SIZE_MAP_X;
				//			ex = _ex;
				//		}
				//}
			}
		}
	}

}
