#pragma once
class Player
{
	enum class DIR : int
	{
		// �g�p����G(sample007.png)�̏��Ԃɍ��킹�Ă���
		DOWN = 0,
		LEFT,
		RIGHT,
		UP,

		NUM,
	};

public:
	void Init();   //< ��������
	void Update(); //< �X�V����
	void Draw();   //< �`�揈��
	void Exit();   //< �I������
	void CD();

	int SetDir(DIR dir) { act_dir = dir; } //< �����ݒ�
	int GetWidth() { return WIDTH; }	//< ���T�C�Y
	int GetHeight() { return HEIGHT; }  //< �c�T�C�Y

	float x, y;    //< �\�����W

	// x, y, yadd �̂��ꂼ��setter(�ƈꕔgetter)���`
	void setX(float arg) { x = arg; }
	void setY(float arg) { y = arg; }
	void setYAdd(float arg) { yadd = arg; };
	float getYAdd() { return yadd; };

protected:
	static const int ACT_DIR_SLIDE = 3;
	static const int ACT_DIR_NUM = 4;
	static const int ACT_IMG_NUM = ACT_DIR_SLIDE * ACT_DIR_NUM;
	static const int WIDTH = 32;
	static const int HEIGHT = 32;
	static const int ACT_SPEED = 20;
	int act_img[ACT_IMG_NUM];       //< �C���[�W

	// 0,1,2,1 ��4��� [0�`3]�܂łɂ��邽�߂ɗp��
	static const int MAX_MOTION_INDEX = 4;
	// �A�j���[�V�����ϊ��e�[�u��
	const int act_motion[MAX_MOTION_INDEX] = { 0, 1, 2, 1, };

	int act_index = 0;
	int act_wait = ACT_SPEED;

	DIR act_dir = DIR::DOWN;

	float yadd = 0.0f;

	void loadData();
	void exitData();
};
#pragma once

