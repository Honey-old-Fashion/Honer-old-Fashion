#pragma once
#include "SceneTask.h"
#include "ISceneChanger.h"
class SceneTitle : public SceneTask {

private:
	bool m_nextSceneFlag[2];

public:
	SceneTitle(ISceneChanger* changer);
	~SceneTitle();
	    
	virtual void mInit() override;
	virtual void mUpdate() override;
	virtual void mRender() override;
	virtual void mFinal() override;
	
	
};

