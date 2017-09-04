#pragma once
#include "GimmickTask.h"

class GoalRectAngleGimmick : public GimmickTask {
private:
	unsigned int createColor;
public:
	GoalRectAngleGimmick(eColor, int ,int);
	~GoalRectAngleGimmick();
	
	virtual void mInit() override;
	virtual void mUpdate() override;
	virtual void mRender() override;
	virtual void mFinal() override;
	virtual POINT GetPoint() {
		return this->pGimmick;
	}
};

