#include "DxLib.h"
#include "Map.h"

// ƒ}ƒbƒvˆ—
void Map::Init()
{
	loadData();
}
//void Map::Update()
//{
//}
void Map::Draw()
{
	for (int j = 0; j < NUM_MAP_Y; j++)
	{
		for (int i = 0; i < NUM_MAP_X; i++)
		{
			int no = data[i + j * NUM_MAP_X];
			if (no != 0)
			{
				DrawGraph(i * SIZE_MAP_X, j * SIZE_MAP_Y, chip[no], FALSE);
			}
		}
	}

}
//void Map::Exit()
//{
//}
void Map::loadData()
{
	LoadDivGraph("demo/mapchip.png", NUM_CHIP_ALL,
		NUM_CHIP_X, NUM_CHIP_Y,
		SIZE_MAP_X, SIZE_MAP_Y,
		chip);
}