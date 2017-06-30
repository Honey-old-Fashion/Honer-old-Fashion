#pragma once


class IObject {

public:
	virtual ~IObject() = default;
	virtual void mInit() = 0;
	virtual void mUpdate() = 0;
	virtual void mRender() = 0;
	virtual void mFinal() = 0;
};