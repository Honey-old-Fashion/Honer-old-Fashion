#pragma once
#include "GimmickTask.h"
class hamaru : public GimmickTask {
public:
	hamaru(eColor, int, int);
	~hamaru();

	virtual void mInit() override {};
	virtual void mUpdate() override {};
	virtual void mRender() override;
	virtual void mFinal() override {};
};

