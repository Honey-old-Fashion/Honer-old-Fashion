#include "Timer.h"
#include "DxLib.h"

// 静的メンバ変数の定義
int Timer::msTimeLimit;

Timer::Timer() {

}

/*************************************************************************
* @brief コンストラクタ
* @param[in] 使用するフォント名, フォントサイズ, 文字の太さ
* @return None
*************************************************************************/
Timer::Timer(char *_font, int _size, int _thick){
	time(&Start);
	// フォントの設定
	m_fontHandle = CreateFontToHandle(_font, _size, _thick);
}


Timer::~Timer(){
	// フォントデータの破棄
	DeleteFontToHandle(m_fontHandle);
}

void Timer::mUpdate(int _maxTime) {
	// 経過時間の取得
	time(&Now);
	// 制限時間を表示
	msTimeLimit = (int)((Start + _maxTime) - Now);
}

void Timer::mRender() {
	DrawFormatStringToHandle(950, 30, GetColor(0, 0, 0), m_fontHandle, "Time:%d Sec", msTimeLimit);
}