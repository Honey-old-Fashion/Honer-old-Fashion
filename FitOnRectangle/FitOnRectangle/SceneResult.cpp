#include "SceneResult.h"
#include "DxLib.h"

/******************************************************
* @brief  SceneTitleのコンストラクター
@param  ISceneChanger changer
* @return None
*******************************************************/
SceneResult::SceneResult(ISceneChanger* changer) : SceneTask(changer) {

}

/******************************************************
* @brief  SceneTitleのデストラクター
* @param  None
* @return None
*******************************************************/
SceneResult::~SceneResult() {

}

/******************************************************
* @brief  シーンの初期化
* @param  None
* @return None
*******************************************************/
void SceneResult::mInit() {

}

/******************************************************
* @brief  シーンの更新
* @param  None
* @return None
*******************************************************/
void SceneResult::mUpdate() {
#ifdef _DEBUG
	printfDx("Result\n Tキーでタイトルへ");
#endif

	if (CheckHitKey(KEY_INPUT_T) != 0) {
		m_changeScene->mChangeScene(eScene_Title);
	}

}

/******************************************************
* @brief  シーンの描画
* @param  None
* @return None
*******************************************************/
void SceneResult::mRender() {
	DrawString(400, 400, _T("ステージ1クリア！！"), GetColor(255, 255, 255));
}
/******************************************************
* @brief  シーンの終了処理
* @param  None
* @return None
*******************************************************/
void SceneResult::mFinal() {
	SceneTask::mFinal();
}