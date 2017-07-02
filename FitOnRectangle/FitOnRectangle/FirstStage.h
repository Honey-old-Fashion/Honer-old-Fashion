#ifndef _FIRSTSTAGE_H_
#define _FIRSTSTAGE_H_
#include "IObject.h"
#include "StageManager.h"

class FirstStage : public IStage {
private:

	int m_stage[10] = {1,0,0,0,0,0,0,0,0,10};
	struct ObjectData {
		IObject* iObjct[10];
		int gimmicType[10];
	};
	ObjectData objData;
public:
	FirstStage();
	~FirstStage();

	virtual void mSetUp() override;
	virtual void mUpdate() override;
	virtual void mRender() override;
	virtual void mTearDown() override;
};

#endif // !_FIRSTSTAGE_H_
