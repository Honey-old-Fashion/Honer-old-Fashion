#include "CharacterTask.h"
#include "DxLib.h"


/***********************************************

* @brief コンストラクタ

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

* @brief 初期化

* @param[in] None

* @return None

***********************************************/
void CharacterTask::mInit() {

}

/***********************************************

* @brief 描画

* @param[in] None

* @return None

***********************************************/
void CharacterTask::mRender() {

}

/***********************************************

* @brief 更新

* @param[in] None

* @return None

***********************************************/
void CharacterTask::mUpdate() {

}

/***********************************************

* @brief 移動

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

* @brief 終了処理

* @param[in] None

* @return None

***********************************************/
void CharacterTask::mFinal() {

}

/***********************************************

* @brief 座標を返す

* @param[in] None

* @return m_characterPosition(座標を格納するPOINT型変数)

***********************************************/
POINT CharacterTask::mGetPosition() {
	return m_characterPosition;
}

/***********************************************

* @brief 右方向への移動のflgを取得する

* @param[in] _flg

* @return None

***********************************************/
void CharacterTask::mSetRightMoveFlg(bool _flg) {
	m_canMoveRight = _flg;
}

/***********************************************

* @brief 左方向への移動のflgを取得する

* @param[in] _flg

* @return None

***********************************************/
void CharacterTask::mSetLeftMoveFlg(bool _flg) {
	m_canMoveLeft = _flg;
}