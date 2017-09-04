#ifndef _SCENEMENU_H_
#define _SCENEMENU_H_

#include "SceneTask.h"
#include "ISceneChanger.h"
#include "GameManager.h"

class SceneMenu : public SceneTask {
private:
	int alphaNum;
	int m_menuUIgHandle[6];
	int m_getMouseX;   // マウスのx座標を取得して格納する変数
	int m_getMouseY;   // マウスのy座標を取得して格納する変数
	bool m_keyFlag;    // キー入力の状態のフラグ
	bool DrawMenuUIFlag;
public:
	SceneMenu(ISceneChanger* _changer);
	~SceneMenu();
	virtual void mInit() override;
	virtual void mUpdate() override;
	virtual void mRender() override;
	virtual void mFinal() override;
};

#endif // !_SCENEMENU_H_