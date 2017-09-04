#ifndef _SCENETUTORIAL_H_
#define _SCENETUTORIAL_H_

#include "SceneTask.h"
#include "ISceneChanger.h"
class SceneTutorial : public SceneTask{
private:
	int m_movieHandle;
	int m_tutorialUIgHandle[3];
public:
	SceneTutorial(ISceneChanger* changer);
	~SceneTutorial();

	virtual void mInit() override;
	virtual void mUpdate() override;
	virtual void mRender() override;
	virtual void mFinal() override;
};

#endif // !_SCENETUTORIAL_H_