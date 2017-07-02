#include "FirstStage.h"
#include "FloarObject.h"
#include "Rectangle.h"
#include "GoalRectAngleGimmick.h"

FirstStage::FirstStage() {
	for (int ii = 0; ii < 10; ii++) {
		switch (m_stage[ii]) {
		case 0:
			objData.iObjct[ii] = (IObject*) new FloarObject(CHAR_SIZE * ii + CHAR_SIZE, 50 + CHAR_SIZE);
			objData.gimmicType[ii] = 0;
			break;
		case 1:
			objData.iObjct[ii] = (IObject*) new class Rectangle(eColor_Red, CHAR_SIZE * (ii + 1) + CHAR_SIZE, 50);
			objData.gimmicType[ii] = 1;
			break;
		case 10:
			
			objData.iObjct[ii] = (IObject*) new GoalRectAngleGimmick(CHAR_SIZE * (ii - 1) + CHAR_SIZE, 50);
			objData.gimmicType[ii] = 2;
			break;
		default:
			break;
		}
	}
}

FirstStage::~FirstStage() {

}


void FirstStage::mSetUp() {
	for (int ii = 0; ii < 10; ii++) {
		objData.iObjct[ii]->mInit();
	}
}

void FirstStage::mUpdate() {
	for (int ii = 0; ii < 10; ii++) {
		objData.iObjct[ii]->mUpdate();
	}
}

void FirstStage::mRender() {
	for (int ii = 0; ii < 10; ii++) {
		objData.iObjct[ii]->mRender();
	}
}

void FirstStage::mTearDown() {
	for (int ii = 0; ii < 10; ii++) {
		objData.iObjct[ii]->mFinal();
		delete objData.iObjct[ii];
		objData.iObjct[ii] = NULL;
	}
}
