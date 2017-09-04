#include "FitRect.h"
#include "DxLib.h"

FitRect::FitRect(eColor _createColor, int _posX, int _posY) {

	switch (_createColor) {
	case eColor_Red:
		m_color = RED;
		break;
	case eColor_Green:
		m_color = GREEN;
		break;
	case eColor_Blue:
		m_color = BLUE;
		break;
	default:
		break;
	}
	pGimmick.x = _posX;
	pGimmick.y = _posY;
	m_colorID = _createColor;

}

FitRect::~FitRect() {

}

void FitRect::mUpdate() {
	pRect[m_colorID] = collision.GetRectPos(m_colorID);
	if (pRect[m_colorID].x >= pGimmick.x && pRect[m_colorID].x <= pGimmick.x + 5 && pRect[m_colorID].y + OBJECTSIZE == pGimmick.y) {
		gameManager->SetFitRectFlag(m_colorID, true, pGimmick);
	}
}

void FitRect::mRender() {
	if (gameManager->GetFitRectFlag().fitRectDownFlag[m_colorID] != true) {
		DrawBox(pGimmick.x, pGimmick.y, pGimmick.x + OBJECTSIZE, pGimmick.y + OBJECTSIZE, GetColor(255, 255, 255), TRUE);
	}
	DrawLine(pGimmick.x, pGimmick.y, pGimmick.x, pGimmick.y + OBJECTSIZE, m_color,3);
	DrawLine(pGimmick.x, pGimmick.y + OBJECTSIZE - 2, pGimmick.x + OBJECTSIZE, pGimmick.y + OBJECTSIZE - 2, m_color,3);
	DrawLine(pGimmick.x + OBJECTSIZE - 1, pGimmick.y, pGimmick.x + OBJECTSIZE - 1, pGimmick.y + OBJECTSIZE, m_color,3);
	
}
