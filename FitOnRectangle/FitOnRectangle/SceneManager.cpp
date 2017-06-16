#include "SceneManager.h"
#include "SceneGame.h"
#include "SceneTitle.h"
#include "SceneMenu.h"

SceneManager::SceneManager() : mNextScene(eScene_Null) {
	mScene = (IScene*) new SceneTitle(this);
}


SceneManager::~SceneManager() {

}

void SceneManager::mInit() {
	mScene->mInit();
}

void SceneManager::mUpdate() {

	if (mNextScene != eScene_Null) {

		mScene->mFinal();
		delete mScene;

		switch (mNextScene) {
		case eScene_Game:
			mScene = (IScene*) new SceneGame(this);
			break;
		case eScene_Title:
			mScene = (IScene*) new SceneTitle(this);
			break;
		case eScene_Menu:
			mScene = (IScene*) new SceneMenu(this);
			break;
		}
		mNextScene = eScene_Null;
			mScene->mInit();
	}
	mScene->mUpdate();
}

void SceneManager::mRender() {
	mScene->mRender();
}

void SceneManager::mFinal() {
	mScene->mFinal();
	delete mScene;
}

void SceneManager::mChangeScene(eSceneName _NextScene) {
	mNextScene = _NextScene;
}