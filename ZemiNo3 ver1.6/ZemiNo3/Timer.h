/*********************************************************************
* !@file Triangle.h
* @brief �^�C�}�[
* @author Takaguchi Tsuyoshi
*********************************************************************/
#pragma once
#include<time.h>
class Timer{
private:
	time_t Start, Now;  // �J�n���̎���, �o�ߎ���
	int m_fontHandle;  // �t�H���g�f�[�^���i�[����ϐ�
	static int msTimeLimit;
	
public:
	Timer();
	Timer(char *_font, int _size, int _thick);
	~Timer();

	void mUpdate(int _maxTime);
	void mRender();

	inline int mGetTime() { return msTimeLimit; }

};

