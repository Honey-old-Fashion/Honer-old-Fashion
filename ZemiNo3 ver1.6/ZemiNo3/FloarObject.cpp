#include "FloarObject.h"



FloarObject::FloarObject(int _posX, int _posY) {
	
	pFloar.x = _posX;
	pFloar.y = _posY;
}


FloarObject::~FloarObject() {

}



void FloarObject::mRender() {
	DrawLine(pFloar.x, pFloar.y, pFloar.x + cm_objSize , pFloar.y, mWhite ,3);
}


