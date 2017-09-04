#ifndef _IOBJECT_H_
#define _IOBJECT_H_
#include <windows.h>

// 色のリスト
#define RED GetColor(255,0,0)    // 赤
#define GREEN GetColor(0,255,0)  // 緑
#define BLUE GetColor(0,0,255)   // 青

#define CYAN GetColor(0,255,255)     // 青緑
#define MAGENTA GetColor(255,0,255)  // 紫
#define YELLOW GetColor(255,255,0)   // 黄

#define BLACK GetColor(0,0,0)        // 黒
#define WHITE GetColor(255,255,255)  // 白
#define GRAY GetColor(128,128,128)   // 灰

// 色のナンバー
enum eColor {
	eColor_Red,
	eColor_Green,
	eColor_Blue
};

// 操作できる図形の色の種類
#define COLOR_NUM 3

class IObject {

public:
	virtual ~IObject() = default;
	virtual void mInit() = 0;
	virtual void mUpdate() = 0;
	virtual void mRender() = 0;
	virtual void mFinal() = 0;
	virtual POINT GetPoint() = 0;
};
#endif //!_IOBJECT_H_