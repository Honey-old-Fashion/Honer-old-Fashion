#include "GateGimmick.h"



GateGimmick::GateGimmick()
{
	this->mInit();
}


GateGimmick::~GateGimmick()
{
	this->mFinal();
}

void GateGimmick::mInit()
{

}

void GateGimmick::mUpdate()
{


}

void GateGimmick::mRender()
{

	if (m_gimmickOpenFlag) {
		DrawBox(pGimmick.x, pGimmick.y,
			pGimmick.x + OBJECTSIZE,
			pGimmick.y + OBJECTSIZE,
			m_color, TRUE);
	}

}

void GateGimmick::mFinal()
{

}

