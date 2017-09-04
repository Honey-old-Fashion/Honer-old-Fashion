/**********************************************************************************************
* !@file  SceneResult.h
* @brief  ���U���g�V�[���̐錾
* @author Takatsu Yuta
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
	int m_clearTime;
	int m_timeTextX;
	int m_rankTextX;
	int m_textFlag;
	int m_resultUIgHandle[3];
	int m_getMouseX;   // �}�E�X��x���W���擾���Ċi�[����ϐ�
	int m_getMouseY;   // �}�E�X��y���W���擾���Ċi�[����ϐ�
	int m_fontHandle;
	bool m_keyFlag;    // �L�[���͂̏�Ԃ̃t���O

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