#include "GimmickManager.h"

class UpGimmick : GimmickTask
{
public:
	UpGimmick(eColor,int,int);
	~UpGimmick();
	virtual void mInit(){}
	virtual void mUpdate(){}
	virtual void mRender() override;
	virtual void mFinal() {}
};

