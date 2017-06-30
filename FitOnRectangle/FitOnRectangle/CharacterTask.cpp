#include "CharacterTask.h"
#include "DxLib.h"


/***********************************************

* @brief �R���X�g���N�^

* @param[in] None

* @return None

***********************************************/
CharacterTask::CharacterTask(){
	m_characterPosition.x = 50;
	m_characterPosition.y = 50;
}


CharacterTask::~CharacterTask()
{
}

/***********************************************

* @brief ������

* @param[in] None

* @return None

***********************************************/
void CharacterTask::mInit() {

}

/***********************************************

* @brief �`��

* @param[in] None

* @return None

***********************************************/
void CharacterTask::mRender() {

}

/***********************************************

* @brief �X�V

* @param[in] None

* @return None

***********************************************/
void CharacterTask::mUpdate() {

}

/***********************************************

* @brief �ړ�

* @param[in] None

* @return None

***********************************************/
void CharacterTask::mMove() {
	//if (m_activeFlg == true) {
		if (CheckHitKey(KEY_INPUT_RIGHT) != 0) {
			m_characterPosition.x += 10;
		}
		if (CheckHitKey(KEY_INPUT_LEFT) != 0) {
			m_characterPosition.x -= 10;
		}
	//}
}

/***********************************************

* @brief �I������

* @param[in] None

* @return None

***********************************************/
void CharacterTask::mFinal() {

}

/***********************************************

* @brief ���W��Ԃ�

* @param[in] None

* @return m_characterPosition(���W���i�[����POINT�^�ϐ�)

***********************************************/
POINT CharacterTask::mGetPosition() {
	return m_characterPosition;
}

/***********************************************

* @brief �E�����ւ̈ړ���flg���擾����

* @param[in] _flg

* @return None

***********************************************/
void CharacterTask::mSetRightMoveFlg(bool _flg) {
	m_canMoveRight = _flg;
}

/***********************************************

* @brief �������ւ̈ړ���flg���擾����

* @param[in] _flg

* @return None

***********************************************/
void CharacterTask::mSetLeftMoveFlg(bool _flg) {
	m_canMoveLeft = _flg;
}