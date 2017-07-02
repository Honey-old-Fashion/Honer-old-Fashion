#include "GimmickTask.h"
#include <Windows.h>

#define GIMMICKSIZE 15

class GateGimmick : public GimmickTask {
private:
	
public:
	GateGimmick(eColor, int, int);
	~GateGimmick();
	virtual void mInit() {}
	virtual void mUpdate() {};
	virtual void mRender();
	virtual void mFinal() {}


};

