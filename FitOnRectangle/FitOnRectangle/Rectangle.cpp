#include "Rectangle.h"
#include "DxLib.h"



Rectangle::Rectangle(eColor _createColor, int _posX, int _posY){
	
	switch (_createColor) {
	case eColor_Red:
		createColor = RED;
		break;

	case eColor_Green:
		createColor = GREEN;
		break;

	case eColor_Blue:
		createColor = BLUE;
		break;
	}
	m_characterPosition.x = _posX;
	m_characterPosition.y = _posY;
}


Rectangle::~Rectangle(){

}

/***********************************************

* @brief èâä˙âª

* @param[in] None

* @return None

***********************************************/
void Rectangle::mInit() {

}

/***********************************************

* @brief éläpå`ÇÃê∂ê¨

* @param[in] êFèÓïÒ, ç∂í[ÇÃxç¿ïW, è„í[ÇÃyç¿ïW

* @return None

***********************************************
void Rectangle::mCreate(eColor _color, int _x, int _y) {

	m_rectPosition[_color].x = _x;
	m_rectPosition[_color].y = _y;
	m_livingFlg[_color] = true;
}
//*/
/***********************************************

* @brief ê}å`ÇÃï`âÊ

* @param[in] None

* @return None

***********************************************/
void Rectangle::mRender() {
	/*
	// ê‘Ç¢ê}å`ÇÃï`âÊ
	if (m_livingFlg[eColor_Red] == true) {

		DrawBox(m_rectPosition[eColor_Red].x, m_rectPosition[eColor_Red].y,
			m_rectPosition[eColor_Red].x + CHAR_SIZE, m_rectPosition[eColor_Red].y + CHAR_SIZE,
			RED, true);
	}

	// óŒÇÃê}å`ÇÃï`âÊ
	if (m_livingFlg[eColor_Green] == true) {

		DrawBox(m_rectPosition[eColor_Green].x, m_rectPosition[eColor_Green].y,
			m_rectPosition[eColor_Green].x + CHAR_SIZE, m_rectPosition[eColor_Green].y + CHAR_SIZE,
			GREEN, true);
	}

	// ê¬Ç¢ê}å`ÇÃï`âÊ
	if (m_livingFlg[eColor_Blue] == true) {

		DrawBox(m_rectPosition[eColor_Blue].x, m_rectPosition[eColor_Blue].y,
			m_rectPosition[eColor_Blue].x + CHAR_SIZE, m_rectPosition[eColor_Blue].y + CHAR_SIZE,
			BLUE, true);
	}
	*/
	DrawBox(m_characterPosition.x, m_characterPosition.y,
		m_characterPosition.x + CHAR_SIZE, m_characterPosition.y + CHAR_SIZE,
		createColor, true);
}

/***********************************************

* @brief éläpå`ÇÃçXêV

* @param[in] None

* @return None

***********************************************/
void Rectangle::mUpdate() {
	CharacterTask::mMove();
}

/***********************************************

* @brief èIóπèàóù

* @param[in] None

* @return None

***********************************************/
void Rectangle::mFinal() {

}