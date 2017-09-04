#ifndef _FIRSTSTAGE_H_
#define _FIRSTSTAGE_H_
#include "IObject.h"
#include "IStage.h"

#define lengthWidth 27
#define LengthHeight 9

class FirstStage : public IStage {
private:


	int m_stage[LengthHeight][lengthWidth] = {
		1, 1,1,1,1,1, 1,1, 1,1,1,1,1, 1,1,1, 1,1,1,1, 1,1,1, 1,1, 1,1,
		1, 0,0,0,0,0, 0,0, 0,0,0,0,0, 0,0,0, 0,0,0,0, 0,0,0, 0,0, 0,1,
		1, 0,0,0,0,0, 0,0, 0,0,0,0,0, 0,0,0, 0,0,0,0, 0,0,0, 0,0, 0,1,
		1,15,0,0,0,0, 0,0, 3,0,0,0,0, 0,0,0, 0,0,0,0, 0,0,0,27,0,28,1,
		1, 2,2,2,2,2,21,2, 2,2,2,2,2,21,2,0, 2,2,2,2, 2,2,2, 2,2, 2,1,
		1, 0,0,0,0,0, 0,0, 0,0,0,0,0, 0,0,0, 0,0,0,0, 0,0,0, 0,0, 0,1,
		1, 0,0,0,0,0, 0,0, 0,0,0,0,0, 0,0,0, 0,0,0,0, 0,0,0, 0,0, 0,1,
		1,16,0,0,0,5, 0,0, 0,0,0,0,0, 0,0,8, 0,0,0,0, 0,0,0, 0,0, 0,1,
		1, 2,2,2,2,2, 2,2,22,2,2,2,2, 2,2,2, 2,2,2,2, 2,2,2, 2,2, 2,1,
	
	};
	int currentCharcterPos[LengthHeight][lengthWidth];
	struct ObjectData {
		IObject* iObject[LengthHeight][lengthWidth];
		int gimmicType[LengthHeight][lengthWidth];
		eColor objectColor[LengthHeight][lengthWidth];
	};
	bool charChangeFlag;
	int i;
	ObjectData objData;
public:
	FirstStage();
	~FirstStage();
	bool clearFlag;
	virtual void mSetUp() override;
	virtual void mUpdate() override;
	virtual void mRender() override;
	virtual void mTearDown() override;
};

#endif // !_FIRSTSTAGE_H_
