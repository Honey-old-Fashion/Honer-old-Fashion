#include "CharacterManager.h"
#include "Rectangle.h"
#include "Triangle.h"


CharacterManager::CharacterManager()
{
}


CharacterManager::~CharacterManager()
{
}

/***********************************************

* @brief ������

* @param[in] None

* @return None

***********************************************/
void CharacterManager::mInit() {
	m_character[0] = (CharacterTask*)new class Rectangle;
	m_character[1] = (CharacterTask*)new class Triangle;
		
	// �}�`�̐���
	m_character[0]->mCreate(eColor_Red, 50, 50);
	m_character[0]->mCreate(eColor_Blue, 50, 200);
	m_character[1]->mCreate(eColor_Red, 200, 50);
}

/***********************************************

* @brief �L�����N�^�[�̕`��

* @param[in] None

* @return None

***********************************************/
void CharacterManager::mRender() {
	// �}�`�̕`��
	m_character[0]->mRender();
	m_character[1]->mRender();
}

/***********************************************

* @brief �}�`�̍X�V

* @param[in] None

* @return None

***********************************************/
void CharacterManager::mUpdate() {

	// ���W�𓮂����L�����̍��W���X�V����
	m_character[0]->mMove();
	m_character[0]->mSetPosition(m_character[0]->mGetPosition(), eColor_Red);
}

/***********************************************

* @brief �I������

* @param[in] None

* @return None

***********************************************/
void CharacterManager::mFinal() {

}