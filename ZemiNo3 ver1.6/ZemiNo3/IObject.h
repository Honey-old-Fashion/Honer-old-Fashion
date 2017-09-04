#ifndef _IOBJECT_H_
#define _IOBJECT_H_
#include <windows.h>

// �F�̃��X�g
#define RED GetColor(255,0,0)    // ��
#define GREEN GetColor(0,255,0)  // ��
#define BLUE GetColor(0,0,255)   // ��

#define CYAN GetColor(0,255,255)     // ��
#define MAGENTA GetColor(255,0,255)  // ��
#define YELLOW GetColor(255,255,0)   // ��

#define BLACK GetColor(0,0,0)        // ��
#define WHITE GetColor(255,255,255)  // ��
#define GRAY GetColor(128,128,128)   // �D

// �F�̃i���o�[
enum eColor {
	eColor_Red,
	eColor_Green,
	eColor_Blue
};

// ����ł���}�`�̐F�̎��
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