#include "GimmickManager.h"

class UpGimmick : GimmickTask
{
public:
	UpGimmick();
	~UpGimmick();
	virtual void mInit() override;
	virtual void mUpdate() override;
	virtual void mRender() override;
	virtual void mFinal() override;
};

