#ifndef _ISTAGE_H_
#define _ISTAGE_H_

#if _DEBUG
#include <crtdbg.h>
#define new ::new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif

#define STAGE_DOUBLE_LOOP for (int ii = 0; ii < LengthHeight; ii++){ \
							for (int jj = 0; jj < lengthWidth; jj++)
#define LOOP_END }				 

class IStage {
public:
	IStage(){}
	virtual ~IStage() = default;
	
	virtual void mSetUp() = 0;
	virtual void mUpdate() = 0;
	virtual void mRender() = 0;
	virtual void mTearDown() = 0;
};

#endif // !_ISTAGE_H_