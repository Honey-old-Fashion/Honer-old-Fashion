#ifndef _SCENEMENU_H_
#define _SCENEMENU_H_

#include "SceneTask.h"
#include "ISceneChanger.h"

class SceneMenu : public SceneTask { 
public:
	SceneMenu(ISceneChanger* _changer);
	~SceneMenu();
	virtual void mInit() override;
	virtual void mUpdate() override;
	virtual void mRender() override;
	virtual void mFinal() override;
};

#endif // !_SCENEMENU_H_