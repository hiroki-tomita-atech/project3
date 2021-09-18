#include "DxLib.h"
#include "Player.h"

// 初期処理
void Player::Init()
{
	loadData();

	int act_wait = ACT_SPEED;
	x = 0;
	y = 0;
}

//< 更新処理
void Player::Update()
{
	float old_x = x;
	float old_y = y;
	float speed = 3.0f;

	// キー情報を取得する
	int input = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	// キーで移動させる
	if (input & PAD_INPUT_RIGHT)
	{
		x += speed;
		act_dir = DIR::RIGHT;
	}
	if (input & PAD_INPUT_LEFT)
	{
		x -= speed;
		act_dir = DIR::LEFT;
	}
	if (input & PAD_INPUT_UP)
	{
		yadd = -5.0f;
	}
	if (input & PAD_INPUT_DOWN)
	{
		y += speed;
		act_dir = DIR::DOWN;
	}

	y += yadd;
	yadd += 0.2f;


	// アクション
	if (--act_wait <= 0)
	{
		act_index++;
		act_index %= MAX_MOTION_INDEX;
		act_wait = ACT_SPEED;
	}
}

// 描画処理
void Player::Draw()
{
	int motion_index = act_motion[act_index];

	// 自分のキャラを表示する
	DrawGraph(x, y, act_img[motion_index + (int)act_dir * ACT_DIR_SLIDE], TRUE);
}

// 終了処理
void Player::Exit()
{
	exitData();
}

void Player::loadData()
{
	LoadDivGraph("demo/sample007.png", ACT_IMG_NUM, ACT_DIR_SLIDE, ACT_DIR_NUM, WIDTH, HEIGHT, act_img);
}

void Player::exitData()
{
	for (int i = 0; i < ACT_IMG_NUM; i++)
	{
		DeleteGraph(act_img[i]);
	}
}