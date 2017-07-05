#include "SceneResult.h"
#include "DxLib.h"

/******************************************************
* @brief  SceneTitle�̃R���X�g���N�^�[
@param  ISceneChanger changer
* @return None
*******************************************************/
SceneResult::SceneResult(ISceneChanger* changer) : SceneTask(changer) {

}

/******************************************************
* @brief  SceneTitle�̃f�X�g���N�^�[
* @param  None
* @return None
*******************************************************/
SceneResult::~SceneResult() {

}

/******************************************************
* @brief  �V�[���̏�����
* @param  None
* @return None
*******************************************************/
void SceneResult::mInit() {

}

/******************************************************
* @brief  �V�[���̍X�V
* @param  None
* @return None
*******************************************************/
void SceneResult::mUpdate() {
#ifdef _DEBUG
	printfDx("Result\n T�L�[�Ń^�C�g����");
#endif

	if (CheckHitKey(KEY_INPUT_T) != 0) {
		m_changeScene->mChangeScene(eScene_Title);
	}

}

/******************************************************
* @brief  �V�[���̕`��
* @param  None
* @return None
*******************************************************/
void SceneResult::mRender() {
	DrawString(400, 400, _T("�X�e�[�W1�N���A�I�I"), GetColor(255, 255, 255));
}
/******************************************************
* @brief  �V�[���̏I������
* @param  None
* @return None
*******************************************************/
void SceneResult::mFinal() {
	SceneTask::mFinal();
}