#ifndef _FLOAR_H_
#define _FLOAR_H_

#include "IObject.h"
#include "DxLib.h"
class FloarObject : public IObject {
private:
	POINT pFloar;
	const int cm_objSize = 41;
	const unsigned int mBlack = GetColor(255, 255, 255);
public:
	FloarObject(int ,int);
	~FloarObject();

	virtual void mInit() override {};
	virtual void mUpdate() override {};
	virtual void mRender() override;
	virtual void mFinal() override {};
};

#endif // !_FLOAR_H_