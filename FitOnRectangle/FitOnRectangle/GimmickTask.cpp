#include "GimmickTask.h"



GimmickTask::GimmickTask()
{
}


GimmickTask::~GimmickTask()
{
}

void GimmickTask::mSetPlayerPointVecter2(POINT _pPlayer,int _color) {

	pPlayer.x = _pPlayer.x;
	pPlayer.y = _pPlayer.y;
	m_color = _color;
}

bool GimmickTask::mHitTest() {

	if (pPlayer.x + OBJECTSIZE == pGimmick.x || pPlayer.x == pGimmick.x + OBJECTSIZE)return TRUE;
	else return FALSE;


}
