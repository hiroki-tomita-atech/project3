#include "DxLib.h"
#include "Player.h"
#include "Map.h"
#include "CD.h"

// クラス
Player player;
Map map;
CD playercd;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	//======================================================
	// ウインドウ設定とDXライブラリの初期化
	//======================================================
	const int SCREEN_WIDTH = 640;		//< スクリーン横の大きさ
	const int SCREEN_HEIGHT = 480;		//< スクリーン縦の大きさ

	// Windowsモードにする
	ChangeWindowMode(TRUE);
	// 画面サイズの設定
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);
	// DXライブラリ初期化
	if (DxLib_Init() == -1)
	{
		//初期化に失敗
		return -1;
	}
	// ダブルバッファモード
	SetDrawScreen(DX_SCREEN_BACK);
	//======================================================
	// ゲーム部分
	//======================================================
	//------------------------------------------------------
	// ゲーム初期化部分
	//------------------------------------------------------

	//マップの初期処理 
	map.Init();
	
	// プレイヤーの初期処理
	player.Init();

	player.x = (SCREEN_WIDTH - player.GetWidth()) / 2;    //< 画面の中心
	player.y = (SCREEN_HEIGHT - player.GetHeight()) / 2;	//< 画面の中心


	//------------------------------------------------------
	// メインループ部分
	//------------------------------------------------------
	while (ProcessMessage() == 0)
	{
		//裏画面消す
		ClearDrawScreen();

		// マップ
		// map.Update();
		map.Draw();

		// プレイヤー処理
		player.Update();

		// 当たり判定
		// ポインタ渡しする
		playercd.CD1(&player);

		// プレイヤー描画
		player.Draw();

		//裏画面を表画面を入れ替える
		ScreenFlip();
	}

	// プレイヤー終了
	player.Exit();

	// map.Exit();

	//======================================================
	// DXライブラリ終了とプログラム終了
	//======================================================
	DxLib_End();
	return 0;
}