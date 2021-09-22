#include "Player.h"
#include "Map.h"
#include <algorithm> // std::max���g�p���邽��
#define NOMINMAX
#include "CD.h"

// void CD::CD1(float x, float y)
void CD::CD1(Player *player)
{
	float x = player->x;
	float y = player->y;

	// �u���b�N�̓����蔻��
	for (int j = 0; j < NUM_MAP_Y; j++)
	{
		for (int i = 0; i < NUM_MAP_X; i++)
		{
			int no = data[i + j * NUM_MAP_X];
			if (no >= 10 && no < 20)
			{
				// �v���C���[�L�����̕Ǔ����蔻��
				if (CheckHit(i * SIZE_MAP_X, j * SIZE_MAP_Y, SIZE_MAP_X, SIZE_MAP_Y,
					x, y, CHARA_WIDTH, CHARA_HEIGHT))
				{
					// �㉺���瓖�����Ă���
					if (y != old_y)
					{
						int _y = std::max(y, old_y);
						_y /= SIZE_MAP_Y;
						_y *= SIZE_MAP_Y;
						y = _y;
						player->setY(y);
						yadd = 0.0f;
						player->setYAdd(yadd);
					}
					else
						// ���E���瓖�����Ă���
						if (x != old_x)
						{
							int _x = std::max(x, old_x);
							_x /= SIZE_MAP_X;
							_x *= SIZE_MAP_X;
							x = _x;
							player->setX(x);
						}
				}
				//// �G�L�����̕Ǔ����蔻��
				//if (CheckHit(i * SIZE_MAP_X, j * SIZE_MAP_Y, SIZE_MAP_X, SIZE_MAP_Y,
				//	ex, ey, CHARA_WIDTH, CHARA_HEIGHT))
				//{
				//	// �㉺���瓖�����Ă���
				//	if (ey != old_ey)
				//	{
				//		int _ey = std::max(ey, old_ey);
				//		_ey /= SIZE_MAP_Y;
				//		_ey *= SIZE_MAP_Y;
				//		ey = _ey;
				//		eyadd = 0.0f;
				//	}
				//	else
				//		// ���E���瓖�����Ă���
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
