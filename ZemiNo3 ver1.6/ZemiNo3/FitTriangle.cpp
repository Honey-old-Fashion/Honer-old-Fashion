#include "FitTriangle.h"



FitTriangle::FitTriangle(eColor _createColor, int _posX, int _posY) {
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

	pGimmick.x = _posX;
	pGimmick.y = _posY;
	m_colorID = _createColor;
}


FitTriangle::~FitTriangle() {

}

void FitTriangle::mUpdate() {
	pTri[m_colorID] = collision.GetTriPos(m_colorID);
	if (pTri[m_colorID].x >= pGimmick.x && pTri[m_colorID].x <= pGimmick.x + 5 && pTri[m_colorID].y + OBJECTSIZE == pGimmick.y) {
		gameManager->SetFitTriFlag(m_colorID, true, pGimmick);
	}
}


void FitTriangle::mRender() {
	if (gameManager->GetFitTriFlag().fitTriDownFlag[m_colorID] != true) {

		DrawBox(pGimmick.x, pGimmick.y,
			pGimmick.x + OBJECTSIZE, pGimmick.y + OBJECTSIZE,
			mBlack, TRUE);
		DrawTriangle(pGimmick.x, pGimmick.y,
			(pGimmick.x + OBJECTSIZE), pGimmick.y,
			pGimmick.x + (OBJECTSIZE / 2), (pGimmick.y + OBJECTSIZE),
			mWhite, TRUE);
	}
	DrawLine((int)pGimmick.x, (int)pGimmick.y, (int)(pGimmick.x + (OBJECTSIZE / 2) ), (int)(pGimmick.y + OBJECTSIZE), createColor ,2.0f);
	DrawLine((int)(pGimmick.x + OBJECTSIZE), (int)pGimmick.y, (int)(pGimmick.x + (OBJECTSIZE / 2)), (int)(pGimmick.y + OBJECTSIZE), createColor, 2.0f);
	DrawTriangle((int)pGimmick.x, (int)pGimmick.y, (int)(pGimmick.x + (OBJECTSIZE / 2)), (int)(pGimmick.y + OBJECTSIZE), pGimmick.x, (pGimmick.y + OBJECTSIZE), mBlack, TRUE);
	DrawTriangle((int)(pGimmick.x + OBJECTSIZE), (int)pGimmick.y, (int)(pGimmick.x + (OBJECTSIZE / 2)), (int)(pGimmick.y + OBJECTSIZE), pGimmick.x + OBJECTSIZE, (pGimmick.y + OBJECTSIZE), mBlack, TRUE);
	/*
	DrawTriangle(pGimmick.x, pGimmick.y,
		(pGimmick.x + OBJECTSIZE), pGimmick.y,
		pGimmick.x + (OBJECTSIZE / 2), (pGimmick.y + OBJECTSIZE),
		createColor, FALSE);
		*/
}
