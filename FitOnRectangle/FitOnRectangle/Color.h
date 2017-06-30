#ifndef _COLOR_H_
#define _COLOR_H_
/**************************************************

* !@file Color.h

* @brief �F�̒�`

* @author �������j

**************************************************/
#include "DxLib.h"

// �F�̃��X�g
#define RED GetColor(255,0,0)        // ��
#define GREEN GetColor(0,255,0)      // ��  
#define BLUE GetColor(0,0,255)       // ��	
#define CYAN GetColor(0,255,255)     // ��
#define MAGENTA GetColor(255,0,255)  // ��
#define YELLOW GetColor(255,255,0)   // ��
#define BLACK GetColor(0,0,0)        // ��
#define WHITE GetColor(255,255,255)  // ��
#define GRAY GetColor(128,128,128)   // �D

// �F�̃i���o�[
typedef enum eColor {
	eColor_Red = 0,
	eColor_Green,
	eColor_Blue,
}eColor;

#define COLOR_NUM 3 // ����ł���}�`�̐F�̎��

#endif // !_COLOR_H_