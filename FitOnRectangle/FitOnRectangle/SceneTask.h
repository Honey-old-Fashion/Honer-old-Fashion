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

	void mGameEnd();
	virtual BOOL mDrawSelectBox(int _x, int _y, int _width, int _height, LPCTSTR _text = NULL, bool _clickFlag =true ,int _buttonColor = GetColor(0, 0, 0), int _textColor = GetColor(255, 255, 255));

public:
	SceneTask(ISceneChanger* _changer);
	virtual ~SceneTask() {};
	virtual void mInit() override {};
	virtual void mUpdate()override {};
	virtual void mRender()override;
	virtual void mFinal()override;

};


#endif // !_SCENETASK_H_
