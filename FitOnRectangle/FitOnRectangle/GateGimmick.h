#include "GimmickManager.h"
#include <Windows.h>

#define GIMMICKSIZE 15

class GateGimmick : public GimmickTask
{
private:
	POINT m_gate;
	
public:
	GateGimmick();
	~GateGimmick();
	virtual void mInit() override;
	virtual void mUpdate() override;
	virtual void mRender() override;
	virtual void mFinal() override;

};

