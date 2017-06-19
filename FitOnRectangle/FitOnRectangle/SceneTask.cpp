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
* @brief  ボタンUIを表示させる関数
* @param  左上のx座標、左上のy座標、横の長さ、縦の長さ、表示するテキスト、ボタンのカラー、テキストのカラー
* @return TRUE ; FALSE
*******************************************************/
BOOL SceneTask::mDrawSelectBox(int _x, int _y, int _width, int _height, LPCTSTR _text, bool _clickFlag, int _buttonColor, int _textColor) {

	int textSize;
	int fontHandle;
	
	if (_clickFlag == true) {
		int mouseX;
		int mouseY;
		GetMousePoint(&mouseX, &mouseY);

		if (mouseX > _x && mouseX < _x + _width && mouseY > _y && mouseY < _y + _height) {
			if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
				return true;
			}
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 / 2);
		}
	}
	DrawBox(_x, _y, _x + _width, _y + _height, _buttonColor, TRUE);
	
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	
	if (_text != NULL) {
		textSize = strlen(_text);
		fontHandle = CreateFontToHandle(NULL, _width / textSize, 4, DX_FONTTYPE_EDGE);
		DrawStringToHandle(_x + _width / textSize, _y + _height / 3, _text, _textColor, fontHandle);
		DeleteFontToHandle(fontHandle);
	}

	return false;
}
