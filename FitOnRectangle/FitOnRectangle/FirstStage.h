#ifndef _FIRSTSTAGE_H_
#define _FIRSTSTAGE_H_
#include "IObject.h"
#include "FloarObject.h"
#include "Rectangle.h"
#include "GateGimmick.h"
#include "GoalRectAngleGimmick.h"
#include "StageManager.h"
#include "Rectangle.h"
#include "hamaru.h"
class FirstStage : public IStage {
private:
	template <class T>
	inline T pointer_cast(void* p)
	{
		return static_cast<T>(p);
	}

	int m_stage[10] = {1,0,0,2,0,0,4,0,0,10};
	struct ObjectData {
		class Rectangle* iChara;
		GoalRectAngleGimmick* iGimmick;
		hamaru* Hamaru;
		GateGimmick* iGate;
		IObject* iObjct[10];
		int gimmicType[10];
	};
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
