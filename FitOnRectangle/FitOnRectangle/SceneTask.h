/**********************************************************************************************
* !@file  SceneTask.h
* @brief  �e�V�[���ŋ��ʂ̃��\�b�h��錾
* @author Sugiyama Ryo
******************************************************************************************/
#ifndef _SCENETASK_H_
#define _SCENETASK_H_

#include "ISceneChanger.h" 
#include "IScene.h"
#include <Dxlib.h>
#include "SystemManager.h" 

class SceneTask :public IScene {

protected:
	int mGraphicHandle;
	int mSoundPlayHandle;
	int mSoundPlayFlag = 0;
	ISceneChanger* m_changeScene;

	virtual BOOL mDrawSelectBox(int _x, int _y, int _width, int _height, int _gHandle, bool _clickFlag = true);

public:
	SceneTask(ISceneChanger* _changer);
	virtual ~SceneTask() {};
	virtual void mInit() override {};
	virtual void mUpdate()override {};
	virtual void mRender()override;
	virtual void mFinal()override;

};


#endif // !_SCENETASK_H_
