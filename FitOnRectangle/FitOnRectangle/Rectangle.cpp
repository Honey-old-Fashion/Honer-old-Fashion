#include "Rectangle.h"
#include "DxLib.h"



Rectangle::Rectangle(){
	for (int i = 0; i < COLOR_NUM; i++) {
		m_rectPosition[i].x = 0;
		m_rectPosition[i].y = 0;
		m_livingFlg[i] = false;
	}
}


Rectangle::~Rectangle(){

}

/***********************************************

* @brief ‰Šú‰»

* @param[in] None

* @return None

***********************************************/
void Rectangle::mInit() {

}

/***********************************************

* @brief ŽlŠpŒ`‚Ì¶¬

* @param[in] Fî•ñ, ¶’[‚ÌxÀ•W, ã’[‚ÌyÀ•W

* @return None

***********************************************/
void Rectangle::mCreate(eColor _color, int _x, int _y) {

	m_rectPosition[_color].x = _x;
	m_rectPosition[_color].y = _y;
	m_livingFlg[_color] = true;
}

/***********************************************

* @brief }Œ`‚Ì•`‰æ

* @param[in] None

* @return None

***********************************************/
void Rectangle::mRender() {
	// Ô‚¢}Œ`‚Ì•`‰æ
	if (m_livingFlg[eColor_Red] == true) {

		DrawBox(m_rectPosition[eColor_Red].x, m_rectPosition[eColor_Red].y,
			m_rectPosition[eColor_Red].x + CHAR_SIZE, m_rectPosition[eColor_Red].y + CHAR_SIZE,
			RED, true);
	}

	// —Î‚Ì}Œ`‚Ì•`‰æ
	if (m_livingFlg[eColor_Green] == true) {

		DrawBox(m_rectPosition[eColor_Green].x, m_rectPosition[eColor_Green].y,
			m_rectPosition[eColor_Green].x + CHAR_SIZE, m_rectPosition[eColor_Green].y + CHAR_SIZE,
			GREEN, true);
	}

	// Â‚¢}Œ`‚Ì•`‰æ
	if (m_livingFlg[eColor_Blue] == true) {

		DrawBox(m_rectPosition[eColor_Blue].x, m_rectPosition[eColor_Blue].y,
			m_rectPosition[eColor_Blue].x + CHAR_SIZE, m_rectPosition[eColor_Blue].y + CHAR_SIZE,
			BLUE, true);
	}
}

/***********************************************

* @brief ŽlŠpŒ`‚ÌXV

* @param[in] None

* @return None

***********************************************/
void Rectangle::mUpdate() {

}

/***********************************************

* @brief I—¹ˆ—

* @param[in] None

* @return None

***********************************************/
void Rectangle::mFinal() {

}