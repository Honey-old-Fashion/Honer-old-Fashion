#include "BallGimmick.h"



BallGimmick::BallGimmick()
{
	this->mInit();
}


BallGimmick::~BallGimmick()
{
	this->mFinal();
}

void BallGimmick::mInit()
{
	m_amountMoveFlag = FALSE;
	m_amountMoveCnt = MOVE;
}

void BallGimmick::mUpdate()
{

	if (mHitTest() == TRUE)
		m_amountMoveFlag = TRUE;

	
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
	}



}

void BallGimmick::mRender()
{

	DrawCircle(pGimmick.x, pGimmick.y, OBJECTSIZE / 2, m_color, TRUE);

}

void BallGimmick::mFinal()
{

}

bool BallGimmick::mHitTest() {

	if (pPlayer.x + OBJECTSIZE == pGimmick.x - OBJECTSIZE / 2 && pPlayer.y > pGimmick.y + OBJECTSIZE / 2 ||
		pPlayer.x == pGimmick.x + OBJECTSIZE / 2 && pPlayer.y > pGimmick.y + OBJECTSIZE / 2) {
		return TRUE;
	}
	else {
		return FALSE;
	}

}