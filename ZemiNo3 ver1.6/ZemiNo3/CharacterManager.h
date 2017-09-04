#pragma once
#include "IObject.h"
#include "CharacterTask.h"
/********************************************************

* !@file CharacterManager.h

* @brief �L�����N�^�[�̐���

* @author �������j

********************************************************/
class CharacterManager:public IObject {
public:
	virtual void mInit() override;
	virtual void mRender() override;
	virtual void mUpdate() override;
	virtual void mFinal() override;

	CharacterManager();
	~CharacterManager();

	IObject* m_character[3];
};
