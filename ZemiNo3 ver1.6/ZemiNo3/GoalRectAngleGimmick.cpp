#include "GoalRectAngleGimmick.h"
#include "DxLib.h"

GoalRectAngleGimmick::GoalRectAngleGimmick(eColor _createColor, int _posX, int _posY) {
	switch (_createColor) {
	case eColor_Red:
		createColor = RED;
		break;

	case eColor_Green:
		createColor = GREEN;
		break;

	case eColor_Blue:
		createColor = BLUE;
		break;
	}
	m_colorID = _createColor;
	pGimmick.x = _posX;
	pGimmick.y = _posY;
}

GoalRectAngleGimmick::~GoalRectAngleGimmick(){

}

void GoalRectAngleGimmick::mInit() {

}

void GoalRectAngleGimmick::mUpdate() {
	pRect[m_colorID] = collision.GetRectPos(m_colorID);
	if (pRect[m_colorID].x >= pGimmick.x && pRect[m_colorID].y == pGimmick.y && pRect[m_colorID].x <= pGimmick.x + (LONG)5) {
		gameManager->SetRectGoalFlag(m_colorID, true);
	}
	else {
		gameManager->SetRectGoalFlag(m_colorID, false);
	}
}

void GoalRectAngleGimmick::mRender() {
	int LineLength;

	// â°ê¸
	LineLength = OBJECTSIZE / LINEMAX;

	for (int ii = 0; ii < LINEMAX; ii++) {
		if (ii % 2 == 0) {
			// è„ê¸
			DrawLine(pGimmick.x + LineLength * ii, pGimmick.y,
				pGimmick.x + LineLength * (ii + 1), pGimmick.y, createColor);
			// â∫ê¸
			DrawLine(pGimmick.x + LineLength * ii, pGimmick.y + OBJECTSIZE,
				pGimmick.x + LineLength * (ii + 1), pGimmick.y + OBJECTSIZE, createColor);
		}
	}

	// ècê¸
	LineLength = OBJECTSIZE / LINEMAX;

	for (int ii = 0; ii < LINEMAX; ii++) {
		if (ii % 2 == 0) {
			// ç∂ê¸
			DrawLine(pGimmick.x, pGimmick.y + LineLength * ii,
				pGimmick.x, pGimmick.y + LineLength * (ii + 1), createColor);
			// âEê¸
			DrawLine(pGimmick.x + OBJECTSIZE, pGimmick.y + LineLength * ii,
				pGimmick.x + OBJECTSIZE, pGimmick.y + LineLength * (ii + 1), createColor);
		}
	}	DrawString(pGimmick.x + 3.5f, pGimmick.y + 7, _T("GOAL"), createColor);
}

void GoalRectAngleGimmick::mFinal() {
	
}
