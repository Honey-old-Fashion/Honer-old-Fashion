#include "SecondStage.h"
#include "Singleton.h"
#include "GameManager.h"
#include "FloarObject.h"
#include "Rectangle.h"
#include "GateGimmick.h"
#include "DropGimmick.h"
#include "GoalRectAngleGimmick.h"
#include "GoalTriangle.h"
#include "StageManager.h"
#include "Rectangle.h"
#include "FitRect.h"
#include "FitTriangle.h"
#include "UpGimmick.h"
#include "WallObject.h"
#include "triangle.h"
#include "BallGimmick.h"

#define StageObject objData.iObject[ii][jj]
#define case break; case
#define SHIFT_SPACE_X 100
#define SHIFT_SPACE_Y 250



SecondStage::SecondStage(){
	STAGE_DOUBLE_LOOP{
		objData.iObject[ii][jj] = nullptr;
	}LOOP_END;
}


SecondStage::~SecondStage(){
}

void SecondStage::mSetUp() {
	STAGE_DOUBLE_LOOP{
		switch (m_stage[ii][jj]) {
		case 0://0 –³
			StageObject = nullptr;
		case 1://1 •Ç
			StageObject = (IObject*) new WallObject(SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
		case 2://2 °
			StageObject = (IObject*) new WallObject(SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
		case 3://3 ÔƒQ[ƒg
			StageObject = (IObject*) new GateGimmick(eColor_Red, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
		case 4://4 —ÎƒQ[ƒg
			StageObject = (IObject*) new GateGimmick(eColor_Green, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
		case 5://5 ÂƒQ[ƒg
			StageObject = (IObject*) new GateGimmick(eColor_Blue, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
		case 6://6 Ô·‚èã‚ª‚é°
			StageObject = (IObject*) new UpGimmick(eColor_Red, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
		case 7://7 —Î·‚èã‚ª‚é°
			StageObject = (IObject*) new UpGimmick(eColor_Green, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
		case 8://8 Â·‚èã‚ª‚é°
			StageObject = (IObject*) new UpGimmick(eColor_Blue, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
		case 9://9 Ô—Ž‚Æ‚µŒŠ
			StageObject = (IObject*) new DropGimmick(SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
		case 10://10—Î—Ž‚Æ‚µŒŠ
			StageObject = (IObject*) new DropGimmick(SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
		case 11://11Â—Ž‚Æ‚µŒŠ
			StageObject = (IObject*) new DropGimmick(SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
		case 12://12ƒ{[ƒ‹
			StageObject = (IObject*) new BallGimmick(SHIFT_SPACE_X + ((CHAR_SIZE * jj) + (CHAR_SIZE / 2)), SHIFT_SPACE_Y + (40 * ii + (CHAR_SIZE / 2)));
		case 13://13ÔŽlŠpƒLƒƒƒ‰
			StageObject = (IObject*) new class Rectangle(eColor_Red, SHIFT_SPACE_X + CHAR_SIZE * jj + CHAR_SIZE, SHIFT_SPACE_Y + 40 * ii);
		case 14://14—ÎŽlŠpƒLƒƒƒ‰
			StageObject = (IObject*) new class Rectangle(eColor_Green, SHIFT_SPACE_X + CHAR_SIZE * jj + CHAR_SIZE, SHIFT_SPACE_Y + 40 * ii);
		case 15://15ÂŽlŠpƒLƒƒƒ‰
			StageObject = (IObject*) new class Rectangle(eColor_Blue, SHIFT_SPACE_X + CHAR_SIZE * jj + CHAR_SIZE, SHIFT_SPACE_Y + 40 * ii);
		case 16://16ÔŽOŠpƒLƒƒƒ‰
			StageObject = (IObject*) new Triangle(eColor_Red, SHIFT_SPACE_X + CHAR_SIZE * jj + CHAR_SIZE, SHIFT_SPACE_Y + 40 * ii);
		case 17://17—ÎŽOŠpƒLƒƒƒ‰
			StageObject = (IObject*) new Triangle(eColor_Green, SHIFT_SPACE_X + CHAR_SIZE * jj + CHAR_SIZE, SHIFT_SPACE_Y + 40 * ii);
		case 18://18ÂŽOŠpƒLƒƒƒ‰
			StageObject = (IObject*) new Triangle(eColor_Blue, SHIFT_SPACE_X + CHAR_SIZE * jj + CHAR_SIZE, SHIFT_SPACE_Y + 40 * ii);
		case 19://19ÔŽlŠp‚­‚Ú‚Ý
			StageObject = (IObject*) new FitRect(eColor_Red, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
		case 20://20—ÎŽlŠp‚­‚Ú‚Ý
			StageObject = (IObject*) new FitRect(eColor_Green, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
		case 21://21ÂŽlŠp‚­‚Ú‚Ý
			StageObject = (IObject*) new FitRect(eColor_Blue, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
		case 22://22ÔŽOŠp‚­‚Ú‚Ý
			StageObject = (IObject*) new FitTriangle(eColor_Red, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
		case 23://23—ÎŽOŠp‚­‚Ú‚Ý
			StageObject = (IObject*) new FitTriangle(eColor_Green, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
		case 24://24ÂŽOŠp‚­‚Ú‚Ý
			StageObject = (IObject*) new FitTriangle(eColor_Blue, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
		case 25://25ÔŽlŠpƒS[ƒ‹
			StageObject = (IObject*) new GoalRectAngleGimmick(eColor_Red, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
		case 26://26—ÎŽlŠpƒS[ƒ‹
			StageObject = (IObject*) new GoalRectAngleGimmick(eColor_Green, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
		case 27://27ÂŽlŠpƒS[ƒ‹
			StageObject = (IObject*) new GoalRectAngleGimmick(eColor_Blue, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
		case 28://28ÔŽOŠpƒS[ƒ‹
			StageObject = (IObject*) new GoalTriangle(eColor_Red, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
		case 29://29—ÎŽOŠpƒS[ƒ‹
			StageObject = (IObject*) new GoalTriangle(eColor_Green, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
		case 30://30ÂŽOŠpƒS[ƒ‹
			StageObject = (IObject*) new GoalTriangle(eColor_Blue, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
		case 31://31ƒ{[ƒ‹ƒS[ƒ‹


		default:
			objData.iObject[ii][jj] = nullptr;
			break;
		}
	} LOOP_END;

	//¶¬Žž‚ÉƒAƒNƒeƒBƒu‚É‚È‚Á‚Ä‚¢‚éƒIƒuƒWƒFƒNƒg‚ðÝ’è
	gameManager->ChangeCharType(e_charType::eRect_Blue);
}

void SecondStage::mUpdate() {

	//PƒL[‚ð—£‚µ‚½Žž‚ÉƒCƒxƒ“ƒg‚Ìˆ—
	if (CheckHitKey(KEY_INPUT_P) != 0) {
		charChangeFlag = true;
	}
	if (CheckHitKey(KEY_INPUT_P) == 0 && charChangeFlag == true) {
		
		if (gameManager->GetCurrentCharType() == e_charType::eRect_Blue) {

			gameManager->ChangeCharType(e_charType::eTri_Red);
		}
		else {

			gameManager->ChangeCharType(e_charType::eRect_Blue);
		}
		charChangeFlag = false;
	}

	STAGE_DOUBLE_LOOP{
		if (StageObject != nullptr)
		StageObject->mUpdate();
	} LOOP_END;

	if (gameManager->GetRectGoalFlag(eColor_Blue) == true && gameManager->GetTriGoalFlag(eColor_Red) == true)
		gameManager->SetGameClearFlag(true);

}

void SecondStage::mRender() {
	STAGE_DOUBLE_LOOP{
		if (StageObject != nullptr)
		StageObject->mRender();
	} LOOP_END;
}

void SecondStage::mTearDown() {
	STAGE_DOUBLE_LOOP{
		if (StageObject != nullptr) {
			StageObject->mFinal();
			delete StageObject;
		}
	} LOOP_END;
}