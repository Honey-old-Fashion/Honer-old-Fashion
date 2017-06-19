#pragma once

typedef enum eSceneName {
	eScene_Title,
	eScene_Game,
	eScene_Menu,
	eScene_Null
} eSceneName;


class ISceneChanger {

public:
	ISceneChanger() {};
	virtual ~ISceneChanger() = default;
	virtual void mChangeScene(eSceneName NextScene) = 0;

};

