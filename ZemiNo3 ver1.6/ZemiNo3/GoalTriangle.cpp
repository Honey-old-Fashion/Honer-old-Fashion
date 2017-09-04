#include "GoalTriangle.h"
#include "DxLib.h"


GoalTriangle::GoalTriangle(eColor _createColor, int _posX, int _posY) {
	pGimmick.x = _posX;
	pGimmick.y = _posY;
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
	m_colorID = _createColor;
	_lineX = OBJECTSIZE / 2 / LINEMAX;
	_lineY = OBJECTSIZE / LINEMAX;
	_lineLength = OBJECTSIZE / LINEMAX;
}


GoalTriangle::~GoalTriangle()
{
}

void GoalTriangle::mUpdate() {
	pTri[m_colorID] = collision.GetTriPos(m_colorID);
	if (pTri[m_colorID].x >= pGimmick.x && pTri[m_colorID].y == pGimmick.y &&pTri[m_colorID].x <= pGimmick.x + (LONG)5) {
		gameManager->SetTriGoalFlag(m_colorID, true);
	}
	else {
		gameManager->SetTriGoalFlag(m_colorID, false);
	}
}

void GoalTriangle::mRender() {
		for (int ii = 0; ii < LINEMAX; ii++) {

		if (ii % 2 == 0) {
			DrawLine(
				pGimmick.x + OBJECTSIZE / LINEMAX * ii,
				pGimmick.y,
				pGimmick.x + OBJECTSIZE / LINEMAX * (ii + 1),
				pGimmick.y,
				m_color
			);

			DrawLine(
				_lineX * ii + pGimmick.x,
				_lineY * ii  + pGimmick.y,
				_lineX * (ii + 1) + pGimmick.x,
				_lineY * (ii + 1) + pGimmick.y,
				m_color
			);
			
			DrawLine(
				_lineX * ii + OBJECTSIZE - (_lineLength * ii) + pGimmick.x,
				_lineY * ii + pGimmick.y,
				_lineX * (ii + 1) + OBJECTSIZE - (_lineLength * (ii + 1)) + pGimmick.x,
				_lineY * (ii + 1) + pGimmick.y,
				m_color
			);
		}
		
	}
		DrawString(pGimmick.x + 3.5f, pGimmick.y + 7, _T("GOAL"), m_color);

}
