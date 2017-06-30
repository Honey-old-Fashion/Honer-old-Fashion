#ifndef _COLOR_H_
#define _COLOR_H_
/**************************************************

* !@file Color.h

* @brief 色の定義

* @author 高口剛史

**************************************************/
#include "DxLib.h"

// 色のリスト
#define RED GetColor(255,0,0)        // 赤
#define GREEN GetColor(0,255,0)      // 緑  
#define BLUE GetColor(0,0,255)       // 青	
#define CYAN GetColor(0,255,255)     // 青緑
#define MAGENTA GetColor(255,0,255)  // 紫
#define YELLOW GetColor(255,255,0)   // 黄
#define BLACK GetColor(0,0,0)        // 黒
#define WHITE GetColor(255,255,255)  // 白
#define GRAY GetColor(128,128,128)   // 灰

// 色のナンバー
typedef enum eColor {
	eColor_Red = 0,
	eColor_Green,
	eColor_Blue,
}eColor;

#define COLOR_NUM 3 // 操作できる図形の色の種類

#endif // !_COLOR_H_