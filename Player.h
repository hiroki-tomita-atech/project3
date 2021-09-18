#pragma once
class Player
{
	enum class DIR : int
	{
		// 使用する絵(sample007.png)の順番に合わせておく
		DOWN = 0,
		LEFT,
		RIGHT,
		UP,

		NUM,
	};

public:
	void Init();   //< 初期処理
	void Update(); //< 更新処理
	void Draw();   //< 描画処理
	void Exit();   //< 終了処理
	void CD();

	int SetDir(DIR dir) { act_dir = dir; } //< 方向設定
	int GetWidth() { return WIDTH; }	//< 横サイズ
	int GetHeight() { return HEIGHT; }  //< 縦サイズ

	float x, y;    //< 表示座標

protected:
	static const int ACT_DIR_SLIDE = 3;
	static const int ACT_DIR_NUM = 4;
	static const int ACT_IMG_NUM = ACT_DIR_SLIDE * ACT_DIR_NUM;
	static const int WIDTH = 32;
	static const int HEIGHT = 32;
	static const int ACT_SPEED = 20;
	int act_img[ACT_IMG_NUM];       //< イメージ

	// 0,1,2,1 の4種類 [0～3]までにするために用意
	static const int MAX_MOTION_INDEX = 4;
	// アニメーション変換テーブル
	const int act_motion[MAX_MOTION_INDEX] = { 0, 1, 2, 1, };

	int act_index = 0;
	int act_wait = ACT_SPEED;

	DIR act_dir = DIR::DOWN;

	float yadd = 0.0f;

	void loadData();
	void exitData();
};
#pragma once

