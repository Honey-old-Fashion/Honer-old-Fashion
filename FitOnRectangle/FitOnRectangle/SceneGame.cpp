#include "SceneGame.h"
#include "DxLib.h"


SceneGame::SceneGame(ISceneChanger* _changer) : SceneTask(_changer) {


}


SceneGame::~SceneGame() {

}

void SceneGame::mInit() {
	charMgr.mInit();
}

void SceneGame::mUpdate() {
#ifdef _DEBUG
	printfDx("game\nTキーでタイトルへ");
#endif
	SceneTask::mRender();
	if (CheckHitKey(KEY_INPUT_T) != 0) {
		m_changeScene->mChangeScene(eScene_Title);
	}

	charMgr.mUpdate();
	
}
void SceneGame::mRender() {
	charMgr.mRender();
}

void SceneGame::mFinal() {

}