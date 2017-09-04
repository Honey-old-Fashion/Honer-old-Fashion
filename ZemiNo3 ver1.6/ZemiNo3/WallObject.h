#pragma once
#include "GimmickTask.h"
#include <windows.h>
class WallObject : public GimmickTask {
private:
	const unsigned int mBlack = GetColor(0, 0, 0);
	POINT pWall;
public:
	WallObject(int ,int );
	~WallObject();
	virtual void mInit() {}
	virtual void mUpdate() {}
	virtual void mRender() override;
	virtual void mFinal() {}
	virtual POINT GetPoint() {
		return this->pGimmick;
	}
};

