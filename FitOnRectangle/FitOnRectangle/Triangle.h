#pragma once
#include "CharacterTask.h"

/*********************************************************************

* !@file Triangle.h

* @brief 三角形のクラス

* @author 高口剛史

*********************************************************************/

class Triangle : public CharacterTask{
private:
	POINT m_triPosition[COLOR_NUM];    // 三角形の頂点の座標を格納する
	bool m_livingFlg[COLOR_NUM];// 三角形のアクティブ状態を色別に管理する

public:
	Triangle();
	~Triangle();

	void mInit() override;
	void mCreate(eColor, int, int) override;
	void mRender() override;
	void mUpdate() override;
	void mFinal() override;

	inline int mGetFloorY(eColor _color) {
		return m_triPosition[_color].y + CHAR_SIZE;
	}

	inline int mGetCenterX(eColor _color) {
		return m_triPosition[_color].x + (CHAR_SIZE / 2);
	}
};

