#pragma once
#include"Map.h"
#include"Player.h"
#include<stdio.h>

class CD :public Map, public Player
{
public:
	void CD1(Player *player);

	//
	// �����蔻����s���֐�
	// 
	// �΂̃L���� ��   x1
	// �@�@�@�@�@ ��   y1
	// �@�@�@�@�@ ���� w1
	// �@�@�@�@�@ �c�� h1
	// ���̃L���� ��   x2
	// �@�@�@�@�@ ��   y2
	// �@�@�@�@�@ ���� w2
	// �@�@�@�@�@ �c�� h2
	//
	int CheckHit(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
	{
		int L1 = x1;      // ��
		int R1 = x1 + w1; // �E(��+����)
		int L2 = x2;      // ��
		int R2 = x2 + w2; // �E(��+����)

		if (R1 <= L2) return 0; //< �����������Ȃ����Ƃɂ���
		if (R2 <= L1) return 0; //< �����������Ȃ����Ƃɂ���

		int U1 = y1;      // ��
		int D1 = y1 + h1; // ��(��+�c��)
		int U2 = y2;      // ��
		int D2 = y2 + h2; // ��(��+�c��)

		if (D1 <= U2) return 0; //< �����������Ȃ����Ƃɂ���
		if (D2 <= U1) return 0; //< �����������Ȃ����Ƃɂ���

		// ����ȊO�̏ꍇ�͓������Ă���
		return 1;
	}

protected:
	const int CHARA_WIDTH = 32;
	const int CHARA_HEIGHT = 32;
	float old_x = x;
	float old_y = y;

};