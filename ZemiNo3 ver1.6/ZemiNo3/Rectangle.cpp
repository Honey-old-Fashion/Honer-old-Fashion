#include "Rectangle.h"
#include "DxLib.h"
#include "GameManager.h"

/***********************************************
* @brief コンストラクタ
* @param[in] 色, x座標, y座標
* @return None
***********************************************/
Rectangle::Rectangle(eColor _createColor, int _posX, int _posY) {

	switch (_createColor) {
	case eColor_Red:
		createColor = RED;
		thisCharType = e_charType::eRect_Red;
		break;

	case eColor_Green:
		createColor = GREEN;
		thisCharType = e_charType::eRect_Green;
		break;

	case eColor_Blue:
		createColor = BLUE;
		thisCharType = e_charType::eRect_Blue;
		break;
	}
	m_colorId = _createColor;
	m_characterPosition.x = _posX;
	m_characterPosition.y = _posY;
	floor = _posY;
}

Rectangle::~Rectangle() {

}

/***********************************************
* @brief 初期化
* @param[in] None
* @return None
***********************************************/
void Rectangle::mInit() {

}

/***********************************************
* @brief 図形の描画
* @param[in] None
* @return None
***********************************************/
void Rectangle::mRender() {
	CharacterTask::mRender();
	DrawBox(m_characterPosition.x, m_characterPosition.y,
		m_characterPosition.x + CHAR_SIZE, m_characterPosition.y + CHAR_SIZE,
		createColor, true);
}

/***********************************************
* @brief 四角形の更新
* @param[in] None
* @return None
***********************************************/
void Rectangle::mUpdate() {
	m_activeFlg = (thisCharType == gameManager->GetCurrentCharType()) ? true : false;
	collision.SetRectCharPos(m_characterPosition, m_colorId);

	if (gameManager->GetUpGimmickFlagAll().upRectFlag[m_colorId] == true){
		m_characterPosition.y = floor - 160;
		floor = m_characterPosition.y;
		gameManager->SetUpRectFlag(m_colorId, false);
		gameManager->SetRectOnUpGimmickFlag(m_colorId, false);
	}
	if (gameManager->GetRectGoalFlag(m_colorId) != true) {
		this->mMove();
	}
	
#ifdef _DEBUG
	printfDx(" %d ", m_floorY);
	printfDx("%d", m_characterPosition.y);
#endif // _DEBUG

}

/***********************************************
* @brief 終了処理
* @param[in] None
* @return None
***********************************************/
void Rectangle::mFinal() {

}

/***********************************************
* @brief 終了処理
* @param[in] None
* @return None
***********************************************/
void Rectangle::mMove() {
	if (m_activeFlg == true) {
		//move Right
		if (CheckHitKey(KEY_INPUT_RIGHT) != 0 && gameManager->GetRectCanMoveRightFlag(m_colorId) == true && m_characterPosition.x <= 1100) {
			m_characterPosition.x += 3;
			if (gameManager->GetRectCanMoveLeftFlag(m_colorId) == false)
				gameManager->SetRectCanMoveLeftFlag(m_colorId, true);

		}

		//Move Left
		if (CheckHitKey(KEY_INPUT_LEFT) != 0 && gameManager->GetRectCanMoveLeftFlag(m_colorId) == true && m_characterPosition.x >= 140) {
			m_characterPosition.x -= 3;
			if (gameManager->GetRectCanMoveRightFlag(m_colorId) == false)
				gameManager->SetRectCanMoveRightFlag(m_colorId, true);
		}

		if (gameManager->GetUpGimmickFlagAll().onUpGimmickRectFlag[m_colorId] == true) {
			m_floorY = floor - CHAR_SIZE / 2;
			if (gameManager->GetUpGimmickFlagAll().onGimmickPos.x + CHAR_SIZE < m_characterPosition.x &&
				gameManager->GetUpGimmickFlagAll().onGimmickPos.x < m_characterPosition.x + CHAR_SIZE ||
				gameManager->GetUpGimmickFlagAll().onGimmickPos.x > m_characterPosition.x + CHAR_SIZE &&
				gameManager->GetUpGimmickFlagAll().onGimmickPos.x + CHAR_SIZE > m_characterPosition.x) {
				m_floorY = floor;
				m_characterPosition.y = m_floorY;
 				gameManager->SetRectOnUpGimmickFlag(m_colorId, false);
			}	
			
		}
		else if (gameManager->GetDropDataAll().dorpRectFlag[m_colorId] == true) {
			dropFloor = floor + CHAR_SIZE * 4;
			m_floorY = dropFloor;
			m_dropFlag = true;
		}
		else if (gameManager->GetFitRectFlag().gimmickPos[m_colorId].x < m_characterPosition.x && gameManager->GetFitRectFlag().gimmickPos[m_colorId].x + 5 > m_characterPosition.x) {
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
				gameManager->SetGimmickActiveFlag(m_colorId, true);
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
				gameManager->SetRectCanMoveLeftFlag(m_colorId, false);
				gameManager->SetRectCanMoveRightFlag(m_colorId, false);
			}
			else {
				gameManager->SetRectCanMoveLeftFlag(m_colorId, true);
				gameManager->SetRectCanMoveRightFlag(m_colorId, true);
			}
		}
		else if (m_jumpFlag == cm_down) {
			m_characterPosition.y += m_jumpSpeed;

			if ((m_floorY - 30) <= m_characterPosition.y) {
				gameManager->SetRectCanMoveLeftFlag(m_colorId, false);
				gameManager->SetRectCanMoveRightFlag(m_colorId, false);
			}

			if (m_characterPosition.y >= m_floorY) {
				m_characterPosition.y = m_floorY;
				m_jumpFlag = cm_neutral;
				m_moveDownFlag = cm_neutral;
				gameManager->SetRectCanMoveLeftFlag(m_colorId, true);
				gameManager->SetRectCanMoveRightFlag(m_colorId, true);
				gameManager->SetFitRectFlag(m_colorId, false);

			}
			else {
				m_jumpSpeed += 1;
				if (m_jumpSpeed >= 56) {
					m_jumpSpeed = 56;
				}
			}
		}


		if (m_moveDownFlag == cm_neutral) {
			if (gameManager->GetFitRectFlag().fitRectDownFlag[m_colorId] == true) {
				m_moveDownFlag = cm_down;
				m_characterPosition.x = gameManager->GetFitRectFlag().gimmickPos[m_colorId].x;
			}
		}
		else if (m_moveDownFlag == cm_down) {
			gameManager->SetRectCanMoveLeftFlag(m_colorId, false);
			gameManager->SetRectCanMoveRightFlag(m_colorId, false);
			if (m_currentJumpFlag == false) m_characterPosition.y += speed;

			if (m_characterPosition.y >= gameManager->GetFitRectFlag().gimmickPos[m_colorId].y) {
				m_characterPosition.y = gameManager->GetFitRectFlag().gimmickPos[m_colorId].y;
				m_characterPosition.x = gameManager->GetFitRectFlag().gimmickPos[m_colorId].x;
				gameManager->SetGimmickActiveFlag(m_colorId, false);
				m_moveDownFlag = cm_up;
				fitFlag = true;
			}
		}
		else if (m_moveDownFlag = cm_up) {

		}

		if (m_dropFlag == true) {
			if (m_characterPosition.y < m_floorY) {
				m_characterPosition.y += dropSpeed;
				dropSpeed++;
				if (m_characterPosition.y >= m_floorY) {
					
					m_dropFlag = false;
					floor += CHAR_SIZE * 4;
					m_floorY = floor;
					m_characterPosition.y = m_floorY;
					gameManager->SetRectDropFlag(m_colorId, false);
					dropSpeed = 0;				
				}
			}
		}
	}
}
