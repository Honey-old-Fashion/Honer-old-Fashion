#pragma once
#include "SceneTask.h"
#include "ISceneChanger.h"
class SceneTitle : public SceneTask {

public:
	SceneTitle(ISceneChanger* changer);
	~SceneTitle();

	virtual void mInit() override;
	virtual void mUpdate() override;
	virtual void mRender() override;
	virtual void mFinal() override;
	
};

