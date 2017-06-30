#ifndef _SCENEGAME_H_
#define _SCENEGAME_H_

#include "SceneTask.h"
#include "ISceneChanger.h"
class SceneGame : public SceneTask {
public:   
	SceneGame(ISceneChanger* _changer);
	~SceneGame();
	 
	virtual void mInit() override;
	virtual void mUpdate() override;
	virtual void mRender() override;
	virtual void mFinal() override;
};

#endif // !_SCENEGAME_H_