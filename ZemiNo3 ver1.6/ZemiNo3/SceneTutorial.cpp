#include "SceneTutorial.h"
#include "DxLib.h"



SceneTutorial::SceneTutorial(ISceneChanger* changer) : SceneTask(changer){
	m_tutorialUIgHandle[0] = LoadGraph("pic/TUTORIAL_SKIP.png");
	m_tutorialUIgHandle[1] = LoadGraph("pic/TUTORIAL_AGAIN.png");
	m_tutorialUIgHandle[2] = LoadGraph("pic/TUTORIAL_STAGESELECT.png");

	m_movieHandle = LoadGraph("movie/TutorialMove.mpg");
	PlayMovieToGraph(m_movieHandle);
}


SceneTutorial::~SceneTutorial(){
}

void SceneTutorial::mInit() {

}

void SceneTutorial::mUpdate() {
	
	if (mNextSceneFlag[0] == true) {
		m_changeScene->mChangeScene(eScene_Menu);
	}
	if (mNextSceneFlag[1] == true) {

		m_changeScene->mChangeScene(eScene_Tutorial);
	}
	if (mNextSceneFlag[2] == true) {

		m_changeScene->mChangeScene(eScene_Menu);
	}

	// 以下十字キー操作の処理
	if (GetMovieStateToGraph(m_movieHandle) == 0) {
		// 左右キーでマウスカーソルの座標を更新する
		if (CheckHitKey(KEY_INPUT_LEFT) != 0) {
			SetMousePoint(150, 650);
		}
		if (CheckHitKey(KEY_INPUT_RIGHT) != 0) {
			SetMousePoint(1100, 650);
		}
	}
	else if (GetMovieStateToGraph(m_movieHandle) == 1) {
		if (CheckHitKey(KEY_INPUT_RIGHT) != 0) {
			SetMousePoint(1180, 675);
		}
	}
}

void SceneTutorial::mRender() {
	
	DrawExtendGraph(0, -125, 1280, 840, m_movieHandle, TRUE);

	if (GetMovieStateToGraph(m_movieHandle) == 1) {
		mNextSceneFlag[0] = SceneTask::mDrawSelectBox(1100, 635, 160, 80, m_tutorialUIgHandle[0]);
	}

	if (GetMovieStateToGraph(m_movieHandle) == 0) {
		mNextSceneFlag[1] = SceneTask::mDrawSelectBox(50, 600, 200, 100, m_tutorialUIgHandle[1]);
		mNextSceneFlag[2] = SceneTask::mDrawSelectBox(1000, 600, 200, 100, m_tutorialUIgHandle[2]);
	}
}

void SceneTutorial::mFinal() {

}