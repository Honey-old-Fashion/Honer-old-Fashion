/******************************************

* !@file CharacterManager.h

* @brief �L�����N�^�[�Ǘ�

* @author �������j

*******************************************/
#include "ICharacter.h"

class CharacterManager :public ICharacter {
public:
	void mInit() override; // ������
	void mDraw() override; // �`��
};