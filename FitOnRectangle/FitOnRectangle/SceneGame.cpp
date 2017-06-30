#include "SceneGame.h"
#include "DxLib.h"

/******************************************************
* @brief  SceneGame�̃R���X�g���N�^�[
* @param  ISceneChanger* changer
* @return None
*******************************************************/
SceneGame::SceneGame(ISceneChanger* _changer) : SceneTask(_changer) {

}

/******************************************************
* @brief  SceneGame�̃f�X�g���N�^�[
* @param  None
* @return None
*******************************************************/
SceneGame::~SceneGame() {

}

/******************************************************
* @brief  �V�[���̏�����
* @param  None
* @return None
*******************************************************/
void SceneGame::mInit() {
}

/******************************************************
* @brief  �V�[���̍X�V
* @param  None
* @return None
*******************************************************/
void SceneGame::mUpdate() {
#ifdef _DEBUG
	printfDx("game\nT�L�[�Ń^�C�g����");
#endif
	SceneTask::mRender();
	if (CheckHitKey(KEY_INPUT_T) != 0) {
		m_changeScene->mChangeScene(eScene_Title);
	}
}

/******************************************************
* @brief  �V�[���̕`��
* @param  None
* @return None
*******************************************************/
void SceneGame::mRender() {
	SceneTask::mRender();
	}

/******************************************************
* @brief  �V�[���̏I������
* @param  None
* @return None
*******************************************************/
void SceneGame::mFinal() {
	SceneTask::mFinal();
}