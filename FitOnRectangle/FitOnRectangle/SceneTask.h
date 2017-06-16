#ifndef _SCENETASK_H_
#define _SCENETASK_H_

#include "ISceneChanger.h"
#include "IScene.h"

class SceneTask :public IScene {

protected:
	int mGraphicHandle;
	int mSoundPlayHandle;
	int mSoundPlayFlag = 0;
	ISceneChanger* mChangeScene;

public:
	SceneTask(ISceneChanger* _changer);
	virtual ~SceneTask() {};
	virtual void mInit() override {};
	virtual void mUpdate()override {};
	virtual void mRender()override;
	virtual void mFinal()override;
};


#endif // !_SCENETASK_H_
