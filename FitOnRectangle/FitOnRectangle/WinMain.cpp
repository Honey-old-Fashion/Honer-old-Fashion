#include <Windows.h>
#include <crtdbg.h>
#pragma comment(lib, "winmm.lib") 

#include "SystemManager.h"

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdshow){

	#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	#endif 


	timeBeginPeriod(1);

	SystemManager SysMgr;

	SysMgr.mInitialize();

	SysMgr.mUpdate();

	SysMgr.mFainalize();

}