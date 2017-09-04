/**********************************************************************************************
* !@file  StageManager.h
* @brief  Control Stage
* @author Sugiyama Ryo
******************************************************************************************/
#ifndef _STAGEMANAGER_H_
#define _STAGEMANAGER_H_

#include "IStage.h"
#include "GameManager.h"
#include "Timer.h"

class StageManager : public IStage {
private:
	char m_stageNumber;
	IStage *iStage;
	e_Stage stageID;
	Timer* timer;
	int countDownTime;
public:
	StageManager();
	~StageManager();
	
	virtual void mSetUp() override;
	virtual void mUpdate() override;
	virtual void mRender() override;
	virtual void mTearDown() override;
};

#endif // !_STAGEMANAGER_H_