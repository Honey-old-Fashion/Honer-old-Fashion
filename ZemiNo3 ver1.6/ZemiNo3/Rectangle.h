#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_
#include "CharacterTask.h"
#include "CollisionDetection.h"
#include "Singleton.h"

/*************************************************************

* !@file Rectangle.h

* @brief 四角形のクラス

* @author Takaguchi Tsuyoshi

*************************************************************/
class Rectangle :public CharacterTask {
private:
	unsigned int createColor;
	CollisionDetection& collision = singleton<CollisionDetection>::GetInstance();
public:
	Rectangle(eColor, int, int);
	~Rectangle();
	virtual POINT GetPoint() {
		return this->m_characterPosition;
	}
	void mInit() override;
	void mRender() override;
	void mUpdate() override;
	void mFinal() override;
	void mMove() override;
};

#endif //!_RECTANGLE_H_