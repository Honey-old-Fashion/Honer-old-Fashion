#pragma once
#include "CharacterTask.h"
#include "Singleton.h"
#include "CollisionDetection.h"
/*********************************************************************

* !@file Triangle.h

* @brief �O�p�`�̃N���X

* @author �������j

*********************************************************************/

class Triangle : public CharacterTask{
private:
	POINT m_triPosition[COLOR_NUM];    // �O�p�`�̒��_�̍��W���i�[����
	bool m_livingFlg[COLOR_NUM];// �O�p�`�̃A�N�e�B�u��Ԃ�F�ʂɊǗ�����
	unsigned int createColor;
	CollisionDetection& collision = singleton<CollisionDetection>::GetInstance();
public:
	Triangle(eColor, int ,int);
	~Triangle();
	virtual POINT GetPoint() {
		return this->m_characterPosition;
	}
	void mInit() override;
	void mRender() override;
	void mUpdate() override;
	void mFinal() override;
	void mMove() override;

	inline int mGetFloorY(eColor _color) {
		return m_triPosition[_color].y + CHAR_SIZE;
	}

	inline int mGetCenterX(eColor _color) {
		return m_triPosition[_color].x + (CHAR_SIZE / 2);
	}
};

