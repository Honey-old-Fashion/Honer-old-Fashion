#include "SceneMenu.h"
#include "DxLib.h"


SceneMenu::SceneMenu(ISceneChanger* _changer) : SceneTask(_changer) {
	}


SceneMenu::~SceneMenu() {
}

/******************************************************
* @brief  シーンの初期化
* @param  None
* @return None
*******************************************************/
void SceneMenu::mInit() {
	mGraphicHandle = LoadGraph("pic/Title.jpg");
	m_menuUIgHandle[0] = LoadGraph("pic/MENU_BACK.png");
	m_menuUIgHandle[1] = LoadGraph("pic/MENU_STAGE1.png");
	m_menuUIgHandle[2] = LoadGraph("pic/MENU_STAGE2.png");
	m_menuUIgHandle[3] = LoadGraph("pic/MENU_STAGE3.png");
	m_menuUIgHandle[4] = LoadGraph("pic/MENU_TUTORIAL.png");
	m_menuUIgHandle[5] = LoadGraph("pic/MENU_STAGESELECT.png");
	SetMousePoint(225, 300);
	alphaNum = 0;
	m_keyFlag = false;
	DrawMenuUIFlag = false;
}

/******************************************************
* @brief  シーンの更新
* @param  None
* @return None
*******************************************************/
void SceneMenu::mUpdate() {
#ifdef _DEBUG
	printfDx("menu");
#endif
	if (mNextSceneFlag[0] == true) {
		m_changeScene->mChangeScene(eScene_Title);
	}

	if (mNextSceneFlag[1] == true) {
		gameManager->SetStageID(e_Stage::e_StageFirst);	
		m_changeScene->mChangeScene(eScene_Game);
	}

	if (mNextSceneFlag[2] == true) {
		gameManager->SetStageID(e_Stage::e_StageSecond);		
		m_changeScene->mChangeScene(eScene_Game);
	}

	if (mNextSceneFlag[3] == true) {
		gameManager->SetStageID(e_Stage::e_StageThird);		
		m_changeScene->mChangeScene(eScene_Game);
	}

	if (mNextSceneFlag[4] == true) {
		m_changeScene->mChangeScene(eScene_Tutorial);
	}

	// 以下十字キーの処理
	GetMousePoint(&m_getMouseX, &m_getMouseY);
	// キーが入力されていないなら
	if (m_keyFlag == false) {
		// カーソルがStage1ボタンの上にあるなら
		if (m_getMouseX >= 25 && m_getMouseX <= (25 + 400) &&
			m_getMouseY >= 200 && m_getMouseY <= (200 + 200)) {

			// Stage2のボタンの上へカーソルを動かす
			if (CheckHitKey(KEY_INPUT_RIGHT) != 0) {
				SetMousePoint(635, 300);
				m_keyFlag = true;
			}
			// Backボタンの上へカーソルを動かす
			if (CheckHitKey(KEY_INPUT_DOWN) != 0) {
				SetMousePoint(250, 600);
				m_keyFlag = true;
			}
		}
		// カーソルがStage2ボタンの上にあるなら
		else if (m_getMouseX >= 435 && m_getMouseX <= (435 + 400) &&
			m_getMouseY >= 200 && m_getMouseY <= (200 + 200)) {

			// Stage3ボタンの上へカーソルを動かす
			if (CheckHitKey(KEY_INPUT_RIGHT) != 0) {
				SetMousePoint(1045, 300);
				m_keyFlag = true;
			}
			// Stage1ボタンの上へカーソルを動かす
			if (CheckHitKey(KEY_INPUT_LEFT) != 0) {
				SetMousePoint(225, 300);
				m_keyFlag = true;
			}
			if (CheckHitKey(KEY_INPUT_DOWN) != 0) {
				SetMousePoint(250, 600);
				m_keyFlag = true;
			}
		}
		// カーソルがStage3ボタンの上にあるなら
		else if (m_getMouseX >= 845 && m_getMouseX <= (845 + 400) &&
			m_getMouseY >= 200 && m_getMouseY <= (200 + 200)) {

			// Stage2ボタンの上へカーソルを動かす
			if (CheckHitKey(KEY_INPUT_LEFT) != 0) {
				SetMousePoint(635, 300);
				m_keyFlag = true;
			}
			// Tutorialボタンの上へカーソルを動かす
			if (CheckHitKey(KEY_INPUT_DOWN) != 0) {
				SetMousePoint(1020, 600);
				m_keyFlag = true;
			}
		}
		// カーソルがBackボタンの上にあるなら
		else if (m_getMouseX >= 50 && m_getMouseX <= (50 + 400) &&
			m_getMouseY >= 500 && m_getMouseY <= (500 + 200)) {

			if (CheckHitKey(KEY_INPUT_RIGHT) != 0) {
				SetMousePoint(1020, 600);
				m_keyFlag = true;
			}
			// Stage1ボタンの上へカーソルを動かす
			if (CheckHitKey(KEY_INPUT_UP) != 0) {
				SetMousePoint(250, 300);
				m_keyFlag = true;
			}
		}
		// カーソルがTutorialボタンの上にあるなら
		else if (m_getMouseX >= 820 && m_getMouseX <= (820 + 400) &&
			m_getMouseY >= 500 && m_getMouseY <= (500 + 200)) {
			
			if (CheckHitKey(KEY_INPUT_LEFT) != 0) {
				SetMousePoint(250, 600);
				m_keyFlag = true;
			}
			if (CheckHitKey(KEY_INPUT_UP) != 0) {
				SetMousePoint(1045, 300);
				m_keyFlag = true;
			}
		}
		else {
			// Stage1ボタンの上へカーソルを動かす
			if (CheckHitKey(KEY_INPUT_LEFT) != 0) {
				SetMousePoint(225, 300);
				m_keyFlag = true;
			}
		}
	}

	// 十字キーが入力されていないなら
	if (CheckHitKey(KEY_INPUT_LEFT) == 0 && CheckHitKey(KEY_INPUT_RIGHT) == 0 &&
		CheckHitKey(KEY_INPUT_UP) == 0 && CheckHitKey(KEY_INPUT_DOWN) == 0) {

		m_keyFlag = false;
	}
	
}

/******************************************************
* @brief  シーンの描画
* @param  None
* @return None
*******************************************************/
void SceneMenu::mRender() {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alphaNum);
	if (alphaNum <= 255) {
		alphaNum += 5;
		if (alphaNum == 255) DrawMenuUIFlag = true;
	}
	SceneTask::mRender();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	if (DrawMenuUIFlag == true) {
		mNextSceneFlag[0] = SceneTask::mDrawSelectBox(50, 500, 400, 200, m_menuUIgHandle[0]);
		mNextSceneFlag[1] = SceneTask::mDrawSelectBox(25, 200, 400, 200, m_menuUIgHandle[1]);
		mNextSceneFlag[2] = SceneTask::mDrawSelectBox(435, 200, 400, 200, m_menuUIgHandle[2]);
		mNextSceneFlag[3] = SceneTask::mDrawSelectBox(845, 200, 400, 200, m_menuUIgHandle[3]);
		mNextSceneFlag[4] = SceneTask::mDrawSelectBox(820, 500, 400, 200, m_menuUIgHandle[4]);
		SceneTask::mDrawSelectBox(0, -100, 1280, 300, m_menuUIgHandle[5], false);
	}
}
/******************************************************
* @brief  シーンの終了処理
* @param  None
* @return None
*******************************************************/
void SceneMenu::mFinal() {
	SceneTask::mFinal();
}