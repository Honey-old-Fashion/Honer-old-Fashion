#ifndef _SECONDSTAGE_H_
#define _SECONDSTAGE_H_
#include "IObject.h"
#include "IStage.h"

#define lengthWidth 27
#define LengthHeight 9
class SecondStage : public IStage{
private:


	int m_stage[LengthHeight][lengthWidth] = {
		1,1, 1,1,1, 1,1,1, 1,1,1,1, 1,1,1,1,1,1,1,1,1,1, 1,1, 1, 1, 1,
		1,0, 0,0,0, 0,0,0, 0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0, 0, 0, 1,
		1,0, 0,0,0, 0,0,0, 0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0, 0, 0, 1,
		1,15,0,0,0, 0,0,0, 0,0,0,0, 0,0,0,0,0,0,0,0,0,12,0,0,0, 28,1,
		1,2, 2,2,21,2,2,21,2,10,2,22,2,2,2,2,2,2,2,2,2,2, 2,11, 2, 2, 1,
		1,0, 0,0,0, 0,0,0, 0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0, 0, 0, 1,
		1,0, 0,0,0, 0,0,0, 0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0, 0, 0, 1,
		1,16,0,0,5, 0,0,0, 0,8,0,3, 0,0,0,0,0,0,0,0,0,0, 0,0, 27,31,1,
		1,2, 2,2,2, 2,2,2, 2,2,2,2, 2,2,2,2,2,2,2,2,2,21,2,2, 2, 2, 1,
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
	SecondStage();
	~SecondStage();
	virtual void mSetUp() override;
	virtual void mUpdate() override;
	virtual void mRender() override;
	virtual void mTearDown() override;
};

#endif //!_SECONDSTAGE_H_