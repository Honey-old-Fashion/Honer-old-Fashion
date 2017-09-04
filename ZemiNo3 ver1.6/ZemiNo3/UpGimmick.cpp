#include "UpGimmick.h"
#include "GameManager.h"


UpGimmick::UpGimmick(eColor _createColor, int _posX, int _posY) {

	pGimmick.x = _posX;
	pGimmick.y = _posY;

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
	m_colorID = _createColor;
}


UpGimmick::~UpGimmick() {

}

void UpGimmick::mUpdate() {
	eColor color;
	if (gameManager->GetGimmickActiveFlag(m_colorID) != true) {

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
			//Rect
			if (gameManager->GetUpGimmickFlagAll().onUpGimmickRectFlag[color] == true && gameManager->GetUpGimmickFlagAll().upReadyGimmickFlag[m_colorID] == true) {
				gameManager->SetUpRectFlag(color, true);
			}

			if (gameManager->GetUpGimmickFlagAll().onUpGimmickTriFlag[color] == true) {
				gameManager->SetUpTriFlag(color, true);
			}

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

			//Tri
			if (gameManager->GetUpGimmickFlagAll().onUpGimmickTriFlag[color] == true && gameManager->GetUpGimmickFlagAll().upReadyGimmickFlag[m_colorID] == true) {
				gameManager->SetUpTriFlag(color, true);
			}

			if (gameManager->GetUpGimmickFlagAll().onUpGimmickTriFlag[color] == true) {
				gameManager->SetUpTriFlag(color, true);
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
	else {
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

			//Rect
			if (pRect[ii].y + OBJECTSIZE >= pGimmick.y && pRect[ii].x + OBJECTSIZE > pGimmick.x && pRect[ii].x < pGimmick.x + OBJECTSIZE) {
				gameManager->SetRectOnUpGimmickFlag(color, m_colorID, true, pGimmick);
			}

			if (pTri[ii].y >= pGimmick.y + (OBJECTSIZE / 2) && pTri[ii].x >= pGimmick.x && pTri[ii].x <= pGimmick.x + 5) {
				gameManager->SetTriOnUpGimmickFlag(color, m_colorID, true, pGimmick);
			}

			if (pRect[ii].y >= pGimmick.y && pRect[ii].y <= (pGimmick.y + (OBJECTSIZE / 2))) {

				if (gameManager->GetRectCanMoveLeftFlag(color) != false) {
					if (this->pRect[ii].x < this->pGimmick.x + OBJECTSIZE && this->pRect[ii].x + OBJECTSIZE > this->pGimmick.x + OBJECTSIZE) {
						gameManager->SetRectCanMoveLeftFlag(color, false);
					}
				}
				if (gameManager->GetRectCanMoveRightFlag(color) != false) {
					if ((this->pRect[ii].x + OBJECTSIZE) >= this->pGimmick.x && this->pRect[ii].x <= this->pGimmick.x) {
						gameManager->SetRectCanMoveRightFlag(color, false);
					}
				}
			}

			//Tri
			if (pTri[ii].y + OBJECTSIZE >= pGimmick.y && pTri[ii].x + OBJECTSIZE > pGimmick.x && pTri[ii].x < pGimmick.x + OBJECTSIZE) {
				gameManager->SetTriOnUpGimmickFlag(color, m_colorID, true, pGimmick);
			}

			if (pTri[ii].y >= pGimmick.y + (OBJECTSIZE / 2) && pTri[ii].x >= pGimmick.x && pTri[ii].x <= pGimmick.x + 5) {
				gameManager->SetTriOnUpGimmickFlag(color, m_colorID, true, pGimmick);
			}

			if (pTri[ii].y >= pGimmick.y && pTri[ii].y <= (pGimmick.y + (OBJECTSIZE / 2))) {

				if (gameManager->GetTriCanMoveLeftFlag(color) != false) {
					if (this->pTri[ii].x < this->pGimmick.x + OBJECTSIZE && this->pTri[ii].x + OBJECTSIZE > this->pGimmick.x + OBJECTSIZE) {
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

void UpGimmick::mRender() {		
	if (gameManager->GetGimmickActiveFlag(m_colorID) == true) {
		DrawBox(pGimmick.x, pGimmick.y + OBJECTSIZE / 2,
			pGimmick.x + OBJECTSIZE,
			pGimmick.y + OBJECTSIZE,
			m_color, TRUE);
	} 
	else {
		DrawBox(pGimmick.x, pGimmick.y - OBJECTSIZE * 3,
			pGimmick.x + OBJECTSIZE,
			pGimmick.y + OBJECTSIZE,
			m_color, TRUE);
	}
	DrawLine(pGimmick.x, pGimmick.y + OBJECTSIZE,
		pGimmick.x + OBJECTSIZE,
		pGimmick.y + OBJECTSIZE,
		GetColor(0, 0, 0), 3);
}