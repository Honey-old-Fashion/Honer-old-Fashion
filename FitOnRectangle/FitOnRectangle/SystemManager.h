 /**********************************************************************************************
* !@file SystemManaget.h
* @brief  Control System 
* @author Sugiyama Ryo
******************************************************************************************/

#ifndef _SYSTEMMANAGET_H_
#define _SYSTEMMANAGER_H_

#include <Dxlib.h>
#include "SceneManager.h"


class SystemManager {

private:
	SystemManager();
	~SystemManager();
	int mInitialize();
	int mFainalize();
	void mUpdate();
	

	friend int APIENTRY _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int);

	DWORD m_lastTime;	// @brief 前回のループ時におけるFPS値
	SceneManager SceneMgr;


};

static int Error(LPCTSTR _errorName, int _errorCode); 

#endif // !_SYSTEMMANAGER_H_
