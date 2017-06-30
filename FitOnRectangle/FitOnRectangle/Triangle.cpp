#include "Triangle.h"
#include "DxLib.h"



Triangle::Triangle()
{
}


Triangle::~Triangle()
{
}
/***********************************************

* @brief 初期化

* @param[in] None

* @return None

***********************************************/
void Triangle::mInit() {

}

/***********************************************

* @brief 三角形の生成

* @param[in] 色情報, 頂点のx座標, 頂点のy座標

* @return None

***********************************************/
void Triangle::mCreate(eColor _color, int _x, int _y) {

	m_triPosition[_color].x = _x;
	m_triPosition[_color].y = _y;
	m_livingFlg[_color] = true;
}

/***********************************************

* @brief 図形の描画

* @param[in] None

* @return None

***********************************************/
void Triangle::mRender() {
	// 赤い図形の描画
	if (m_livingFlg[eColor_Red] == true) {

		DrawTriangle(m_triPosition[eColor_Red].x, m_triPosition[eColor_Red].y,
			(m_triPosition[eColor_Red].x + CHAR_SIZE), m_triPosition[eColor_Red].y,
			m_triPosition[eColor_Red].x + (CHAR_SIZE / 2), (m_triPosition[eColor_Red].y + CHAR_SIZE),
			RED, true);
	}

	// 緑の図形の描画
	if (m_livingFlg[eColor_Green] == true) {

		DrawTriangle(m_triPosition[eColor_Red].x, m_triPosition[eColor_Red].y,
			(m_triPosition[eColor_Red].x + CHAR_SIZE), m_triPosition[eColor_Red].y,
			m_triPosition[eColor_Red].x + (CHAR_SIZE / 2), (m_triPosition[eColor_Red].y + CHAR_SIZE),
			GREEN, true);
	}

	// 青い図形の描画
	if (m_livingFlg[eColor_Blue] == true) {

		DrawTriangle(m_triPosition[eColor_Red].x, m_triPosition[eColor_Red].y,
			(m_triPosition[eColor_Red].x + CHAR_SIZE), m_triPosition[eColor_Red].y,
			m_triPosition[eColor_Red].x + (CHAR_SIZE / 2), (m_triPosition[eColor_Red].y + CHAR_SIZE),
			BLUE, true);
	}
}

/***********************************************

* @brief　三角形の更新

* @param[in] None

* @return None

***********************************************/
void Triangle::mUpdate() {

}

/***********************************************

* @brief 終了処理

* @param[in] None

* @return None

***********************************************/
void Triangle::mFinal() {

}