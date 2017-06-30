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

* @brief ������

* @param[in] None

* @return None

***********************************************/
void Rectangle::mInit() {

}

/***********************************************

* @brief �l�p�`�̐���

* @param[in] �F���, ���[��x���W, ��[��y���W

* @return None

***********************************************/
void Rectangle::mCreate(eColor _color, int _x, int _y) {

	m_rectPosition[_color].x = _x;
	m_rectPosition[_color].y = _y;
	m_livingFlg[_color] = true;
}

/***********************************************

* @brief �}�`�̕`��

* @param[in] None

* @return None

***********************************************/
void Rectangle::mRender() {
	// �Ԃ��}�`�̕`��
	if (m_livingFlg[eColor_Red] == true) {

		DrawBox(m_rectPosition[eColor_Red].x, m_rectPosition[eColor_Red].y,
			m_rectPosition[eColor_Red].x + CHAR_SIZE, m_rectPosition[eColor_Red].y + CHAR_SIZE,
			RED, true);
	}

	// �΂̐}�`�̕`��
	if (m_livingFlg[eColor_Green] == true) {

		DrawBox(m_rectPosition[eColor_Green].x, m_rectPosition[eColor_Green].y,
			m_rectPosition[eColor_Green].x + CHAR_SIZE, m_rectPosition[eColor_Green].y + CHAR_SIZE,
			GREEN, true);
	}

	// ���}�`�̕`��
	if (m_livingFlg[eColor_Blue] == true) {

		DrawBox(m_rectPosition[eColor_Blue].x, m_rectPosition[eColor_Blue].y,
			m_rectPosition[eColor_Blue].x + CHAR_SIZE, m_rectPosition[eColor_Blue].y + CHAR_SIZE,
			BLUE, true);
	}
}

/***********************************************

* @brief �l�p�`�̍X�V

* @param[in] None

* @return None

***********************************************/
void Rectangle::mUpdate() {

}

/***********************************************

* @brief �I������

* @param[in] None

* @return None

***********************************************/
void Rectangle::mFinal() {

}