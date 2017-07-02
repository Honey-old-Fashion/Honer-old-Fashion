#pragma once
#include "SceneTask.h"
#include "ISceneChanger.h"
#include "FirstStage.h"

class SceneGame : public SceneTask {
public:   
	SceneGame(ISceneChanger* _changer);
	~SceneGame();
	 
	virtual void mInit() override;
	virtual void mUpdate() override;
	virtual void mRender() override;
	virtual void mFinal() override;

private:
	FirstStage* obj;
};

