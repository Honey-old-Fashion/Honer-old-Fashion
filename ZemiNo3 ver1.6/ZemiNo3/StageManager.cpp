#include "StageManager.h"
#include "FirstStage.h"
#include "SecondStage.h"
#include "ThirdStage.h"

StageManager::StageManager() {
	iStage = nullptr;
	stageID = gameManager->GetStageID();
	gameManager->SetGameClearFlag(false);
}

StageManager::~StageManager() {

}

void StageManager::mSetUp() {
	if (stageID == e_Stage::e_StageFirst) {
		iStage = (IStage*)new FirstStage;
		countDownTime = 60;
	}
	if (stageID == e_Stage::e_StageSecond) {
		iStage = (IStage*)new SecondStage;
		countDownTime = 90;
	}
	if (stageID == e_Stage::e_StageThird) {
		iStage = (IStage*)new ThirdStage;
		countDownTime = 120;
	}
	iStage->mSetUp();

	timer = new Timer("HGP–¾’©E", 40, 3);
}

void StageManager::mUpdate() {
	iStage->mUpdate();
	timer->mUpdate(countDownTime);
	if (timer->mGetTime() == 0) {
		gameManager->SetGameClearFlag(true);
	}
}

void StageManager::mRender() {
	iStage->mRender();
	timer->mRender();
}

void StageManager::mTearDown() {
		delete iStage;
		delete timer;
		iStage = nullptr;
		
}
