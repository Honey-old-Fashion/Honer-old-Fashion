#include "hamaru.h"
#include "DxLib.h"

hamaru::hamaru(eColor _createColor, int _posX, int _posY) {
	pGimmick.x = _posX;
	pGimmick.y = _posY;
	switch (_createColor) {
	case eColor_Red:
		m_color = RED;
		break;
	case eColor_Green:
		m_color = GREEN;
		break;
	case eColor_Blue:
		m_color = BLUE;
		break;
	default:
		break;
	}
}

hamaru::~hamaru() {

}

void hamaru::mRender() {

		DrawLine(pGimmick.x, pGimmick.y, pGimmick.x, pGimmick.y + OBJECTSIZE, m_color);
		DrawLine(pGimmick.x, pGimmick.y + OBJECTSIZE, pGimmick.x + OBJECTSIZE, pGimmick.y + OBJECTSIZE, m_color);
		DrawLine(pGimmick.x + OBJECTSIZE, pGimmick.y, pGimmick.x + OBJECTSIZE, pGimmick.y + OBJECTSIZE, m_color);
	
}
