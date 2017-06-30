#ifndef _FIRSTSTAGE_H_
#define _FIRSTSTAGE_H_

#include "StageManager.h"
class FirstStage : public IStage {
private:
	char m_stage;

public:
	FirstStage();
	~FirstStage();

	virtual void mSetUp() override;
	virtual void mUpdate() override;
	virtual void mRender() override;
	virtual void mTearDown() override;
};

#endif // !_FIRSTSTAGE_H_
