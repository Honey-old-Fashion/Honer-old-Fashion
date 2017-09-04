#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_

//呼び出し方　GameControl->関数名
#define gameManager GameManager::GetInstane()

#include "DxLib.h"
#include "IObject.h"

#pragma region 列挙型の定義

enum class e_Stage {
	e_StageFirst = 0,
	e_StageSecond,
	e_StageThird
};

enum class e_charType {
	eRect_Red,
	eRect_Green,
	eRect_Blue,
	eTri_Red,
	eTri_Green,
	eTri_Blue,
	eNull
};
#pragma endregion

class GameManager final {

private:
	GameManager();

#pragma region 非公開メンバの定義など

	struct ObjData {
		bool hitFlag;

	};



	const char CRed = 0;
	const char CGreen = 1;
	const char CBlue = 2;
	const int width = 20;
	const int height = 20;
	const int objSize = 40;
	int score;

	POINT playerPoint;
	POINT gimmickPoint;
	
	e_Stage stageId;
	e_charType currentCharType;

	bool gimmicActioncolorFlag[COLOR_NUM];

	struct FitData {
		bool fitRectDownFlag[COLOR_NUM];
		bool fitTriDownFlag[COLOR_NUM];
		POINT gimmickPos[COLOR_NUM];
	};

	struct UpData {
		bool onUpGimmickRectFlag[COLOR_NUM];
		bool onUpGimmickTriFlag[COLOR_NUM];
		bool upReadyGimmickFlag[COLOR_NUM];
		bool upRectFlag[COLOR_NUM];
		bool upTriFlag[COLOR_NUM];
		POINT onGimmickPos;
	};

	struct DropData {
		bool dorpRectFlag[COLOR_NUM];
		bool dorpTriFlag[COLOR_NUM];
		POINT dropPos;
	};

	FitData fitData;
	UpData upData;
	DropData dropData;

	bool rectGoalFlag[COLOR_NUM];
	bool triGoalFlag[COLOR_NUM];

	bool rectCanMoveLeft[COLOR_NUM];
	bool rectCanMoveRight[COLOR_NUM];

	bool triCanMoveLeft[COLOR_NUM];
	bool triCanMoveRight[COLOR_NUM];

	bool gameClearFlag;

#pragma endregion

public:

#pragma region 公開メンバの定義など
	
	~GameManager();
	static GameManager* GetInstane() {
		static GameManager ptr;
		return &ptr;
	}
	
	ObjData HitTest(POINT charPoint,POINT gimmickPoint,int gimmickID);

	
	inline void			SetStageID(	e_Stage _stageId) { stageId = _stageId; }
	inline e_Stage		GetStageID() { return stageId; }

	inline void			AddScore(int adder) { score += adder; }
	inline int			GetScore() { return score; }

	inline void			SetGimmickActiveFlag(int colorType, bool flag) { gimmicActioncolorFlag[colorType] = flag; }
	inline bool			GetGimmickActiveFlag(eColor colorType) { return gimmicActioncolorFlag[colorType]; }

	inline void			ChangeCharType(e_charType nextCharType) { currentCharType = nextCharType; }
	inline e_charType	GetCurrentCharType() { return currentCharType; }

	inline void			SetGameClearFlag(bool flag) { gameClearFlag = flag; }
	inline bool			GetGameClearFlag() { return gameClearFlag; }

	inline void			SetRectGoalFlag(eColor color, bool flag) { rectGoalFlag[color] = flag; }
	inline bool			GetRectGoalFlag(eColor color) { return rectGoalFlag[color]; }

	inline void			SetTriGoalFlag(eColor color, bool flag) { triGoalFlag[color] = flag; }
	inline bool			GetTriGoalFlag(eColor color) { return triGoalFlag[color]; }

	inline void			SetRectCanMoveLeftFlag(eColor color, bool flag) { rectCanMoveLeft[color] = flag; }
	inline bool			GetRectCanMoveLeftFlag(eColor color) { return rectCanMoveLeft[color]; }

	inline void			SetRectCanMoveRightFlag(eColor color, bool flag) { rectCanMoveRight[color] = flag; }
	inline bool			GetRectCanMoveRightFlag(eColor color) { return rectCanMoveRight[color]; }
	
	inline void			SetTriCanMoveLeftFlag(eColor color, bool flag) { triCanMoveLeft[color] = flag; }
	inline bool			GetTriCanMoveLeftFlag(eColor color) { return triCanMoveLeft[color]; }

	inline void			SetTriCanMoveRightFlag(eColor color, bool flag) { triCanMoveRight[color] = flag; }
	inline bool			GetTriCanMoveRightFlag(eColor color) { return triCanMoveRight[color]; }

	inline void			SetFitRectFlag(eColor color, bool flag, POINT pos) { 
							fitData.fitRectDownFlag[color] = flag;
							fitData.gimmickPos[color].x = pos.x;
							fitData.gimmickPos[color].y = pos.y;
						}

	inline void			SetFitRectFlag(eColor color, bool flag) {
							fitData.fitRectDownFlag[color] = flag;
						}

	inline FitData			GetFitRectFlag() { return  fitData; }

	inline void			SetFitTriFlag(eColor color, bool flag, POINT pos) { 
							fitData.fitTriDownFlag[color] = flag; 
							fitData.gimmickPos[color].x = pos.x;
							fitData.gimmickPos[color].y = pos.y;
					}

	inline void			SetFitTriFlag(eColor color, bool flag) {
							fitData.fitTriDownFlag[color] = flag;
					}
	inline FitData		GetFitTriFlag() { return  fitData; }

	inline void			SetRectOnUpGimmickFlag(eColor color, eColor gColor, bool flag, POINT Pos) {
							upData.onUpGimmickRectFlag[color] = flag; 
							upData.upReadyGimmickFlag[gColor] = flag;
							upData.onGimmickPos.x = Pos.x;
							upData.onGimmickPos.y = Pos.y;
						}
	inline void			SetRectOnUpGimmickFlag(eColor color, bool flag) {
							upData.onUpGimmickRectFlag[color] = flag;
							}

	inline void			SetTriOnUpGimmickFlag(eColor color, eColor gColor, bool flag, POINT Pos) {
							upData.onUpGimmickTriFlag[color] = flag;
							upData.upReadyGimmickFlag[gColor] = flag;
							upData.onGimmickPos.x = Pos.x;
							upData.onGimmickPos.y = Pos.y;
						}

	inline void			SetTriOnUpGimmickFlag(eColor color, bool flag) {
							upData.onUpGimmickTriFlag[color] = flag;
						}
	inline void			SetUpRectFlag(eColor color, bool flag) { upData.upRectFlag[color] = flag; }
	inline void         SetUpTriFlag(eColor color, bool flag) { upData.upTriFlag[color] = flag; }

	inline UpData		GetUpGimmickFlagAll() { return upData; }

	inline void			SetRectDropFlag(eColor color, bool flag) {
							dropData.dorpRectFlag[color] = flag;
						}

	inline void			SetRectDropFlag(eColor color, bool flag, POINT pos) {
							dropData.dorpRectFlag[color] = flag;
							dropData.dropPos.x = pos.x;
							dropData.dropPos.y = pos.y;
						}

	inline void			SetTriDropFlag(eColor color, bool flag) {
							dropData.dorpTriFlag[color] = flag;
						}

	inline void			SetTriDropFlag(eColor color, bool flag, POINT pos) {
							dropData.dorpTriFlag[color] = flag;
							dropData.dropPos.x = pos.x;
							dropData.dropPos.y = pos.y;
						}

	inline DropData		GetDropDataAll() { return dropData; }

#pragma endregion

};

#endif // !_GAMEMANAGER_H_