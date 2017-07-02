#ifndef _CHARACTERTASK_H_
#define _CHARACTERTASK_H_

#include "Windows.h"
#include "IObject.h"

#define CHAR_SIZE 40	// �L�����N�^�[�̃T�C�Y

/*******************************************************************

* !@file CharacterTask.h

* @brief �L�����N�^�[�֘A�̃N���X�Ɍp��������

* @author �������j

*******************************************************************/
class CharacterTask : public IObject {
protected:
	POINT m_characterPosition;
	
	bool m_activeFlg;
	bool m_canMoveRight;
	bool m_canMoveLeft;

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