#include "FirstStage.h"


FirstStage::FirstStage() {
	for (int ii = 0; ii < 10; ii++) {
		switch (m_stage[ii]) {
		case 0:
			objData.iObjct[ii] = (IObject*) new FloarObject(CHAR_SIZE * ii + CHAR_SIZE, 50 + CHAR_SIZE);
			objData.gimmicType[ii] = 0;
			break;
		case 1:
			objData.iObjct[ii] = NULL;
			objData.iChara =  new class Rectangle(eColor_Red, CHAR_SIZE * (ii + 1) + CHAR_SIZE, 50);
			objData.gimmicType[ii] = 1;
			break;
		case 2:
			objData.iObjct[ii] = NULL;
			objData.Hamaru = new hamaru(eColor_Red, CHAR_SIZE * (ii) + CHAR_SIZE, 50 + CHAR_SIZE);
			objData.gimmicType[ii] = 2;
			break;

		case 4:
			objData.iObjct[ii] = (IObject*) new FloarObject(CHAR_SIZE * ii + CHAR_SIZE, 50 + CHAR_SIZE);
			objData.iGate = new GateGimmick(eColor_Red, CHAR_SIZE * (ii) + CHAR_SIZE, 50);
			objData.gimmicType[ii] = 4;
			objData.iGate->mSetActiveFlag(true);
			break;
		case 10:
			objData.iObjct[ii] = NULL;
			objData.iGimmick = new GoalRectAngleGimmick(CHAR_SIZE * (ii - 1) + CHAR_SIZE, 50);
			objData.gimmicType[ii] = 10;
			break;
		default:
			break;
		}

		clearFlag = false;
	}
}

FirstStage::~FirstStage() {

}


void FirstStage::mSetUp() {
	for (int ii = 0; ii < 10; ii++) {
		switch (objData.gimmicType[ii]) {
		case 1:
			objData.iChara->mInit();
			break;
		case 2:
			objData.Hamaru->mInit();
			break;
		case 4:
			objData.iGate->mInit();
			
			break;
		case 10:
			objData.iGimmick->mInit();
			break;

		default:
			objData.iObjct[ii]->mInit();
			break;
		}
	}
}

void FirstStage::mUpdate() {
	for (int ii = 0; ii < 10; ii++) {
		switch (objData.gimmicType[ii]) {
		case 1:
			objData.iChara->mUpdate();
			break;
		case 2:
			objData.Hamaru->mUpdate();

			if (objData.iChara->HitTest(ii, objData.gimmicType[ii], objData.Hamaru->mGetGimmickPointVecter2()).hitFlag == true) {
				objData.iGate->mSetActiveFlag(false);
				
			}
	
			else {
				//objData.iGate->mSetActiveFlag(true);
			}
			break;
		case 4:
			objData.iGate->mUpdate();
			if (objData.iGate->mGetActiveFlag() == true) {
				
				objData.iChara->HitTest(ii, objData.gimmicType[ii], objData.iGate->mGetGimmickPointVecter2());
			}
			break;
		case 10:
			objData.iGimmick->mUpdate();
			if (objData.iChara->HitTest(ii, objData.gimmicType[ii], objData.iGimmick->mGetGimmickPointVecter2()).hitFlag == true) {
				clearFlag = true;
			}
			break;

		default:
			objData.iObjct[ii]->mUpdate();
			break;
		}
	}
}

void FirstStage::mRender() {
	for (int ii = 0; ii < 10; ii++) {
		switch (objData.gimmicType[ii]) {
		case 1:
			objData.iChara->mRender();
			break;
		case 2:
			objData.Hamaru->mRender();
			break;
		case 4:
			objData.iGate->mRender();
			break;
		case 10:
			objData.iGimmick->mRender();
			break;

		default:
			objData.iObjct[ii]->mRender();
			break;
		}
	}
}

void FirstStage::mTearDown() {
	for (int ii = 0; ii < 10; ii++) {
		switch (objData.gimmicType[ii]) {
		case 1:
			objData.iChara->mFinal();
			delete objData.iChara;
			break;
		case 2:
			objData.Hamaru->mFinal();
			delete objData.Hamaru;
			break;
		case 4:
			objData.iGate->mFinal();
			delete objData.iGate;
			break;
		case 10:
			objData.iGimmick->mFinal();
			delete objData.iGimmick;
			break;

		default:
			objData.iObjct[ii]->mFinal();
			delete objData.iObjct[ii];
			objData.iObjct[ii] = NULL;
			break;
		}
		
	}
}
