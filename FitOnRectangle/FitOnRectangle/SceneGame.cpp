#include "SceneGame.h"
#include "DxLib.h"


SceneGame::SceneGame(ISceneChanger* _changer) : SceneTask(_changer) {
	obj = new FirstStage;

}


SceneGame::~SceneGame() {

}

void SceneGame::mInit() {
	obj->mSetUp();
}

void SceneGame::mUpdate() {
#ifdef _DEBUG
	printfDx("game\nTキーでタイトルへ");
#endif
	SceneTask::mRender();
	obj->mUpdate();
	if (obj->clearFlag == true) {
		m_changeScene->mChangeScene(eScene_Result);
	}
}
void SceneGame::mRender() {
	obj->mRender();
}

void SceneGame::mFinal() {
	obj->mTearDown();
}