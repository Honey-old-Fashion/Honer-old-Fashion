#include "SceneMenu.h"
#include "DxLib.h"


SceneMenu::SceneMenu(ISceneChanger* _changer) : SceneTask(_changer) {
	}


SceneMenu::~SceneMenu() {
}

/******************************************************
* @brief  �V�[���̏�����
* @param  None
* @return None
*******************************************************/
void SceneMenu::mInit() {
	mGraphicHandle = LoadGraph("pic/Title.jpg");
	m_menuUIgHandle[0] = LoadGraph("pic/MENU_BACK.png");
	m_menuUIgHandle[1] = LoadGraph("pic/MENU_STAGE1.png");
	m_menuUIgHandle[2] = LoadGraph("pic/MENU_STAGE2.png");
	m_menuUIgHandle[3] = LoadGraph("pic/MENU_STAGE3.png");
	m_menuUIgHandle[4] = LoadGraph("pic/MENU_TUTORIAL.png");
	m_menuUIgHandle[5] = LoadGraph("pic/MENU_STAGESELECT.png");
	SetMousePoint(225, 300);
	alphaNum = 0;
	m_keyFlag = false;
	DrawMenuUIFlag = false;
}

/******************************************************
* @brief  �V�[���̍X�V
* @param  None
* @return None
*******************************************************/
void SceneMenu::mUpdate() {
#ifdef _DEBUG
	printfDx("menu");
#endif
	if (mNextSceneFlag[0] == true) {
		m_changeScene->mChangeScene(eScene_Title);
	}

	if (mNextSceneFlag[1] == true) {
		gameManager->SetStageID(e_Stage::e_StageFirst);	
		m_changeScene->mChangeScene(eScene_Game);
	}

	if (mNextSceneFlag[2] == true) {
		gameManager->SetStageID(e_Stage::e_StageSecond);		
		m_changeScene->mChangeScene(eScene_Game);
	}

	if (mNextSceneFlag[3] == true) {
		gameManager->SetStageID(e_Stage::e_StageThird);		
		m_changeScene->mChangeScene(eScene_Game);
	}

	if (mNextSceneFlag[4] == true) {
		m_changeScene->mChangeScene(eScene_Tutorial);
	}

	// �ȉ��\���L�[�̏���
	GetMousePoint(&m_getMouseX, &m_getMouseY);
	// �L�[�����͂���Ă��Ȃ��Ȃ�
	if (m_keyFlag == false) {
		// �J�[�\����Stage1�{�^���̏�ɂ���Ȃ�
		if (m_getMouseX >= 25 && m_getMouseX <= (25 + 400) &&
			m_getMouseY >= 200 && m_getMouseY <= (200 + 200)) {

			// Stage2�̃{�^���̏�փJ�[�\���𓮂���
			if (CheckHitKey(KEY_INPUT_RIGHT) != 0) {
				SetMousePoint(635, 300);
				m_keyFlag = true;
			}
			// Back�{�^���̏�փJ�[�\���𓮂���
			if (CheckHitKey(KEY_INPUT_DOWN) != 0) {
				SetMousePoint(250, 600);
				m_keyFlag = true;
			}
		}
		// �J�[�\����Stage2�{�^���̏�ɂ���Ȃ�
		else if (m_getMouseX >= 435 && m_getMouseX <= (435 + 400) &&
			m_getMouseY >= 200 && m_getMouseY <= (200 + 200)) {

			// Stage3�{�^���̏�փJ�[�\���𓮂���
			if (CheckHitKey(KEY_INPUT_RIGHT) != 0) {
				SetMousePoint(1045, 300);
				m_keyFlag = true;
			}
			// Stage1�{�^���̏�փJ�[�\���𓮂���
			if (CheckHitKey(KEY_INPUT_LEFT) != 0) {
				SetMousePoint(225, 300);
				m_keyFlag = true;
			}
			if (CheckHitKey(KEY_INPUT_DOWN) != 0) {
				SetMousePoint(250, 600);
				m_keyFlag = true;
			}
		}
		// �J�[�\����Stage3�{�^���̏�ɂ���Ȃ�
		else if (m_getMouseX >= 845 && m_getMouseX <= (845 + 400) &&
			m_getMouseY >= 200 && m_getMouseY <= (200 + 200)) {

			// Stage2�{�^���̏�փJ�[�\���𓮂���
			if (CheckHitKey(KEY_INPUT_LEFT) != 0) {
				SetMousePoint(635, 300);
				m_keyFlag = true;
			}
			// Tutorial�{�^���̏�փJ�[�\���𓮂���
			if (CheckHitKey(KEY_INPUT_DOWN) != 0) {
				SetMousePoint(1020, 600);
				m_keyFlag = true;
			}
		}
		// �J�[�\����Back�{�^���̏�ɂ���Ȃ�
		else if (m_getMouseX >= 50 && m_getMouseX <= (50 + 400) &&
			m_getMouseY >= 500 && m_getMouseY <= (500 + 200)) {

			if (CheckHitKey(KEY_INPUT_RIGHT) != 0) {
				SetMousePoint(1020, 600);
				m_keyFlag = true;
			}
			// Stage1�{�^���̏�փJ�[�\���𓮂���
			if (CheckHitKey(KEY_INPUT_UP) != 0) {
				SetMousePoint(250, 300);
				m_keyFlag = true;
			}
		}
		// �J�[�\����Tutorial�{�^���̏�ɂ���Ȃ�
		else if (m_getMouseX >= 820 && m_getMouseX <= (820 + 400) &&
			m_getMouseY >= 500 && m_getMouseY <= (500 + 200)) {
			
			if (CheckHitKey(KEY_INPUT_LEFT) != 0) {
				SetMousePoint(250, 600);
				m_keyFlag = true;
			}
			if (CheckHitKey(KEY_INPUT_UP) != 0) {
				SetMousePoint(1045, 300);
				m_keyFlag = true;
			}
		}
		else {
			// Stage1�{�^���̏�փJ�[�\���𓮂���
			if (CheckHitKey(KEY_INPUT_LEFT) != 0) {
				SetMousePoint(225, 300);
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
void SceneMenu::mRender() {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alphaNum);
	if (alphaNum <= 255) {
		alphaNum += 5;
		if (alphaNum == 255) DrawMenuUIFlag = true;
	}
	SceneTask::mRender();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	if (DrawMenuUIFlag == true) {
		mNextSceneFlag[0] = SceneTask::mDrawSelectBox(50, 500, 400, 200, m_menuUIgHandle[0]);
		mNextSceneFlag[1] = SceneTask::mDrawSelectBox(25, 200, 400, 200, m_menuUIgHandle[1]);
		mNextSceneFlag[2] = SceneTask::mDrawSelectBox(435, 200, 400, 200, m_menuUIgHandle[2]);
		mNextSceneFlag[3] = SceneTask::mDrawSelectBox(845, 200, 400, 200, m_menuUIgHandle[3]);
		mNextSceneFlag[4] = SceneTask::mDrawSelectBox(820, 500, 400, 200, m_menuUIgHandle[4]);
		SceneTask::mDrawSelectBox(0, -100, 1280, 300, m_menuUIgHandle[5], false);
	}
}
/******************************************************
* @brief  �V�[���̏I������
* @param  None
* @return None
*******************************************************/
void SceneMenu::mFinal() {
	SceneTask::mFinal();
}