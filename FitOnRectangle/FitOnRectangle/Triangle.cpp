#include "Triangle.h"
#include "DxLib.h"



Triangle::Triangle()
{
}


Triangle::~Triangle()
{
}
/***********************************************

* @brief ϊ»

* @param[in] None

* @return None

***********************************************/
void Triangle::mInit() {

}

/***********************************************

* @brief Op`ΜΆ¬

* @param[in] Fξρ, Έ_ΜxΐW, Έ_ΜyΐW

* @return None

***********************************************/
void Triangle::mCreate(eColor _color, int _x, int _y) {

	m_triPosition[_color].x = _x;
	m_triPosition[_color].y = _y;
	m_livingFlg[_color] = true;
}

/***********************************************

* @brief }`Μ`ζ

* @param[in] None

* @return None

***********************************************/
void Triangle::mRender() {
	// Τ’}`Μ`ζ
	if (m_livingFlg[eColor_Red] == true) {

		DrawTriangle(m_triPosition[eColor_Red].x, m_triPosition[eColor_Red].y,
			(m_triPosition[eColor_Red].x + CHAR_SIZE), m_triPosition[eColor_Red].y,
			m_triPosition[eColor_Red].x + (CHAR_SIZE / 2), (m_triPosition[eColor_Red].y + CHAR_SIZE),
			RED, true);
	}

	// ΞΜ}`Μ`ζ
	if (m_livingFlg[eColor_Green] == true) {

		DrawTriangle(m_triPosition[eColor_Red].x, m_triPosition[eColor_Red].y,
			(m_triPosition[eColor_Red].x + CHAR_SIZE), m_triPosition[eColor_Red].y,
			m_triPosition[eColor_Red].x + (CHAR_SIZE / 2), (m_triPosition[eColor_Red].y + CHAR_SIZE),
			GREEN, true);
	}

	// Β’}`Μ`ζ
	if (m_livingFlg[eColor_Blue] == true) {

		DrawTriangle(m_triPosition[eColor_Red].x, m_triPosition[eColor_Red].y,
			(m_triPosition[eColor_Red].x + CHAR_SIZE), m_triPosition[eColor_Red].y,
			m_triPosition[eColor_Red].x + (CHAR_SIZE / 2), (m_triPosition[eColor_Red].y + CHAR_SIZE),
			BLUE, true);
	}
}

/***********************************************

* @brief@Op`ΜXV

* @param[in] None

* @return None

***********************************************/
void Triangle::mUpdate() {

}

/***********************************************

* @brief IΉ

* @param[in] None

* @return None

***********************************************/
void Triangle::mFinal() {

}