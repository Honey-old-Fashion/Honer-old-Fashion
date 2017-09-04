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
	m_moveDownFlag = cm_neutral;
	fitFlag = false;
	count = 0;
	m_jumpFlag = cm_neutral;
	m_jumpSpeed = 30;
	m_jumpTopPosition = 50;
	cursorColor = GetColor(0, 0, 0);
}

CharacterTask::~CharacterTask() {

}

void CharacterTask::mRender() {
	if (m_activeFlg == true) {
		DrawTriangle(
			m_characterPosition.x + (CHAR_SIZE / 3),
			m_characterPosition.y - ((CHAR_SIZE / 3) * 2),
			m_characterPosition.x + ((CHAR_SIZE / 3) * 2),
			m_characterPosition.y - ((CHAR_SIZE / 3) * 2),
			m_characterPosition.x + (CHAR_SIZE / 2),
			m_characterPosition.y - (CHAR_SIZE / 3),
			cursorColor,
			TRUE
		);
	}
}

/***********************************************

* @brief 移動

* @param[in] None

* @return None

***********************************************/
void CharacterTask::mMove() {

	
}


CharacterTask::HitTestData CharacterTask::HitTest(int _gimmickID, int _gimmickType ,POINT _gimmickPos) {
	HitTestData data;
	switch (_gimmickType) {
	case 2:
		if (m_characterPosition.x == _gimmickPos.x && m_characterPosition.y + CHAR_SIZE == _gimmickPos.y) {
			data.hitFlag = true;
			m_moveDownFlag = cm_down;
			m_floorX = (int)_gimmickPos.x;
			m_floorY = (int)_gimmickPos.y;
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
			data.gimmiclID = _gimmickID;
		}
		break;
	default:
		break;
	}
	data.gimmiclID = _gimmickID;
	
	return data;
}

POINT CharacterTask::GetPoint() {
	return m_characterPosition;
}