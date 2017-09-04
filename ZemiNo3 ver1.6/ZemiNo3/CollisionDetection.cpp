#include "CollisionDetection.h"



CollisionDetection::CollisionDetection() {
	for (int ii = 0; ii < COLOR_NUM; ii++) {
		rectPoint[ii].x = (LONG)NULL;
		rectPoint[ii].y = (LONG)NULL;
		triPoint[ii].x = (LONG)NULL;
		triPoint[ii].y = (LONG)NULL;
	}
}

CollisionDetection::~CollisionDetection() {

}

void CollisionDetection::SetRectCharPos(POINT pos, eColor color) {
	rectPoint[color].x = pos.x;
	rectPoint[color].y = pos.y;
}

void CollisionDetection::SetTriCharPos(POINT pos, eColor color) {
	triPoint[color].x = pos.x;
	triPoint[color].y = pos.y;
}
