#pragma once
#include "GimmickTask.h"
class GoalTriangle : public GimmickTask {
private:
	int _lineX;
	int _lineY;
	int _lineLength;
public:
	GoalTriangle(eColor ,int ,int);
	~GoalTriangle();
	virtual POINT GetPoint() {
		return this->pGimmick;
	}
	virtual void mInit() override {};
	virtual void mUpdate() override;
	virtual void mRender() override;
	virtual void mFinal() override {};
};
