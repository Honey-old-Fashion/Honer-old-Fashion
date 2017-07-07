#include "UpGimmick.h"



UpGimmick::UpGimmick(eColor _createColor,int _posX,int _posY)
{
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


UpGimmick::~UpGimmick()
{
}

void UpGimmick::mRender()
{
	if (activeFlag) {
		DrawBox(pGimmick.x, pGimmick.y / 2,
			pGimmick.x + OBJECTSIZE,
			pGimmick.y/2,
			m_color, TRUE);
	}
	else {
		DrawBox(pGimmick.x, pGimmick.y+OBJECTSIZE*2,
			pGimmick.x + OBJECTSIZE,
			pGimmick.y + OBJECTSIZE * 2,
			m_color, TRUE);
	}

}