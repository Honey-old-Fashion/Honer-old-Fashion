#ifndef _CHARACTERTASK_H_
#define _CHARACTERTASK_H_

#include "Windows.h"
#include "IObject.h"
#include "GameManager.h"

#define CHAR_SIZE 40	// キャラクターのサイズ

/*******************************************************************

* !@file CharacterTask.h

* @brief キャラクター関連のクラスに継承させる

* @author 高口剛史

*******************************************************************/
class CharacterTask : public IObject {
protected:
	POINT m_characterPosition;
	e_charType thisCharType;
	bool m_activeFlg;
	bool m_canMoveRight;
	bool m_canMoveLeft;
	char m_moveDownFlag;
	bool m_canJampFlag;
	bool m_dropFlag;
	int count;
	int dropSpeed = 0;
	int dropFloor;
	const int speed = 5;
	const char cm_neutral = 0;
	const char cm_up = 1;
	const char cm_down = 2;
	int m_floorX;
	int m_floorY;
	char m_jumpFlag;
	bool m_currentJumpFlag;
	int m_jumpSpeed;
	int m_jumpTopPosition;
	long floor;
	bool fitFlag;
	unsigned int cursorColor;
	struct HitTestData {
		bool hitFlag;
		int gimmiclID;
	};
	eColor m_colorId;
public:
	CharacterTask();
	~CharacterTask();

	virtual void mInit() override {};
	virtual void mRender() override;
	virtual void mUpdate() override {};
	virtual void mFinal() override {};
	virtual void mMove();

	virtual POINT GetPoint() override;
	inline void mSetRightMoveFlg(bool _flg) { m_canMoveRight = _flg; }
	inline void mSetLeftMoveFlg(bool _flg) { m_canMoveLeft = _flg; }

	HitTestData HitTest(int _gimmickID, int _gimmickType ,POINT _gimmickPos);
};

#endif // !_CHARACTERTASK_H_