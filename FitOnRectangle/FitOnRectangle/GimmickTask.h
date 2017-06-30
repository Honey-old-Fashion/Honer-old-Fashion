#pragma once
#include "IObject.h"
#include <DxLib.h>
#include <Windows.h>

#define OBJECTSIZE 40


class GimmickTask :public IObject
{
protected:
	POINT pPlayer;
	POINT pGimmick;
	int m_color;
	bool m_gimmickOpenFlag;

	virtual void mInit() override {}
	virtual void mUpdate() override {}
	virtual void mRender()override {}
	virtual void mFinal() override {}

public:
	GimmickTask();
	~GimmickTask();

	virtual void mSetPlayerPointVecter2(POINT,int);
	virtual bool mHitTest();

};

