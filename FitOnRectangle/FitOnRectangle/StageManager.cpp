#include "StageManager.h"
#include "FirstStage.h"

StageManager::StageManager(char _stageId) {
	m_stageNumber = _stageId;
}

StageManager::~StageManager() {

}

void StageManager::mSetUp() {
	switch (m_stageNumber) {

	case 1:
		iStage[0] = (IStage*) new FirstStage;
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		break;
	}
}

void StageManager::mUpdate() {

}

void StageManager::mRender() {

}

void StageManager::mTearDown() {
	for (int ii = 0; ii < 3; ii++) {
		delete iStage[ii];
	}
}
