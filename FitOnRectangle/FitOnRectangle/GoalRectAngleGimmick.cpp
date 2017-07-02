#include "GoalRectAngleGimmick.h"
#include "DxLib.h"


GoalRectAngleGimmick::GoalRectAngleGimmick(int _posX, int _posY) {
	pGimmick.x = _posX;
	pGimmick.y = _posY;
}

GoalRectAngleGimmick::~GoalRectAngleGimmick(){

}

void GoalRectAngleGimmick::mInit() {

}

void GoalRectAngleGimmick::mUpdate() {

}

void GoalRectAngleGimmick::mRender() {
	DrawBox(pGimmick.x, pGimmick.y, pGimmick.x + OBJECTSIZE, pGimmick.y + OBJECTSIZE, GetColor(255, 0, 0), TRUE);
	DrawString(pGimmick.x + 10, pGimmick.y + 10, _T("GOAL"), GetColor(255, 255, 255));
}

void GoalRectAngleGimmick::mFinal() {
	
}
