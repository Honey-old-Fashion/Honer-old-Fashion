#include "Triangle.h"
#include "DxLib.h"


/*************************************************************************
* @brief コンストラクタ
* @param[in] 色, x座標, y座標
* @return None
*************************************************************************/
Triangle::Triangle(eColor _createColor, int _posX, int _posY) {
	switch (_createColor) {
	case eColor_Red:
		createColor = RED;
		thisCharType = e_charType::eTri_Red;
		break;

	case eColor_Green:
		createColor = GREEN;
		thisCharType = e_charType::eTri_Green;
		break;

	case eColor_Blue:
		createColor = BLUE;
		thisCharType = e_charType::eTri_Blue;
		break;
	}
	m_colorId = _createColor;
	m_characterPosition.x = _posX;
	m_characterPosition.y = _posY;
	floor = _posY;
}


Triangle::~Triangle()
{
}
/***********************************************
* @brief 初期化
* @param[in] None
* @return None
***********************************************/
void Triangle::mInit() {
	
}


/***********************************************
* @brief 図形の描画
* @param[in] None
* @return None
***********************************************/
void Triangle::mRender() {
	CharacterTask::mRender();
	
	DrawTriangle(
		m_characterPosition.x,
		m_characterPosition.y,
		(m_characterPosition.x + CHAR_SIZE),
		m_characterPosition.y,
		m_characterPosition.x + (CHAR_SIZE / 2),
		(m_characterPosition.y + CHAR_SIZE),
		createColor, 
		TRUE
	);
}

/***********************************************
* @brief　三角形の更新
* @param[in] None
* @return None
***********************************************/
void Triangle::mUpdate() {
	m_activeFlg = (thisCharType == gameManager->GetCurrentCharType()) ? true : false;
	collision.SetTriCharPos(m_characterPosition, m_colorId);
	if (gameManager->GetUpGimmickFlagAll().upTriFlag[m_colorId] == true) {
		m_characterPosition.y = floor - 160;
		floor = m_characterPosition.y;
		gameManager->SetUpTriFlag(m_colorId, false);
		gameManager->SetTriOnUpGimmickFlag(m_colorId, false);
	}

	if (gameManager->GetTriGoalFlag(m_colorId) != true) {
		mMove();
	}
}

/***********************************************
* @brief 終了処理
* @param[in] None
* @return None
***********************************************/
void Triangle::mFinal() {

}

/*************************************************************************
* @brief 移動処理
* @param[in]
* @return None
*************************************************************************/
void Triangle::mMove() {
	if (m_activeFlg == true) {

		if (CheckHitKey(KEY_INPUT_RIGHT) != 0 && gameManager->GetTriCanMoveRightFlag(m_colorId) == true && m_characterPosition.x <= 1100) {
			m_characterPosition.x += 3;
			if (gameManager->GetTriCanMoveLeftFlag(m_colorId) == false)
				gameManager->SetTriCanMoveLeftFlag(m_colorId, true);

		}
		if (CheckHitKey(KEY_INPUT_LEFT) != 0 && gameManager->GetTriCanMoveLeftFlag(m_colorId) == true && m_characterPosition.x >= 140) {
			m_characterPosition.x -= 3;
			if (gameManager->GetTriCanMoveRightFlag(m_colorId) == false)
				gameManager->SetTriCanMoveRightFlag(m_colorId, true);
		}
		if (gameManager->GetUpGimmickFlagAll().onUpGimmickTriFlag[m_colorId] == true) {
			m_floorY = floor - CHAR_SIZE / 2;
			if (gameManager->GetUpGimmickFlagAll().onGimmickPos.x + CHAR_SIZE <= m_characterPosition.x &&
				gameManager->GetUpGimmickFlagAll().onGimmickPos.x <= m_characterPosition.x + CHAR_SIZE ||
				gameManager->GetUpGimmickFlagAll().onGimmickPos.x >= m_characterPosition.x + CHAR_SIZE &&
				gameManager->GetUpGimmickFlagAll().onGimmickPos.x + CHAR_SIZE >= m_characterPosition.x) {
				m_characterPosition.y = floor;
				gameManager->SetTriOnUpGimmickFlag(m_colorId, false);
			}
		}
		else if (gameManager->GetFitTriFlag().gimmickPos[m_colorId].x <m_characterPosition.x && gameManager->GetFitTriFlag().gimmickPos[m_colorId].x + 5 > m_characterPosition.x) {
			m_floorY = floor + CHAR_SIZE;
		}
		else {
			m_floorY = floor;
		}
		//Jump Action
		if (m_jumpFlag == cm_neutral) {
			m_currentJumpFlag = false;
			if (CheckHitKey(KEY_INPUT_SPACE) != 0) {
				m_canJampFlag = true;
			}
			if (CheckHitKey(KEY_INPUT_SPACE) == 0 && m_canJampFlag == true) {
				m_currentJumpFlag = true;
				m_jumpFlag = cm_up;
				m_jumpSpeed = 16;
				m_canJampFlag = false;
				m_jumpTopPosition = m_characterPosition.y - 80;
			}
		}
		if (m_jumpFlag == cm_up) {
			m_characterPosition.y -= m_jumpSpeed;
			if (m_characterPosition.y <= m_jumpTopPosition) {
				m_characterPosition.y = m_jumpTopPosition;
				m_jumpFlag = cm_down;
			}
			else {
				m_jumpSpeed -= 2;
				if (m_jumpSpeed <= 0) {
					m_jumpSpeed = 1;
				}
			}

			if ((m_floorY - 30) <= m_characterPosition.y) {
				gameManager->SetTriCanMoveLeftFlag(m_colorId, false);
				gameManager->SetTriCanMoveRightFlag(m_colorId, false);
			}
			else {
				gameManager->SetTriCanMoveLeftFlag(m_colorId, true);
				gameManager->SetTriCanMoveRightFlag(m_colorId, true);
			}
		}
		else if (m_jumpFlag == cm_down) {
			m_characterPosition.y += m_jumpSpeed;

			if ((m_floorY - 30) <= m_characterPosition.y) {
				gameManager->SetTriCanMoveLeftFlag(m_colorId, false);
				gameManager->SetTriCanMoveRightFlag(m_colorId, false);
			}

			if (m_characterPosition.y >= m_floorY) {
				m_characterPosition.y = m_floorY;
				m_jumpFlag = cm_neutral;
				m_moveDownFlag = cm_neutral;
				gameManager->SetTriCanMoveLeftFlag(m_colorId, true);
				gameManager->SetTriCanMoveRightFlag(m_colorId, true);
				gameManager->SetFitTriFlag(m_colorId, false);
				gameManager->SetGimmickActiveFlag(m_colorId, true);

			}
			else {
				m_jumpSpeed += 1;
				if (m_jumpSpeed >= 56) {
					m_jumpSpeed = 56;
				}
			}
		}


		if (m_moveDownFlag == cm_neutral) {
			if (gameManager->GetFitTriFlag().fitTriDownFlag[m_colorId] == true) {
				m_moveDownFlag = cm_down;
				m_characterPosition.x = gameManager->GetFitTriFlag().gimmickPos[m_colorId].x;
			}
		}
		else if (m_moveDownFlag == cm_down) {
			gameManager->SetTriCanMoveLeftFlag(m_colorId, false);
			gameManager->SetTriCanMoveRightFlag(m_colorId, false);
			if (m_currentJumpFlag == false) m_characterPosition.y += speed;

			if (m_characterPosition.y >= gameManager->GetFitTriFlag().gimmickPos[m_colorId].y) {
				m_characterPosition.y = gameManager->GetFitTriFlag().gimmickPos[m_colorId].y;
				gameManager->SetGimmickActiveFlag(m_colorId, false);
				m_moveDownFlag = cm_up;
				fitFlag = true;
			}
		}
		else if (m_moveDownFlag = cm_up) {

		}
	}
}