/******************************************

* !@file CharacterManager.h

* @brief キャラクター管理

* @author 高口剛史

*******************************************/
#include "ICharacter.h"

class CharacterManager :public ICharacter {
public:
	void mInit() override; // 初期化
	void mDraw() override; // 描画
};