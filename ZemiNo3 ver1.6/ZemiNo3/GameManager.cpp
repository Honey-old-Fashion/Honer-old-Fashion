#include "GameManager.h"
#define case break; case

GameManager::GameManager() {
	for (int ii = 0; ii < COLOR_NUM; ii++) {
		gimmicActioncolorFlag[ii] = true;
		rectCanMoveLeft[ii] = true;
		rectCanMoveRight[ii] = true;
		triCanMoveLeft[ii] = true;
		triCanMoveRight[ii] = true;
	}
}

GameManager::~GameManager(){ 

}

GameManager::ObjData GameManager::HitTest(POINT charPoint, POINT gimmickPoint, int gimmickID) {
	ObjData data;
	switch (gimmickID) {
	case 0:
		

	case 1:
		
	case 2:
		if(charPoint.x == gimmickPoint.x && charPoint.y + objSize == gimmickPoint.y) {
			data.hitFlag = true;
		}
		
	case 3:
		
	case 4:
		if (charPoint.x + objSize >= gimmickPoint.x && charPoint.x <= gimmickPoint.x + objSize) {
			data.hitFlag = true;
		}
	default:
		break;
	}
	return data;
}