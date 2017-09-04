#pragma once
#include "GimmickTask.h"
class FitTriangle : public GimmickTask {
private:
	unsigned int createColor;
	const unsigned int mBlack = GetColor(0, 0, 0); 
	const unsigned int mWhite = GetColor(255, 255, 255);

public:
	FitTriangle(eColor ,int ,int);
	~FitTriangle();
	virtual void mInit() {}
	virtual void mUpdate() override;
	virtual void mRender() override;
	virtual void mFinal() {}
	virtual POINT GetPoint() {
		return this->pGimmick;
	}
};

