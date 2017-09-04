#include "SceneGame.h"
#include "DxLib.h"

SceneGame::SceneGame(ISceneChanger* _changer) : SceneTask(_changer) {
	
}


SceneGame::~SceneGame() {

}

void SceneGame::mInit() {
	mgr.mSetUp();
	SceneTask::mGraphicHandle = LoadGraph("pic/BG.png");
}

void SceneGame::mUpdate() {
#ifdef _DEBUG
	printfDx("game\nTキーでタイトルへ");
#endif
	mgr.mUpdate();
	if (gameManager->GetGameClearFlag() == true) {
		m_changeScene->mChangeScene(eScene_Result);
	}
}
void SceneGame::mRender() {
	SceneTask::mRender();
	mgr.mRender();
}

void SceneGame::mFinal() {
	mgr.mTearDown();
}