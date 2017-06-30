#pragma once
#include "CharacterTask.h"

class Rectangle : public CharacterTask {
private:
	POINT m_rectPosition[COLOR_NUM];     // 四角形の左上の座標を色別に格納する
	bool m_livingFlg[COLOR_NUM];// 四角形のアクティブ状態を色別に管理する
public:
	Rectangle();
	~Rectangle();

	void mInit() override;
	void mCreate(eColor,int,int) override;
	void mDraw() override;
	void mUpdate() override;

	void mSetPosition(POINT _position, eColor _color) {
		m_rectPosition[_color].x = _position.x;
		m_rectPosition[_color].y = _position.y;
	}

	inline int mGetFloorY(eColor _color) {
		return m_rectPosition[_color].y + CHAR_SIZE;
	}

	inline int mGetCenterX(eColor _color) {
		return m_rectPosition[_color].x + (CHAR_SIZE/2);
	}

};

