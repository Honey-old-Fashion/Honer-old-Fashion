#pragma once
#include "GimmickTask.h"
class FitRect : public GimmickTask {
public:
	FitRect(eColor, int, int);
	~FitRect();

	virtual void mInit() override {};
	virtual void mUpdate() override;
	virtual void mRender() override;
	virtual void mFinal() override {};
	virtual POINT GetPoint() {
		return this->pGimmick;
	}
};

