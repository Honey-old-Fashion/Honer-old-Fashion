#ifndef _SCENEMENU_H_
#define _SCENEMENU_H_

#include "SceneTask.h"
#include "ISceneChanger.h"
#include "GameManager.h"

class SceneMenu : public SceneTask {
private:
	int alphaNum;
	int m_menuUIgHandle[6];
	int m_getMouseX;   // �}�E�X��x���W���擾���Ċi�[����ϐ�
	int m_getMouseY;   // �}�E�X��y���W���擾���Ċi�[����ϐ�
	bool m_keyFlag;    // �L�[���͂̏�Ԃ̃t���O
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