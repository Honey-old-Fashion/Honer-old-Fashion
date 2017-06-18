#include "SceneTitle.h"
#include "DxLib.h"

SceneTitle::SceneTitle(ISceneChanger* changer) : SceneTask(changer) {

}


SceneTitle::~SceneTitle() {
	
}

void SceneTitle::mInit() {
	mGraphicHandle = LoadGraph("pic/Title.jpg");
}

void SceneTitle::mUpdate() {
#ifdef _DEBUG
	printfDx("Title\n GƒL[‚ÅƒQ[ƒ€‚Ö");
#endif

	if (m_nextSceneFlag[0] == true) {
		m_changeScene->mChangeScene(eScene_Game);
	}
	if (m_nextSceneFlag[1] == true) {
		delete this;
		DxLib_End();
		exit(0);
	}
}

void SceneTitle::mRender() {
	SceneTask::mRender();	
	m_nextSceneFlag[0] = SceneTask::mDrawSelectBox(100, 400, 400, 200, "START");
	m_nextSceneFlag[1] = SceneTask::mDrawSelectBox(780, 400, 400, 200, " END ");
	SceneTask::mDrawSelectBox(100, 100, 1080, 250, "Fit on Rectangle", false);
}

void SceneTitle::mFinal() {
	SceneTask::mFinal();
}