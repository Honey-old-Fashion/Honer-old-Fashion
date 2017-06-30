/**********************************************************************************************
* !@file  StageManager.h
* @brief  Control Stage
* @author Sugiyama Ryo
******************************************************************************************/
#ifndef _STAGEMANAGER_H_
#define _STAGEMANAGER_H_

#include "IStage.h"

class StageManager : public IStage {
private:
	char m_stageNumber;
	IStage *iStage[3];
public:
	StageManager(char _stageId);
	~StageManager();
	
	virtual void mSetUp() override;
	virtual void mUpdate() override;
	virtual void mRender() override;
	virtual void mTearDown() override;
};

#endif // !_STAGEMANAGER_H_