#include "WallObject.h"
#include "DxLib.h"


WallObject::WallObject(int x, int y) {
	pWall.x = x;
	pWall.y = y;
}


WallObject::~WallObject()
{
}

void WallObject::mRender() {
	DrawBox(pWall.x, pWall.y, pWall.x + OBJECTSIZE, pWall.y + OBJECTSIZE, mBlack,TRUE);
}