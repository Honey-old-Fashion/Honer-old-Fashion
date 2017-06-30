#include "SceneGame.h"
#include "DxLib.h"

/******************************************************
* @brief  SceneGameのコンストラクター
* @param  ISceneChanger* changer
* @return None
*******************************************************/
SceneGame::SceneGame(ISceneChanger* _changer) : SceneTask(_changer) {

}

/******************************************************
* @brief  SceneGameのデストラクター
* @param  None
* @return None
*******************************************************/
SceneGame::~SceneGame() {

}

/******************************************************
* @brief  シーンの初期化
* @param  None
* @return None
*******************************************************/
void SceneGame::mInit() {
}

/******************************************************
* @brief  シーンの更新
* @param  None
* @return None
*******************************************************/
void SceneGame::mUpdate() {
#ifdef _DEBUG
	printfDx("game\nTキーでタイトルへ");
#endif
	SceneTask::mRender();
	if (CheckHitKey(KEY_INPUT_T) != 0) {
		m_changeScene->mChangeScene(eScene_Title);
	}
}

/******************************************************
* @brief  シーンの描画
* @param  None
* @return None
*******************************************************/
void SceneGame::mRender() {
	SceneTask::mRender();
	}

/******************************************************
* @brief  シーンの終了処理
* @param  None
* @return None
*******************************************************/
void SceneGame::mFinal() {
	SceneTask::mFinal();
}