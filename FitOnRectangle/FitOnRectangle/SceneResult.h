/**********************************************************************************************
* !@file  SceneResult.h
* @brief  リザルトシーンの宣言
* @author Takatsu Yuta
******************************************************************************************/
#ifndef SCENERESULT_H
#define SCENERESULT_H

#include "SceneTask.h"
#include "ISceneChanger.h"
class SceneResult : public SceneTask {

private:
	int alphaNum;
	bool m_nextSceneFlag[2];
public:
	SceneResult(ISceneChanger* changer);
	~SceneResult();

	virtual void mInit() override;
	virtual void mUpdate() override;
	virtual void mRender() override;
	virtual void mFinal() override;
};

#endif // !SCENERESULT_H