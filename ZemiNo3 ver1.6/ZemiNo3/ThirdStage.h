#ifndef _THIRDSTAGE_H_
#define _THIRDSTAGE_H_
#include "IObject.h"
#include "IStage.h"

#define lengthWidth 27
#define LengthHeight 9
class ThirdStage : public IStage{
private:


	int m_stage[LengthHeight][lengthWidth] = {
		1,1, 1, 1,1, 1, 1,1, 1,1,1,1,1,1, 1,1, 1, 1,1,1, 1,1, 1, 1, 1, 1, 1,
		1,0, 0, 0,0, 0, 0,0, 0,0,0,0,0,0, 0,0, 0, 1,0,0, 0,0, 0, 0, 0, 0, 1,
		1,0, 0, 0,0, 0, 0,0, 0,0,0,0,0,0, 0,0, 0, 1,0,0, 0,0, 0, 0, 0, 0, 1,
		1,13,14,0,0, 5, 0,0, 0,0,0,0,0,0, 0,0, 12,1,0,0, 0,0, 0, 0, 26,31,1,
		1,2, 2, 2,20,2, 2,19,2,0,2,1,2,21,2,32,2, 2,0,19,2,33,2, 20,2, 2, 1,
		1,0, 0, 0,0, 0, 0,0, 0,0,0,1,0,0, 0,0, 0, 0,0,0, 0,0, 0, 0, 0, 0, 1,
		1,0, 0, 0,0, 0, 0,0, 0,0,0,1,0,0, 0,0, 0, 0,0,0, 0,0, 0, 0, 0, 0, 1,
		1,15,0, 0,4, 0, 0,0, 0,6,0,1,0,0, 0,0, 0, 0,7,3, 0,8, 0, 0, 27,25,1,
		1,2, 2, 2,2, 21,2,2, 2,2,2,2,2,2, 2,2, 20,2,2,2, 2,2, 21,2, 2, 2, 1

	};
	struct ObjectData {
		IObject* iObject[LengthHeight][lengthWidth];
		int gimmicType[LengthHeight][lengthWidth];
		eColor objectColor[LengthHeight][lengthWidth];
	};
	bool charChangeFlag;
	int i;
	ObjectData objData;
public:
	ThirdStage();
	~ThirdStage();
	virtual void mSetUp() override;
	virtual void mUpdate() override;
	virtual void mRender() override;
	virtual void mTearDown() override;
};

#endif //!_THIRDSTAGE_H_