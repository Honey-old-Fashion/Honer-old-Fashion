#include "SceneTask.h"
#include "DxLib.h"
#include <string>

SceneTask::SceneTask(ISceneChanger* _changer) :mGraphicHandle(0) {

	m_changeScene = _changer;
}

void SceneTask::mFinal() {

	DeleteGraph(mGraphicHandle);
	mSoundPlayFlag = CheckSoundMem(mSoundPlayHandle);
	if (mSoundPlayFlag == 1) {
		mSoundPlayFlag = 0;
		StopSoundMem(mSoundPlayHandle);
		DeleteSoundMem(mSoundPlayHandle);
	}
}

void SceneTask::mRender() {

	DrawExtendGraph(0, 0, 1279, 719, mGraphicHandle, FALSE);

	mSoundPlayFlag = CheckSoundMem(mSoundPlayHandle);
	if (mSoundPlayFlag == 0) {
		PlaySoundMem(mSoundPlayHandle, DX_PLAYTYPE_LOOP, TRUE);
		mSoundPlayFlag = 1;
	}
}

/******************************************************
* @brief  �{�^��UI��\��������֐�
* @param  �����x���W�A�����y���W�A���̒����A�c�̒����A�O���t�B�b�N�n���h���A�}�E�X�J�[�\���̎擾
* @return TRUE ; FALSE
*******************************************************/
BOOL SceneTask::mDrawSelectBox(int _x, int _y, int _width, int _height, int _gHandle, bool _clickFlag) {

	if (_clickFlag == true) {
		int mouseX;
		int mouseY;
		GetMousePoint(&mouseX, &mouseY);	

		if (mouseX > _x && mouseX < _x + _width && mouseY > _y && mouseY < _y + _height) {
			if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
				return true;
			}
			SetDrawBlendMode(DX_BLENDMODE_SUB, 255);
		}
	}
	DrawExtendGraph(_x, _y, _x + _width, _y + _height, _gHandle, TRUE);
	
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	
	return false;
}
