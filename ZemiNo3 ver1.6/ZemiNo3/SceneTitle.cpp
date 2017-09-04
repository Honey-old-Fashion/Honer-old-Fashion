#include "SceneTitle.h"
#include "DxLib.h"

/******************************************************
* @brief  SceneTitleのコンストラクター
* @param  ISceneChanger* changer
* @return None
*******************************************************/
SceneTitle::SceneTitle(ISceneChanger* changer) : SceneTask(changer) {

}

/******************************************************
* @brief  SceneTitleのデストラクター
* @param  None
* @return None
*******************************************************/
SceneTitle::~SceneTitle() {
	
}

/******************************************************
* @brief  シーンの初期化
* @param  None
* @return None
*******************************************************/
void SceneTitle::mInit() {
	mGraphicHandle = LoadGraph("pic/Title.jpg");
	m_titleUIgHandle[0] = LoadGraph("pic/TITLE.png");
	m_titleUIgHandle[1] = LoadGraph("pic/TITLE_END.png");
	m_titleUIgHandle[2] = LoadGraph("pic/TITLE_START.png");
	SetMousePoint(300, 500);
	alphaNum = 0;
	DrawTitleUIFlag = false;
}

/******************************************************
* @brief  シーンの更新
* @param  None
* @return None
*******************************************************/
void SceneTitle::mUpdate() {
#ifdef _DEBUG
	printfDx("Title\n Gキーでゲームへ");
#endif

	if (m_nextSceneFlag[0] == true) {
		delete this;
		DxLib_End();
		exit(0);
	}
	if (m_nextSceneFlag[1] == true) {
		m_changeScene->mChangeScene(eScene_Menu);
	}

	// 左右キーでマウスカーソルの座標を更新する
	if (CheckHitKey(KEY_INPUT_LEFT) != 0) {
		SetMousePoint(300, 500);
	}
	if (CheckHitKey(KEY_INPUT_RIGHT) != 0) {
		SetMousePoint(980, 500);
	}

}

/******************************************************
* @brief  シーンの描画
* @param  None
* @return None
*******************************************************/
void SceneTitle::mRender() {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alphaNum);
	if (alphaNum <= 255) {
		alphaNum += 5;
		if(alphaNum == 255) DrawTitleUIFlag = true;
	}
	SceneTask::mRender();
	//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, alphaNum);
	if (DrawTitleUIFlag == true) {
		m_nextSceneFlag[0] = SceneTask::mDrawSelectBox(100, 400, 400, 200, m_titleUIgHandle[1]);
		m_nextSceneFlag[1] = SceneTask::mDrawSelectBox(780, 400, 400, 200, m_titleUIgHandle[2]);
		SceneTask::mDrawSelectBox(200, 100, 800, 250, m_titleUIgHandle[0], false);
	}
}
/******************************************************
* @brief  シーンの終了処理
* @param  None
* @return None
*******************************************************/
void SceneTitle::mFinal() {
	SceneTask::mFinal();
}