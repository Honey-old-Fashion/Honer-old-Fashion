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

* @brief 初期化

* @param[in] None

* @return None

***********************************************/
void CharacterManager::mInit() {
	m_character[0] = (CharacterTask*)new class Rectangle;
	m_character[1] = (CharacterTask*)new class Triangle;
		
	// 図形の生成
	m_character[0]->mCreate(eColor_Red, 50, 50);
	m_character[0]->mCreate(eColor_Blue, 50, 200);
	m_character[1]->mCreate(eColor_Red, 200, 50);
}

/***********************************************

* @brief キャラクターの描画

* @param[in] None

* @return None

***********************************************/
void CharacterManager::mRender() {
	// 図形の描画
	m_character[0]->mRender();
	m_character[1]->mRender();
}

/***********************************************

* @brief 図形の更新

* @param[in] None

* @return None

***********************************************/
void CharacterManager::mUpdate() {

	// 座標を動かしキャラの座標を更新する
	m_character[0]->mMove();
	m_character[0]->mSetPosition(m_character[0]->mGetPosition(), eColor_Red);
}

/***********************************************

* @brief 終了処理

* @param[in] None

* @return None

***********************************************/
void CharacterManager::mFinal() {

}