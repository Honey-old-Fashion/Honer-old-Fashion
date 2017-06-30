#include "Triangle.h"
#include "DxLib.h"



Triangle::Triangle()
{
}


Triangle::~Triangle()
{
}
/***********************************************

* @brief ������

* @param[in] None

* @return None

***********************************************/
void Triangle::mInit() {

}

/***********************************************

* @brief �O�p�`�̐���

* @param[in] �F���, ���_��x���W, ���_��y���W

* @return None

***********************************************/
void Triangle::mCreate(eColor _color, int _x, int _y) {

	m_triPosition[_color].x = _x;
	m_triPosition[_color].y = _y;
	m_livingFlg[_color] = true;
}

/***********************************************

* @brief �}�`�̕`��

* @param[in] None

* @return None

***********************************************/
void Triangle::mRender() {
	// �Ԃ��}�`�̕`��
	if (m_livingFlg[eColor_Red] == true) {

		DrawTriangle(m_triPosition[eColor_Red].x, m_triPosition[eColor_Red].y,
			(m_triPosition[eColor_Red].x + CHAR_SIZE), m_triPosition[eColor_Red].y,
			m_triPosition[eColor_Red].x + (CHAR_SIZE / 2), (m_triPosition[eColor_Red].y + CHAR_SIZE),
			RED, true);
	}

	// �΂̐}�`�̕`��
	if (m_livingFlg[eColor_Green] == true) {

		DrawTriangle(m_triPosition[eColor_Red].x, m_triPosition[eColor_Red].y,
			(m_triPosition[eColor_Red].x + CHAR_SIZE), m_triPosition[eColor_Red].y,
			m_triPosition[eColor_Red].x + (CHAR_SIZE / 2), (m_triPosition[eColor_Red].y + CHAR_SIZE),
			GREEN, true);
	}

	// ���}�`�̕`��
	if (m_livingFlg[eColor_Blue] == true) {

		DrawTriangle(m_triPosition[eColor_Red].x, m_triPosition[eColor_Red].y,
			(m_triPosition[eColor_Red].x + CHAR_SIZE), m_triPosition[eColor_Red].y,
			m_triPosition[eColor_Red].x + (CHAR_SIZE / 2), (m_triPosition[eColor_Red].y + CHAR_SIZE),
			BLUE, true);
	}
}

/***********************************************

* @brief�@�O�p�`�̍X�V

* @param[in] None

* @return None

***********************************************/
void Triangle::mUpdate() {

}

/***********************************************

* @brief �I������

* @param[in] None

* @return None

***********************************************/
void Triangle::mFinal() {

}