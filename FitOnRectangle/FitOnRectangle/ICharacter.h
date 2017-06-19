/*******************************************

* !@file ICharacter.h

* @brief キャラクター関連のクラスに継承させる

* @author 高口剛史

*******************************************/
class ICharacter {

public:
	virtual void mInit(){}  // 初期化
	virtual void mDraw(){}  // 描画
};