#include "SceneGame.h"
#include "DxLib.h"


SceneGame::SceneGame(ISceneChanger* _changer) : SceneTask(_changer) {

}


SceneGame::~SceneGame() {

}

void SceneGame::mInit() {
}

void SceneGame::mUpdate() {
#ifdef _DEBUG
	printfDx("game\nT�L�[�Ń^�C�g����");
#endif
	SceneTask::mRender();
	if (CheckHitKey(KEY_INPUT_T) != 0) {
		m_changeScene->mChangeScene(eScene_Title);
	}
	
}
void SceneGame::mRender() {

}

void SceneGame::mFinal() {

}