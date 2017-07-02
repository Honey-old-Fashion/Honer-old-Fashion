#include "CharacterTask.h"
#include "DxLib.h"


/***********************************************

* @brief コンストラクタ

* @param[in] None

* @return None

***********************************************/
CharacterTask::CharacterTask(){
	
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
		if (CheckHitKey(KEY_INPUT_RIGHT) != 0) {
			m_characterPosition.x += 5;
		}
		if (CheckHitKey(KEY_INPUT_LEFT) != 0) {
			m_characterPosition.x -= 5;
		}
	//}
}

CharacterTask::HitTestData CharacterTask::HitTest(int _gimmickID, int _gimmickType ,POINT _gimmickPos) {
	HitTestData data;
	switch (_gimmickType) {
	case 4:

		break;
	case 5:

		break;
	case 6:
		break;
	case 10:
		break;
	default:
		break;
	}
	data.gimmiclID = _gimmickID;
	

	return data;
}