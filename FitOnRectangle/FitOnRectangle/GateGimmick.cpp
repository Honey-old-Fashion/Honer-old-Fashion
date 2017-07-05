#include "GateGimmick.h"
#include "DxLib.h"


GateGimmick::GateGimmick(eColor _createColor, int _posX, int _posY) {
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


GateGimmick::~GateGimmick() {

}



void GateGimmick::mRender() {

	if (activeFlag == true) {

		DrawBox(pGimmick.x, pGimmick.y,
			pGimmick.x + OBJECTSIZE,
			pGimmick.y + OBJECTSIZE,
			m_color, TRUE);
	}
	else {

		DrawLine(pGimmick.x, pGimmick.y + OBJECTSIZE,
			pGimmick.x + OBJECTSIZE,
			pGimmick.y + OBJECTSIZE,
			GetColor(255, 255, 255));
	}

}
