#ifndef _SCENEMANAGER_H_
#define _SCENEMANAGER_H_

#include "IScene.h"
#include "ISceneChanger.h"

class SceneManager : public ISceneChanger, IScene {

private:
	IScene* mScene;
	eSceneName mNextScene;

public:
	SceneManager();
	~SceneManager();
	virtual void mInit() override;
	virtual void mUpdate() override;
	virtual void mRender() override;
	virtual void mFinal() override;
	void mChangeScene(eSceneName _NextScene) override;
	
};

#endif // !_SCENEMANAGER_H_