#ifndef _GIMMICKMANAGER_H_
#define _GIMMICKMANAGER_H_

#include "IObject.h"
#include "GateGimmick.h"
#include "DropGimmick.h"
#include "UpGimmick.h"
#include "BallGimmick.h"

class GimmickManager : public IObject
{
public:
	GimmickManager();
	~GimmickManager();
	virtual void mInit() override;
	virtual void mUpdate() override;
	virtual void mRender() override;
	virtual void mFinal() override;
	void mSetRectAngle(int);

	GateGimmick gate;
	DropGimmick drop;
	UpGimmick   up;
	BallGimmick ball;
};

#endif // !_GIMMICKMANAGER_H_