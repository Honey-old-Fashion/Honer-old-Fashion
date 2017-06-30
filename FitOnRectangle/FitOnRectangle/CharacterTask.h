#pragma once
#include "Windows.h"
#include "IObject.h"
#include "Color.h"

#define CHAR_SIZE 100  // キャラクターのサイズ

/*******************************************************************

* !@file CharacterTask.h

* @brief キャラクター関連のクラスに継承させる

* @author 高口剛史

*******************************************************************/
class CharacterTask : public IObject {
private:
	POINT m_characterPosition;
	bool m_activeFlg;
	bool m_canMoveRight;
	bool m_canMoveLeft;
public:
	CharacterTask();
	~CharacterTask();

	virtual void mInit() override;
	virtual void mCreate(eColor, int, int){};
	virtual void mRender() override;
	virtual void mUpdate() override;
	virtual void mFinal() override;
	virtual void mMove();

	virtual inline void mSetActiveFlg(bool _activeFlg) {
		m_activeFlg = _activeFlg;
	}
	virtual inline void mSetPosition(POINT _position, eColor _color) {};

	POINT mGetPosition();

	virtual int mGetFloorY(eColor) = 0;
	virtual int mGetCenterX(eColor) = 0;

	void mSetRightMoveFlg(bool);
	void mSetLeftMoveFlg(bool);
};

