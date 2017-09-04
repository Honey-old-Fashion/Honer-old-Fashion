#include "SceneResult.h"
#include "GameManager.h"
#include "DxLib.h"

/******************************************************
* @brief  SceneTitleのコンストラクター
@param  ISceneChanger changer
* @return None
*******************************************************/
SceneResult::SceneResult(ISceneChanger* changer) : SceneTask(changer) {
	time = new Timer;
	m_clearTime = time->mGetTime();

	m_timeTextX = -200;
	m_rankTextX = -200;
	m_textFlag = 0;

	mGraphicHandle = LoadGraph("pic/Title.jpg");
	m_resultUIgHandle[0] = LoadGraph("pic/RESULT_TITLE.png");
	m_resultUIgHandle[1] = LoadGraph("pic/RESULT_STAGESELECT.png");
	m_resultUIgHandle[2] = LoadGraph("pic/RESULT_NEXTSTAGE.png");

	// フォントの設定
	m_fontHandle = CreateFontToHandle("HGP明朝E", 80, 3);
}

/******************************************************
* @brief  SceneTitleのデストラクター
* @param  None
* @return None
*******************************************************/
SceneResult::~SceneResult() {
	// フォントデータの破棄
	DeleteFontToHandle(m_fontHandle);
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

	if (mNextSceneFlag[0] == true) {
		m_changeScene->mChangeScene(eScene_Title);
	}
	if (mNextSceneFlag[1] == true) {
		m_changeScene->mChangeScene(eScene_Menu);

	}

	if (mNextSceneFlag[2] == true) {
		if(gameManager->GetStageID() == e_Stage::e_StageFirst){
			gameManager->SetStageID(e_Stage::e_StageSecond);
		}
		else{
			gameManager->SetStageID(e_Stage::e_StageThird);
		}

		m_changeScene->mChangeScene(eScene_Game);
	}

	switch (m_textFlag) {
	case 0:
		m_timeTextX += 5;
		if (m_timeTextX >= 350) {
			m_textFlag = 2;
		}
		break;
	case 2:
		m_rankTextX += 5;
		if (m_rankTextX >= 340) {
			m_textFlag = 3;
		}
		break;
	default:
		break;
	}

	// 以下十字キーの処理
	GetMousePoint(&m_getMouseX, &m_getMouseY);
	// キーが入力されていないなら
	if (m_keyFlag == false) {
		// カーソルがTitleボタンの上にあるなら
		if (m_getMouseX >= 25 && m_getMouseX <= (25 + 400) &&
			m_getMouseY >= 500 && m_getMouseY <= (500 + 200)) {

			// StageSelectのボタンの上へカーソルを動かす
			if (CheckHitKey(KEY_INPUT_RIGHT) != 0) {
				SetMousePoint(635, 600);
				m_keyFlag = true;
			}
		}
		// カーソルがStageSelectボタンの上にあるなら
		else if (m_getMouseX >= 435 && m_getMouseX <= (435 + 400) &&
			m_getMouseY >= 500 && m_getMouseY <= (500 + 200)) {

			// NextStageボタンの上へカーソルを動かす
			if (CheckHitKey(KEY_INPUT_RIGHT) != 0) {
				SetMousePoint(1045, 600);
				m_keyFlag = true;
			}
			// StageSelectボタンの上へカーソルを動かす
			if (CheckHitKey(KEY_INPUT_LEFT) != 0) {
				SetMousePoint(225, 600);
				m_keyFlag = true;
			}
		}
		// カーソルがNextStageボタンの上にあるなら
		else if (m_getMouseX >= 845 && m_getMouseX <= (845 + 400) &&
			m_getMouseY >= 500 && m_getMouseY <= (500 + 200)) {

			// StageSelectボタンの上へカーソルを動かす
			if (CheckHitKey(KEY_INPUT_LEFT) != 0) {
				SetMousePoint(635, 600);
				m_keyFlag = true;
			}
		}
		else {
			// Titleボタンの上へカーソルを動かす
			if (CheckHitKey(KEY_INPUT_LEFT) != 0) {
				SetMousePoint(225, 600);
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
void SceneResult::mRender() {

	SceneTask::mRender();

	DrawStringToHandle(450, 100, "Result", GetColor(255, 255, 255), m_fontHandle);


	// クリア時間の表示
	DrawStringToHandle(m_timeTextX, 250, "Time:", GetColor(255, 255, 255), m_fontHandle);
	if (m_textFlag >= 1) {
		DrawFormatStringToHandle((m_timeTextX + 190), 250, GetColor(255, 255, 255), m_fontHandle, "%d Sec", time->mGetTime());
	}
	
	// クリア時間に応じたランク表示
	DrawStringToHandle(m_rankTextX, 350, "Rank:", GetColor(255, 255, 255), m_fontHandle);
	if (m_textFlag >= 3) {
		// 以下時間に応じたランク分岐
		if (m_clearTime >= 59) {
			DrawStringToHandle((m_rankTextX + 200), 350, _T("SSS"), GetColor(255, 255, 255), m_fontHandle);
		}
		else if (m_clearTime >= 58) {
			DrawStringToHandle((m_rankTextX + 200), 350, _T("SS"), GetColor(255, 255, 255), m_fontHandle);
		}
		else if (m_clearTime >= 57) {
			DrawStringToHandle((m_rankTextX + 200), 350, _T("S"), GetColor(255, 255, 255), m_fontHandle);
		}
		else if (m_clearTime >= 50) {
			DrawStringToHandle((m_rankTextX + 200), 350, _T("AAA"), GetColor(255, 255, 255), m_fontHandle);
		}

		// ボタンの表示
		mNextSceneFlag[0] = SceneTask::mDrawSelectBox(25, 500, 400, 200, m_resultUIgHandle[0]);
		mNextSceneFlag[1] = SceneTask::mDrawSelectBox(435, 500, 400, 200, m_resultUIgHandle[1]);
		
		if (gameManager->GetStageID() != e_Stage::e_StageThird) {
			mNextSceneFlag[2] = SceneTask::mDrawSelectBox(845, 500, 400, 200, m_resultUIgHandle[2]);
		}
	}
}
/******************************************************
* @brief  シーンの終了処理
* @param  None
* @return None
*******************************************************/
void SceneResult::mFinal() {
	SceneTask::mFinal();
}