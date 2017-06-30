#include "GimmickManager.h"

class DropGimmick : GimmickTask
{
public:
	DropGimmick();
	~DropGimmick();
	virtual void mInit() override;
	virtual void mUpdate() override;
	virtual void mRender() override;
	virtual void mFinal() override;
};

