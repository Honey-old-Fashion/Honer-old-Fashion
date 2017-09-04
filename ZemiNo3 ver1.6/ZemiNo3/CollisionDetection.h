#ifndef _COLLISIONDETECTION_H_
#define _COLLISIONDETECTION_H_

#include <winapifamily.h>
#include "GameManager.h"
#include "IObject.h"

class  CollisionDetection {
public:
	CollisionDetection();
	~CollisionDetection();
	void SetRectCharPos(POINT pos, eColor color);
	void SetTriCharPos(POINT pos, eColor color);
	POINT GetRectPos(eColor arrayNum) { return rectPoint[arrayNum]; }
	POINT GetTriPos(eColor arrayNum) { return triPoint[arrayNum]; }

private:
	POINT rectPoint[COLOR_NUM];
	POINT triPoint[COLOR_NUM];
};

#endif // !_COLLISIONDETECTION_H_