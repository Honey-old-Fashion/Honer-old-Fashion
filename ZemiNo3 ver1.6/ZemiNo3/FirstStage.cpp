#include "FirstStage.h"
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

FirstStage::FirstStage() {
	STAGE_DOUBLE_LOOP {
		objData.iObject[ii][jj] = nullptr;
	}LOOP_END;
}

FirstStage::~FirstStage() {

}


void FirstStage::mSetUp() {
	STAGE_DOUBLE_LOOP{
		switch (m_stage[ii][jj]) {
			case 0://0 無
				StageObject = nullptr;
			case 1://1 壁
				StageObject = (IObject*) new WallObject(SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
			case 2://2 床
				StageObject = (IObject*) new WallObject(SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
			case 3://3 赤ゲート
				StageObject = (IObject*) new GateGimmick(eColor_Red, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
			case 4://4 緑ゲート
				StageObject = (IObject*) new GateGimmick(eColor_Green, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
			case 5://5 青ゲート
				StageObject = (IObject*) new GateGimmick(eColor_Blue, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
			case 6://6 赤盛り上がる床
				StageObject = (IObject*) new UpGimmick(eColor_Red, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
			case 7://7 緑盛り上がる床
				StageObject = (IObject*) new UpGimmick(eColor_Green, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
			case 8://8 青盛り上がる床
				StageObject = (IObject*) new UpGimmick(eColor_Blue, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
			case 9://9 赤落とし穴
				StageObject = (IObject*) new DropGimmick(SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
			case 10://10緑落とし穴
				StageObject = (IObject*) new DropGimmick(SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
			case 11://11青落とし穴
				StageObject = (IObject*) new DropGimmick(SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
			case 12://12ボール
				StageObject = (IObject*) new BallGimmick(SHIFT_SPACE_X + ((CHAR_SIZE * jj) + (CHAR_SIZE / 2)), SHIFT_SPACE_Y + (40 * ii + (CHAR_SIZE / 2)));
			case 13://13赤四角キャラ
				StageObject = (IObject*) new class Rectangle(eColor_Red, SHIFT_SPACE_X + CHAR_SIZE * jj + CHAR_SIZE, SHIFT_SPACE_Y + 40 * ii);
			case 14://14緑四角キャラ
				StageObject = (IObject*) new class Rectangle(eColor_Green, SHIFT_SPACE_X + CHAR_SIZE * jj + CHAR_SIZE, SHIFT_SPACE_Y + 40 * ii);
			case 15://15青四角キャラ
				StageObject = (IObject*) new class Rectangle(eColor_Blue, SHIFT_SPACE_X + CHAR_SIZE * jj + CHAR_SIZE, SHIFT_SPACE_Y + 40 * ii);
			case 16://16赤三角キャラ
				StageObject = (IObject*) new Triangle(eColor_Red, SHIFT_SPACE_X + CHAR_SIZE * jj + CHAR_SIZE, SHIFT_SPACE_Y + 40 * ii);
			case 17://17緑三角キャラ
				StageObject = (IObject*) new Triangle(eColor_Green, SHIFT_SPACE_X + CHAR_SIZE * jj + CHAR_SIZE, SHIFT_SPACE_Y + 40 * ii);
			case 18://18青三角キャラ
				StageObject = (IObject*) new Triangle(eColor_Blue, SHIFT_SPACE_X + CHAR_SIZE * jj + CHAR_SIZE, SHIFT_SPACE_Y + 40 * ii);
			case 19://19赤四角くぼみ
				StageObject = (IObject*) new FitRect(eColor_Red, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
			case 20://20緑四角くぼみ
				StageObject = (IObject*) new FitRect(eColor_Green, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
			case 21://21青四角くぼみ
				StageObject = (IObject*) new FitRect(eColor_Blue, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
			case 22://22赤三角くぼみ
				StageObject = (IObject*) new FitTriangle(eColor_Red, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
			case 23://23緑三角くぼみ
				StageObject = (IObject*) new FitTriangle(eColor_Green, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
			case 24://24青三角くぼみ
				StageObject = (IObject*) new FitTriangle(eColor_Blue, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
			case 25://25赤四角ゴール
				StageObject = (IObject*) new GoalRectAngleGimmick(eColor_Red, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
			case 26://26緑四角ゴール
				StageObject = (IObject*) new GoalRectAngleGimmick(eColor_Green, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
			case 27://27青四角ゴール
				StageObject = (IObject*) new GoalRectAngleGimmick(eColor_Blue, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
			case 28://28赤三角ゴール
				StageObject = (IObject*) new GoalTriangle(eColor_Red, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
			case 29://29緑三角ゴール
				StageObject = (IObject*) new GoalTriangle(eColor_Green, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
			case 30://30青三角ゴール
				StageObject = (IObject*) new GoalTriangle(eColor_Blue, SHIFT_SPACE_X + CHAR_SIZE * jj, SHIFT_SPACE_Y + 40 * ii);
			case 31://31ボールゴール


			default:
				objData.iObject[ii][jj] = nullptr;
				break;
			}
	objData.gimmicType[ii][jj] = m_stage[ii][jj];

	} LOOP_END;

	//生成時にアクティブになっているオブジェクトを設定
	gameManager->ChangeCharType(e_charType::eRect_Blue);
}

void FirstStage::mUpdate() {

	//Pキーを離した時にイベントの処理
	if (CheckHitKey(KEY_INPUT_P) != 0) {
		charChangeFlag = true;
	}
	if (CheckHitKey(KEY_INPUT_P) == 0 && charChangeFlag == true) {
		//書かなくてもわかるよね？
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

	if (gameManager->GetRectGoalFlag(eColor_Blue) == true && gameManager->GetTriGoalFlag(eColor_Red)== true)
		gameManager->SetGameClearFlag(true);
}

void FirstStage::mRender() {
	STAGE_DOUBLE_LOOP{
		if (StageObject != nullptr)
			StageObject->mRender();
	} LOOP_END;
}

void FirstStage::mTearDown() {
	STAGE_DOUBLE_LOOP {
		if (StageObject != nullptr) {
			StageObject->mFinal();
			delete StageObject;
		}		
	} LOOP_END;
}
