#include "BallGimmick.h"
#include "DxLib.h"



BallGimmick::BallGimmick(int _posX, int _posY) {
	pGimmick.x = _posX;
	pGimmick.y = _posY;

	m_amountMoveFlag = FALSE;
	m_amountMoveCnt = MOVE;

	m_color = GetColor(150, 150, 150);
	m_amountMoveFlag = TRUE;
}


BallGimmick::~BallGimmick()
{

}


void BallGimmick::mUpdate()
{
	/*
	if (m_amountMoveFlag) {
		if (pPlayer.x < pGimmick.x) {
			pGimmick.x += m_amountMoveCnt;
		}
		else {
			pGimmick.x -= m_amountMoveCnt;
		}

		m_amountMoveCnt--;

		if (m_amountMoveCnt == 0) {
			m_amountMoveFlag = FALSE;
			m_amountMoveCnt = MOVE;
		}
		else m_amountMoveFlag = TRUE;
	}

	*/

}

void BallGimmick::mRender()
{

	DrawCircleAA(pGimmick.x, pGimmick.y, OBJECTSIZE / 2, m_color, TRUE);

}