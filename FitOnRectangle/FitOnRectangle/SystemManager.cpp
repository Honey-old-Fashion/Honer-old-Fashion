/**********************************************************************************
* !@file SystemManager.cpp
* @brief Control System
* @author Sugiyama Ryo 
*********************************************************************************/

#include "SystemManager.h"
#include "DxLib.h"


/******************************************************
* @brief  Constructer
* @param  None
* @return None
*******************************************************/
SystemManager::SystemManager() {
	
}

/******************************************************
* @brief  Destructer
* @param  None
* @return None
*******************************************************/
SystemManager::~SystemManager() {
}

/******************************************************
* @brief  System initialize function
* @param  None
* @return ErrorId
*******************************************************/
int SystemManager::mInitialize() {

	m_lastTime = 0;

	ChangeWindowMode(TRUE);

	SetMainWindowText("FitOnRectangle");

	GetMouseDispFlag();

	SetUse3DFlag(FALSE);

	SetDoubleStartValidFlag(FALSE);

	SetGraphMode(1280, 720, 32);

	SetDrawScreen(DX_SCREEN_BACK);

	if (DxLib_Init() == -1) {
		Error("Dxライブラリの初期化に失敗しました。", -1);
	}
	return 0;

}

/******************************************************
* @brief  System update function
* @param  None
* @return None
*******************************************************/
void SystemManager::mUpdate() {

	SceneMgr.mInit();

	while (ProcessMessage() != -1 ) {
		ClearDrawScreen();
		
		SceneMgr.mUpdate();
		SceneMgr.mRender();

		const DWORD waitTime = 16;	//60FPS

		DWORD nTime = timeGetTime();
		DWORD rTime = nTime - m_lastTime;
		m_lastTime = nTime;

		if (rTime < waitTime) {
			Sleep(waitTime - rTime);
		}

		ScreenFlip();

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
		
	#ifdef _DEBUG
		clsDx();
	#endif
	}
	SceneMgr.mFinal();
}

/******************************************************
* @brief  Release ojject function
* @param  None
* @return ErrorId
*******************************************************/
int SystemManager::mFainalize() {

	if (DxLib_End() == -1) {
		Error("DXライブラリの終了に失敗しました", -2);
	}
	return 0;
}


/******************************************************
* @brief  エラーが起こったらエラー番号とともに強制終了する関数
* @param  _errorName : エラーの概要
* @param  _errorCode : エラーコード
* @return None
*******************************************************/
static int Error(LPCTSTR _errorName, int _errorCode) {
	MessageBox(NULL, _errorName, NULL, MB_OK);
	exit(_errorCode);
}
