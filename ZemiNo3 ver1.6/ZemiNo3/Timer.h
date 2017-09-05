/*********************************************************************
* !@file Triangle.h
* @brief タイマー
* @author Takaguchi Tsuyoshi
*********************************************************************/
#pragma once
#include<time.h>
class Timer{
private:
	time_t Start, Now;  // 開始時の時間, 経過時間
	int m_fontHandle;  // フォントデータを格納する変数
	static int msTimeLimit;
	
public:
	Timer();
	Timer(char *_font, int _size, int _thick);
	~Timer();

	void mUpdate(int _maxTime);
	void mRender();

	inline int mGetTime() { return msTimeLimit; }

};

