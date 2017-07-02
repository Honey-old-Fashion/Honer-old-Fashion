#pragma once
#include "IObject.h"
#include <DxLib.h>
#include <Windows.h>

#define OBJECTSIZE 40



class GimmickTask :public IObject
{
protected:
	bool activeFlag;
	POINT pPlayer;
	POINT pGimmick;
	unsigned int m_color;
	bool m_gimmickOpenFlag;
	int m_colorID;


public:
	GimmickTask();
	~GimmickTask();

	inline POINT mGetGimmickPointVecter2() {
		return pGimmick;
	}

	inline int mGetGimmickColorId() {
		return m_colorID;
	}

	inline void mSetActiveFlag(bool _activeFlag) {
		activeFlag = _activeFlag;
	}

	inline bool mGetActiveFlag() {
		return activeFlag;
	}

	virtual void mInit() override {}
	virtual void mUpdate() override {}
	virtual void mRender()override {}
	virtual void mFinal() override {}
};

