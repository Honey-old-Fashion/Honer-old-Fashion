#ifndef _CHARACTERTASK_H_
#define _CHARACTERTASK_H_

#include "Windows.h"
#include "IObject.h"

#define CHAR_SIZE 40	// キャラクターのサイズ

/*******************************************************************

* !@file CharacterTask.h

* @brief キャラクター関連のクラスに継承させる

* @author 高口剛史

*******************************************************************/
class CharacterTask : public IObject {
protected:
	POINT m_characterPosition;
	
	bool m_activeFlg;
	bool m_canMoveRight;
	bool m_canMoveLeft;
	bool m_moveDownFlag;
	bool m_canJampFlag;
	int count;
	const int speed = 4;
	const char cm_neutral = 0;
	const char cm_up = 1;
	const char cm_down = 2;
	const int cm_ceil = 10;
	const int cm_floor = 100;
	char m_jumpFlag;
	int m_jumpSpeed;
	int m_jumpTopPosition;
	struct HitTestData {
		bool hitFlag;
		int gimmiclID;
	};

public:
	CharacterTask();
	~CharacterTask();

	virtual void mInit() override {};
	virtual void mRender() override {};
	virtual void mUpdate() override {};
	virtual void mFinal() override {};
	virtual void mMove();


	inline void mSetRightMoveFlg(bool _flg) { m_canMoveRight = _flg; }
	inline void mSetLeftMoveFlg(bool _flg) { m_canMoveLeft = _flg; }

	HitTestData HitTest(int _gimmickID, int _gimmickType ,POINT _gimmickPos);
};

#endif // !_CHARACTERTASK_H_