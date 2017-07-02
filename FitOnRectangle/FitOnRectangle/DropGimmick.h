#include "GimmickManager.h"

class DropGimmick : GimmickTask
{
public:
	DropGimmick(eColor, int ,int);
	~DropGimmick();
	virtual void mInit() override {};
	virtual void mUpdate() override {};
	virtual void mRender() override;
	virtual void mFinal() override {};
};

