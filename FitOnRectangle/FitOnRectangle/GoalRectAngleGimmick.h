#pragma once
#include "GimmickTask.h"
class GoalRectAngleGimmick : public GimmickTask {

public:
	GoalRectAngleGimmick(int ,int);
	~GoalRectAngleGimmick();
	
	virtual void mInit() override;
	virtual void mUpdate() override;
	virtual void mRender() override;
	virtual void mFinal() override;

};

