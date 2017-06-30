#pragma once
#include "ICharacter.h"
#include "CharacterTask.h"
class Rectangle;

class CharacterManager :public ICharacter {
public:
	CharacterManager();
	~CharacterManager();

	CharacterTask* m_character[3];
	
	virtual void mInit() override;
	virtual void mDraw() override;
	virtual void mUpdate() override;
};