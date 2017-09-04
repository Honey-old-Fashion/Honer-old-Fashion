/**********************************************************************************************
* !@file  SceneTask.h
* @brief  各シーンで共通のメソッドを宣言
* @author Sugiyama Ryo
******************************************************************************************/
#ifndef _SCENETASK_H_
#define _SCENETASK_H_

#include "ISceneChanger.h" 
#include "IScene.h"
#include "SystemManager.h" 

class SceneTask :public IScene {

protected:
	int mGraphicHandle;
	int mSoundPlayHandle;
	int mSoundPlayFlag = 0;
	bool mNextSceneFlag[4];

	int m_stageID;
	
	virtual bool mDrawSelectBox(int _x, int _y, int _width, int _height, int _gHandle, bool _clickFlag = true);
	virtual inline void mSetStageSelectFlag(int _stageID)  { m_stageID = _stageID; }
public:
	SceneTask(ISceneChanger* _changer);
	virtual ~SceneTask() {};
	virtual void mInit() override {};
	virtual void mUpdate()override {};
	virtual void mRender()override;
	virtual void mFinal()override;
	ISceneChanger* m_changeScene;
};


#endif // !_SCENETASK_H_
