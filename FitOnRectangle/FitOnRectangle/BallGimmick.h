#include "GimmickManager.h"
#include "GimmickTask.h"
#include <Windows.h>

#define MOVE 5

class BallGimmick : public GimmickTask
{
private:
	bool m_amountMoveFlag;
	bool m_renderFlag;
	int m_amountMoveCnt;

public:
	BallGimmick(int,int);
	~BallGimmick();
	virtual void mInit() {}
	virtual void mUpdate() override;
	virtual void mRender() override;
	virtual void mFinal(){}

};

