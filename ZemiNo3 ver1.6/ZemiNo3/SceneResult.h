/**********************************************************************************************
* !@file  SceneResult.h
* @brief  ���U���g�V�[���̐錾
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
	int m_clearTime;   // �N���A���Ԃ��i�[����ϐ�
	int m_timeTextX;   // �e�L�X�g�̍��W
	int m_rankTextX;
	int m_textFlag;    // �A�j���[�V�����𐧌䂷�邽�߂�Flag
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