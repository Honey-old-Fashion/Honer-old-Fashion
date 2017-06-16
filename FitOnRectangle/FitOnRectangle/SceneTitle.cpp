#include "SceneTitle.h"
#include "DxLib.h"


SceneTitle::SceneTitle(ISceneChanger* changer) : SceneTask(changer) {

}


SceneTitle::~SceneTitle() {

}

void SceneTitle::mInit() {

}

void SceneTitle::mUpdate() {
#ifdef _DEBUG
	printfDx("Title\n GƒL[‚ÅƒQ[ƒ€‚Ö");
#endif

	if (CheckHitKey(KEY_INPUT_G) != 0) {
		mChangeScene->mChangeScene(eScene_Game);
	}
}

void SceneTitle::mRender() {

}

void SceneTitle::mFinal() {

}