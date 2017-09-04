#pragma once
#include "IObject.h"
#include <DxLib.h>
#include <Windows.h>
#include "Singleton.h"
#include "CollisionDetection.h"

#define OBJECTSIZE 40
#define LINEMAX 10


class GimmickTask :public IObject {
protected:
	bool activeFlag;
	POINT pRect[COLOR_NUM];
	POINT pTri[COLOR_NUM];
	POINT pGimmick;
	unsigned int m_color;
	bool m_gimmickOpenFlag;
	eColor m_colorID;
	CollisionDetection& collision = singleton<CollisionDetection>::GetInstance();

public:
	GimmickTask();
	~GimmickTask();

	
	virtual POINT GetPoint() override;


	inline int mGetGimmickColorId() {
		return m_colorID;
	}

	inline void mSetActiveFlag(bool _activeFlag) {
		activeFlag = _activeFlag;
	}

	inline bool mGetActiveFlag() {
		return activeFlag;
	}

	virtual void mInit() override {}
	virtual void mUpdate() override {}
	virtual void mRender()override {}
	virtual void mFinal() override {}
};                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                