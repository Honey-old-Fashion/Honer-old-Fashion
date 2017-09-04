#include "GateGimmick.h"
#include "DxLib.h"
#include "GameManager.h"

GateGimmick::GateGimmick(eColor _createColor, int _posX, int _posY) {
	this->pGimmick.x = _posX;
	this->pGimmick.y = _posY;

	switch (_createColor) {

	case eColor_Red:
		m_color = GetColor(255, 0, 0);
		break;
	case eColor_Green:
		m_color = GetColor(0, 255, 0);
		break;
	case eColor_Blue:
		m_color = GetColor(0, 0, 255);
		break;
	default:
		break;
	}

	this->m_colorID = _createColor;
}


GateGimmick::~GateGimmick() {

}

void GateGimmick::mUpdate() {
	if (gameManager->GetGimmickActiveFlag(this->m_colorID) == true) {
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

			if (this->pRect[ii].y <= this->pGimmick.y && this->pRect[ii].y >= (this->pGimmick.y - (OBJECTSIZE * 2))) {
				
				if (gameManager->GetRectCanMoveLeftFlag(color) != false) {
					if (this->pRect[ii].x <= this->pGimmick.x + OBJECTSIZE && this->pRect[ii].x + OBJECTSIZE >= this->pGimmick.x + OBJECTSIZE) {
						gameManager->SetRectCanMoveLeftFlag(color, false);
					}
				}
				if (gameManager->GetRectCanMoveRightFlag(color) != false) {
					if ((this->pRect[ii].x + OBJECTSIZE) >= this->pGimmick.x && this->pRect[ii].x <= this->pGimmick.x) {
						gameManager->SetRectCanMoveRightFlag(color, false);
					}
				}
			}

			if (this->pTri[ii].y <= this->pGimmick.y && this->pTri[ii].y >= (this->pGimmick.y - (OBJECTSIZE * 2))) {

				if (gameManager->GetTriCanMoveLeftFlag(color) != false) {
					if (this->pTri[ii].x <= this->pGimmick.x + OBJECTSIZE && this->pTri[ii].x + OBJECTSIZE >= this->pGimmick.x + OBJECTSIZE) {
						gameManager->SetTriCanMoveLeftFlag(color, false);
					}
				}
				if (gameManager->GetTriCanMoveRightFlag(color) != false) {
					if ((this->pTri[ii].x + OBJECTSIZE) >= this->pGimmick.x && this->pTri[ii].x <= this->pGimmick.x) {
						gameManager->SetTriCanMoveRightFlag(color, false);
					}
				}
			}
		}
	}
}

void GateGimmick::mRender() {

	if (gameManager->GetGimmickActiveFlag(m_colorID) == true) {

		DrawBox(this->pGimmick.x, this->pGimmick.y - (OBJECTSIZE * 2),
			this->pGimmick.x + OBJECTSIZE,
			this->pGimmick.y + OBJECTSIZE,
			this->m_color, TRUE);
	}

	DrawLine(this->pGimmick.x, this->pGimmick.y + OBJECTSIZE,
		this->pGimmick.x + OBJECTSIZE,
		this->pGimmick.y + OBJECTSIZE,
		GetColor(0, 0, 0), 3);


}

POINT GimmickTask::GetPoint() {
	return pGimmick;
}