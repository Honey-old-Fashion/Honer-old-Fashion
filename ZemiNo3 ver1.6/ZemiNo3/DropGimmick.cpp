#include "DropGimmick.h"

#define LINEMAX 10

DropGimmick::DropGimmick(int _posX, int _posY) {
	pGimmick.x = _posX;
	pGimmick.y = _posY;
	m_color = GetColor(0, 0, 0);
}

DropGimmick::~DropGimmick() {

}

void DropGimmick::mUpdate() {
	eColor color;
	for (int ii = 0; ii < COLOR_NUM; ii++) {
		switch (ii) {
		case 0:
			color = eColor_Red;
			break;
		case 1:
			color = eColor_Green;
			break;
		case 2:
			color = eColor_Blue;
			break;
		default:
			break;
		}

		this->pRect[ii] = collision.GetRectPos(color);
		this->pTri[ii] = collision.GetTriPos(color);

		if (pRect[ii].y + OBJECTSIZE == pGimmick.y && pRect[ii].x >= pGimmick.x && pRect[ii].x <= pGimmick.x + 5 && gameManager->GetGimmickActiveFlag(color) == true) {
			gameManager->SetRectDropFlag(color, true, pGimmick);
		}

	}
}

void DropGimmick::mRender() {

	/*if (activeFlag) {

		DrawLine(pGimmick.x, pGimmick.y + OBJECTSIZE,
			pGimmick.x + OBJECTSIZE,
			pGimmick.y + OBJECTSIZE,
			m_color);
	}
	else {*/
		int LineLength;

		// â°ê¸
		LineLength = OBJECTSIZE / LINEMAX;

		for (int ii = 0; ii < LINEMAX; ii++) {
			if (ii % 2 == 0) {
				// è„ê¸
				DrawLine(pGimmick.x + LineLength * ii, pGimmick.y,
					pGimmick.x + LineLength * (ii + 1), pGimmick.y, m_color);
				// â∫ê¸
				DrawLine(pGimmick.x, pGimmick.y + OBJECTSIZE,
					pGimmick.x + OBJECTSIZE, pGimmick.y + OBJECTSIZE, m_color);
			}
		}

		// ècê¸
		LineLength = OBJECTSIZE / LINEMAX;

		for (int ii = 0; ii < LINEMAX; ii++) {
			if (ii % 2 == 0) {
				// ç∂ê¸
				DrawLine(pGimmick.x, pGimmick.y,
					pGimmick.x, pGimmick.y + OBJECTSIZE, m_color);
				// âEê¸
				DrawLine(pGimmick.x + OBJECTSIZE, pGimmick.y,
					pGimmick.x + OBJECTSIZE, pGimmick.y + OBJECTSIZE, m_color);
			}
		}
	//}	
}