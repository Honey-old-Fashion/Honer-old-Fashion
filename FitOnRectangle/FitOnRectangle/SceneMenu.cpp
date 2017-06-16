#include "SceneMenu.h"
#include "DxLib.h"


SceneMenu::SceneMenu(ISceneChanger* _changer) : SceneTask(_changer) {

}


SceneMenu::~SceneMenu() {
}


void SceneMenu::mInit() {

}

void SceneMenu::mUpdate() {
#ifdef _DEBUG
	printfDx("menu");
#endif
}

void SceneMenu::mRender() {

}

void SceneMenu::mFinal() {

}