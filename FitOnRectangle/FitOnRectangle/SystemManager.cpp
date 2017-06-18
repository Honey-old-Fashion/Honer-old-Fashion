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

	ChangeWindowMode(TRUE);

	SetMainWindowText("FitOnRectangle");

	GetMouseDispFlag();

	SetDoubleStartValidFlag(FALSE);

	SetGraphMode(1280, 720, 32);

	SetDrawScreen(DX_SCREEN_BACK);

	if (DxLib_Init() == -1) {

	#ifdef _DEBUG
		printfDx("DX���C�u�����̏������Ɏ��s���܂���");
	#endif 
		exit(-1);
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
		mKeepFPS();
		ClearDrawScreen();
		
		SceneMgr.mUpdate();
		SceneMgr.mRender();

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
	#ifdef _DEBUG
		printfDx("DX���C�u�����̏I���Ɏ��s���܂���");
	#endif
		return -2;
	}
	return 0;
}

/******************************************************
* @brief  Get now FPS and keep 60 FPS
* @param  None
* @return None
*******************************************************/
void SystemManager::mKeepFPS() {
	const DWORD waitTime = 16;	//60FPS

	DWORD nTime = timeGetTime();
	DWORD rTime = nTime - m_lastTime;
	m_lastTime = nTime;

	if (rTime < waitTime) {	
		Sleep(waitTime - rTime);
	}
}

/******************************************************
* @brief  �G���[���N��������G���[�ԍ��ƂƂ��ɋ����I������֐�
* @param  _errorName : �G���[�̊T�v
* @param  _errorCode : �G���[�R�[�h
* @return None
*******************************************************/
static int Error(LPCTSTR _errorName, int _errorCode) {
	MessageBox(NULL, _errorName, NULL, MB_OK);
	exit(_errorCode);
}