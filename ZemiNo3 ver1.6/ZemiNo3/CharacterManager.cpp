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
* @brief 初期化
* @param[in] None
* @return None
***********************************************/
void CharacterManager::mInit() {
	m_character[0] = (IObject*)new class Rectangle(eColor_Red, 50, 50);
}

/***********************************************
* @brief キャラクターの描画
* @param[in] None
* @return None
***********************************************/
void CharacterManager::mRender() {
	// 図形の描画
	m_character[0]->mRender();
}

/***********************************************
* @brief 図形の更新
* @param[in] None
* @return None
***********************************************/
void CharacterManager::mUpdate() {

	// 座標を動かしキャラの座標を更新する
	m_character[0]->mUpdate();
	//m_character[0]->mSetPosition(m_character[0]->mGetPosition(), eColor_Red);
}

/***********************************************
* @brief 終了処理
* @param[in] None
* @return None
***********************************************/
void CharacterManager::mFinal() {

}