#include "GimmickTask.h"


class UpGimmick : public GimmickTask
{
public:
	UpGimmick(eColor, int, int);
	~UpGimmick();
	virtual void mInit() override {}
	virtual void mUpdate() override;
	virtual void mRender() override;
	virtual void mFinal() override {}
	virtual POINT GetPoint() {
		return this->pGimmick;
	}
};
