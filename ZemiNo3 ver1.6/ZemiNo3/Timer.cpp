#include "Timer.h"
#include "DxLib.h"

// �ÓI�����o�ϐ��̒�`
int Timer::msTimeLimit;

Timer::Timer() {

}

/*************************************************************************
* @brief �R���X�g���N�^
* @param[in] �g�p����t�H���g��, �t�H���g�T�C�Y, �����̑���
* @return None
*************************************************************************/
Timer::Timer(char *_font, int _size, int _thick){
	time(&Start);
	// �t�H���g�̐ݒ�
	m_fontHandle = CreateFontToHandle(_font, _size, _thick);
}


Timer::~Timer(){
	// �t�H���g�f�[�^�̔j��
	DeleteFontToHandle(m_fontHandle);
}

void Timer::mUpdate(int _maxTime) {
	// �o�ߎ��Ԃ̎擾
	time(&Now);
	// �������Ԃ�\��
	msTimeLimit = (int)((Start + _maxTime) - Now);
}

void Timer::mRender() {
	DrawFormatStringToHandle(950, 30, GetColor(0, 0, 0), m_fontHandle, "Time:%d Sec", msTimeLimit);
}