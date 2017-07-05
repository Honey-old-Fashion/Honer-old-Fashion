#include "CharacterTask.h"
#include "DxLib.h"

/***********************************************

* @brief コンストラクタ

* @param[in] None

* @return None

***********************************************/
CharacterTask::CharacterTask(){
	m_canMoveRight = true;
	m_canMoveLeft = true;
	m_moveDownFlag = false;
	count = 0;
	m_jumpFlag = cm_neutral;
	m_jumpSpeed = 10;
	m_jumpTopPosition = 50;
}

CharacterTask::~CharacterTask() {

}


/***********************************************

* @brief 移動

* @param[in] None

* @return None

***********************************************/
void CharacterTask::mMove() {
	//if (m_activeFlg == true) {
	if (CheckHitKey(KEY_INPUT_RIGHT) != 0 && m_canMoveRight == true) {
		m_characterPosition.x += 5;
	}
	if (CheckHitKey(KEY_INPUT_LEFT) != 0 && m_canMoveLeft == true) {
		m_characterPosition.x -= 5;
	}
	
	//}
}

CharacterTask::HitTestData CharacterTask::HitTest(int _gimmickID, int _gimmickType ,POINT _gimmickPos) {
	HitTestData data;
	switch (_gimmickType) {
	case 2:
		if (m_characterPosition.x == _gimmickPos.x) {
			data.hitFlag = true;
			/*
			m_canMoveRight = false;
			m_canMoveLeft = false;
			*/
		}
		
		break;
	case 4:
		if (m_characterPosition.x + CHAR_SIZE >= _gimmickPos.x && m_characterPosition.x <= _gimmickPos.x + CHAR_SIZE) {
			m_canMoveRight = false;
			data.hitFlag = true;
		}
		else {
			m_canMoveRight = true;
			data.hitFlag = false;
		}
		
		/*
		if (m_characterPosition.x == _gimmickPos.x + CHAR_SIZE) {
			m_canMoveLeft = false;
		}
		*/
		break;
	case 5:
		break;
	case 6:

		break;
	case 10:
		if (m_characterPosition.x + CHAR_SIZE >= _gimmickPos.x + CHAR_SIZE / 4 && m_characterPosition.x + CHAR_SIZE <= _gimmickPos.x + (CHAR_SIZE / 4 * 3)) {
			data.hitFlag = true;
		}
		break;
	default:
		break;
	}
	data.gimmiclID = _gimmickID;
	
	return data;
}