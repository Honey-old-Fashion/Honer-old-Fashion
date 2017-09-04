#ifndef _FLOAR_H_
#define _FLOAR_H_

#include "GimmickTask.h"
#include "DxLib.h"

class FloarObject : public GimmickTask {
private:
	POINT pFloar;
	const int cm_objSize = 41;
	const unsigned int mBlack = GetColor(255, 255, 255);
	const unsigned int mWhite = GetColor(0,0,0);

public:
	FloarObject(int ,int);
	~FloarObject();

	virtual void mInit() override {};
	virtual void mUpdate() override {};
	virtual void mRender() override;
	virtual void mFinal() override {};
	virtual POINT GetPoint() {
		return this->pGimmick;
	}
};

#endif // !_FLOAR_H_