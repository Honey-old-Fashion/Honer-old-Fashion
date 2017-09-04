#include "SceneResult.h"
#include "GameManager.h"
#include "DxLib.h"

/******************************************************
* @brief  SceneTitle�̃R���X�g���N�^�[
@param  ISceneChanger changer
* @return None
*******************************************************/
SceneResult::SceneResult(ISceneChanger* changer) : SceneTask(changer) {
	time = new Timer;
	m_clearTime = time->mGetTime();

	m_timeTextX = -200;
	m_rankTextX = -200;
	m_textFlag = 0;

	mGraphicHandle = LoadGraph("pic/Title.jpg");
	m_resultUIgHandle[0] = LoadGraph("pic/RESULT_TITLE.png");
	m_resultUIgHandle[1] = LoadGraph("pic/RESULT_STAGESELECT.png");
	m_resultUIgHandle[2] = LoadGraph("pic/RESULT_NEXTSTAGE.png");

	// �t�H���g�̐ݒ�
	m_fontHandle = CreateFontToHandle("HGP����E", 80, 3);
}

/******************************************************
* @brief  SceneTitle�̃f�X�g���N�^�[
* @param  None
* @return None
*******************************************************/
SceneResult::~SceneResult() {
	// �t�H���g�f�[�^�̔j��
	DeleteFontToHandle(m_fontHandle);
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

	if (mNextSceneFlag[0] == true) {
		m_changeScene->mChangeScene(eScene_Title);
	}
	if (mNextSceneFlag[1] == true) {
		m_changeScene->mChangeScene(eScene_Menu);

	}

	if (mNextSceneFlag[2] == true) {
		if(gameManager->GetStageID() == e_Stage::e_StageFirst){
			gameManager->SetStageID(e_Stage::e_StageSecond);
		}
		else{
			gameManager->SetStageID(e_Stage::e_StageThird);
		}

		m_changeScene->mChangeScene(eScene_Game);
	}

	switch (m_textFlag) {
	case 0:
		m_timeTextX += 5;
		if (m_timeTextX >= 350) {
			m_textFlag = 2;
		}
		break;
	case 2:
		m_rankTextX += 5;
		if (m_rankTextX >= 340) {
			m_textFlag = 3;
		}
		break;
	default:
		break;
	}

	// �ȉ��\���L�[�̏���
	GetMousePoint(&m_getMouseX, &m_getMouseY);
	// �L�[�����͂���Ă��Ȃ��Ȃ�
	if (m_keyFlag == false) {
		// �J�[�\����Title�{�^���̏�ɂ���Ȃ�
		if (m_getMouseX >= 25 && m_getMouseX <= (25 + 400) &&
			m_getMouseY >= 500 && m_getMouseY <= (500 + 200)) {

			// StageSelect�̃{�^���̏�փJ�[�\���𓮂���
			if (CheckHitKey(KEY_INPUT_RIGHT) != 0) {
				SetMousePoint(635, 600);
				m_keyFlag = true;
			}
		}
		// �J�[�\����StageSelect�{�^���̏�ɂ���Ȃ�
		else if (m_getMouseX >= 435 && m_getMouseX <= (435 + 400) &&
			m_getMouseY >= 500 && m_getMouseY <= (500 + 200)) {

			// NextStage�{�^���̏�փJ�[�\���𓮂���
			if (CheckHitKey(KEY_INPUT_RIGHT) != 0) {
				SetMousePoint(1045, 600);
				m_keyFlag = true;
			}
			// StageSelect�{�^���̏�փJ�[�\���𓮂���
			if (CheckHitKey(KEY_INPUT_LEFT) != 0) {
				SetMousePoint(225, 600);
				m_keyFlag = true;
			}
		}
		// �J�[�\����NextStage�{�^���̏�ɂ���Ȃ�
		else if (m_getMouseX >= 845 && m_getMouseX <= (845 + 400) &&
			m_getMouseY >= 500 && m_getMouseY <= (500 + 200)) {

			// StageSelect�{�^���̏�փJ�[�\���𓮂���
			if (CheckHitKey(KEY_INPUT_LEFT) != 0) {
				SetMousePoint(635, 600);
				m_keyFlag = true;
			}
		}
		else {
			// Title�{�^���̏�փJ�[�\���𓮂���
			if (CheckHitKey(KEY_INPUT_LEFT) != 0) {
				SetMousePoint(225, 600);
				m_keyFlag = true;
			}
		}
	}

	// �\���L�[�����͂���Ă��Ȃ��Ȃ�
	if (CheckHitKey(KEY_INPUT_LEFT) == 0 && CheckHitKey(KEY_INPUT_RIGHT) == 0 &&
		CheckHitKey(KEY_INPUT_UP) == 0 && CheckHitKey(KEY_INPUT_DOWN) == 0) {
		
		m_keyFlag = false;
	}
}

/******************************************************
* @brief  �V�[���̕`��
* @param  None
* @return None
*******************************************************/
void SceneResult::mRender() {

	SceneTask::mRender();

	DrawStringToHandle(450, 100, "Result", GetColor(255, 255, 255), m_fontHandle);


	// �N���A���Ԃ̕\��
	DrawStringToHandle(m_timeTextX, 250, "Time:", GetColor(255, 255, 255), m_fontHandle);
	if (m_textFlag >= 1) {
		DrawFormatStringToHandle((m_timeTextX + 190), 250, GetColor(255, 255, 255), m_fontHandle, "%d Sec", time->mGetTime());
	}
	
	// �N���A���Ԃɉ����������N�\��
	DrawStringToHandle(m_rankTextX, 350, "Rank:", GetColor(255, 255, 255), m_fontHandle);
	if (m_textFlag >= 3) {
		// �ȉ����Ԃɉ����������N����
		if (m_clearTime >= 59) {
			DrawStringToHandle((m_rankTextX + 200), 350, _T("SSS"), GetColor(255, 255, 255), m_fontHandle);
		}
		else if (m_clearTime >= 58) {
			DrawStringToHandle((m_rankTextX + 200), 350, _T("SS"), GetColor(255, 255, 255), m_fontHandle);
		}
		else if (m_clearTime >= 57) {
			DrawStringToHandle((m_rankTextX + 200), 350, _T("S"), GetColor(255, 255, 255), m_fontHandle);
		}
		else if (m_clearTime >= 50) {
			DrawStringToHandle((m_rankTextX + 200), 350, _T("AAA"), GetColor(255, 255, 255), m_fontHandle);
		}

		// �{�^���̕\��
		mNextSceneFlag[0] = SceneTask::mDrawSelectBox(25, 500, 400, 200, m_resultUIgHandle[0]);
		mNextSceneFlag[1] = SceneTask::mDrawSelectBox(435, 500, 400, 200, m_resultUIgHandle[1]);
		
		if (gameManager->GetStageID() != e_Stage::e_StageThird) {
			mNextSceneFlag[2] = SceneTask::mDrawSelectBox(845, 500, 400, 200, m_resultUIgHandle[2]);
		}
	}
}
/******************************************************
* @brief  �V�[���̏I������
* @param  None
* @return None
*******************************************************/
void SceneResult::mFinal() {
	SceneTask::mFinal();
}