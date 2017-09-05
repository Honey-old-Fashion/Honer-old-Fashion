#include "CharacterManager.h"
#include "Rectangle.h"
//#include "Triangle.h"


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
	m_character[0] = (IObject*)new class Rectangle(eColor_Red, 50, 50);
}

/***********************************************
* @brief �L�����N�^�[�̕`��
* @param[in] None
* @return None
***********************************************/
void CharacterManager::mRender() {
	// �}�`�̕`��
	m_character[0]->mRender();
}

/***********************************************
* @brief �}�`�̍X�V
* @param[in] None
* @return None
***********************************************/
void CharacterManager::mUpdate() {

	// ���W�𓮂����L�����̍��W���X�V����
	m_character[0]->mUpdate();
	//m_character[0]->mSetPosition(m_character[0]->mGetPosition(), eColor_Red);
}

/***********************************************
* @brief �I������
* @param[in] None
* @return None
***********************************************/
void CharacterManager::mFinal() {

}