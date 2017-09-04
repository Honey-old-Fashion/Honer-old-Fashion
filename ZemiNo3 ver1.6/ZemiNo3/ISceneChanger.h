#ifndef _ISCENECHANGER_H_
#define _ISCENECHANGER_H_

typedef enum eSceneName {
	eScene_Title,
	eScene_Game,
	eScene_Menu,
	eScene_Tutorial,
	eScene_Result,
	eScene_Null
} eSceneName;


class ISceneChanger {

public:
	ISceneChanger() {};
	virtual ~ISceneChanger() = default;
	virtual void mChangeScene(eSceneName NextScene) = 0;

};

#endif // !_ISCENECHANGER_H_