#include "DxLib.h"
#include "Player.h"
#include "Map.h"
#include "CD.h"

// �N���X
Player player;
Map map;
CD playercd;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	//======================================================
	// �E�C���h�E�ݒ��DX���C�u�����̏�����
	//======================================================
	const int SCREEN_WIDTH = 640;		//< �X�N���[�����̑傫��
	const int SCREEN_HEIGHT = 480;		//< �X�N���[���c�̑傫��

	// Windows���[�h�ɂ���
	ChangeWindowMode(TRUE);
	// ��ʃT�C�Y�̐ݒ�
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);
	// DX���C�u����������
	if (DxLib_Init() == -1)
	{
		//�������Ɏ��s
		return -1;
	}
	// �_�u���o�b�t�@���[�h
	SetDrawScreen(DX_SCREEN_BACK);
	//======================================================
	// �Q�[������
	//======================================================
	//------------------------------------------------------
	// �Q�[������������
	//------------------------------------------------------

	//�}�b�v�̏������� 
	map.Init();
	
	// �v���C���[�̏�������
	player.Init();

	player.x = (SCREEN_WIDTH - player.GetWidth()) / 2;    //< ��ʂ̒��S
	player.y = (SCREEN_HEIGHT - player.GetHeight()) / 2;	//< ��ʂ̒��S


	//------------------------------------------------------
	// ���C�����[�v����
	//------------------------------------------------------
	while (ProcessMessage() == 0)
	{
		//����ʏ���
		ClearDrawScreen();

		// �}�b�v
		// map.Update();
		map.Draw();

		// �v���C���[����
		player.Update();

		// �����蔻��
		// �|�C���^�n������
		playercd.CD1(&player);

		// �v���C���[�`��
		player.Draw();

		//����ʂ�\��ʂ����ւ���
		ScreenFlip();
	}

	// �v���C���[�I��
	player.Exit();

	// map.Exit();

	//======================================================
	// DX���C�u�����I���ƃv���O�����I��
	//======================================================
	DxLib_End();
	return 0;
}