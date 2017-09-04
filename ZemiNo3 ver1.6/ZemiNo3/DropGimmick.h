#include "GimmickTask.h"

class DropGimmick : GimmickTask
{
public:
	DropGimmick(int, int);
	~DropGimmick();
	virtual void mInit() override {};
	virtual void mUpdate() override;
	virtual void mRender() override;
	virtual void mFinal() override {};
	virtual POINT GetPoint() {
		return this->pGimmick;
	}
};
