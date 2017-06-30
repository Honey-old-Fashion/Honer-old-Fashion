#pragma once
class ICharacter {
public:

	ICharacter() {} 
	virtual ~ICharacter() = default;

	virtual void mInit() = 0;
	virtual void mDraw() = 0;
	virtual void mUpdate() = 0;
};

