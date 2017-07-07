#include "BallGimmick.h"
#include "DxLib.h"



BallGimmick::BallGimmick(int _posX,int _posY)
{
	m_amountMoveFlag = FALSE;
	m_amountMoveCnt = MOVE;

	m_color = GetColor(255, 255, 255);
}


BallGimmick::~BallGimmick()
{
	
}


void BallGimmick::mUpdate()
{

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