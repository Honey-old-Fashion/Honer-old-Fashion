/**********************************************************************************************
* !@file  SceneResult.h
* @brief  リザルトシーンの宣言
* @author Takaguchi Tsuyoshi
******************************************************************************************/
#ifndef SCENERESULT_H
#define SCENERESULT_H

#include "SceneTask.h"
#include "ISceneChanger.h"
#include "Timer.h"
#include "GameManager.h"

class SceneResult : public SceneTask {

private:
	int alphaNum;
	int m_clearTime;   // クリア時間を格納する変数
	int m_timeTextX;   // テキストの座標
	int m_rankTextX;
	int m_textFlag;    // アニメーションを制御するためのFlag
	int m_resultUIgHandle[3];
	int m_getMouseX;   // マウスのx座標を取得して格納する変数
	int m_getMouseY;   // マウスのy座標を取得して格納する変数
	int m_fontHandle;
	bool m_keyFlag;    // キー入力の状態のフラグ

	Timer* time;
public:
	SceneResult(ISceneChanger* changer);
	~SceneResult();

	virtual void mInit() override;
	virtual void mUpdate() override;
	virtual void mRender() override;
	virtual void mFinal() override;
};

#endif // !SCENERESULT_H