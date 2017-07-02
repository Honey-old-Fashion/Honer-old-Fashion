#pragma once
#include "CharacterTask.h"
#include <Windows.h>
/*************************************************************

* !@file Rectangle.h

* @brief 四角形のクラス

* @author 高口剛史

*************************************************************/
class Rectangle :public CharacterTask {
private:
	POINT m_rectPosition[COLOR_NUM];  // 四角形の座標を色別に格納する
	bool m_livingFlg[COLOR_NUM];      // 四角形のアクティブ状態を色別に格納する
	unsigned int createColor;
public:
	Rectangle(eColor, int, int);
	~Rectangle();

	void mInit() override;
	void mRender() override;
	void mUpdate() override;
	void mFinal() override;

	void mSetPosition(POINT _position, eColor _color) {
		m_rectPosition[_color] = _position;
		m_rectPosition[_color] = _position;
	}

	inline int mGetFloorY(eColor _color) {
		return m_rectPosition[_color].y + CHAR_SIZE;
	}

	inline int mGetCenterX(eColor _color) {
		return m_rectPosition[_color].x + (CHAR_SIZE / 2);
	}
};