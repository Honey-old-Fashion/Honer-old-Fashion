#include "GimmickManager.h"
#include "GimmickTask.h"

#define MOVE 5

class BallGimmick : public GimmickTask
{
private:
	bool m_amountMoveFlag;
	bool m_renderFlag;
	int m_amountMoveCnt;

public:
	BallGimmick();
	~BallGimmick();
	virtual void mInit() override;
	virtual void mUpdate() override;
	virtual void mRender() override;
	virtual void mFinal() override;
	virtual bool mHitTest()override;
};

