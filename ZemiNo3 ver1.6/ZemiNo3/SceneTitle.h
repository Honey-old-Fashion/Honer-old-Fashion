/**********************************************************************************************
* !@file  SceneTitle.h
* @brief  タイトルシーンの宣言
* @author Sugiyama Ryo
******************************************************************************************/
#ifndef _SCENETITLE_H_
#define _SCENETITLE_H_

#include "SceneTask.h"
#include "ISceneChanger.h"
class SceneTitle : public SceneTask {

private:
	int alphaNum;
	int m_titleUIgHandle[3];
	bool m_nextSceneFlag[2];
	bool DrawTitleUIFlag;
public:
	SceneTitle(ISceneChanger* changer);
	~SceneTitle();
	    
	virtual void mInit() override;
	virtual void mUpdate() override;
	virtual void mRender() override;
	virtual void mFinal() override;
};

#endif // !_SCENETITLE_H_