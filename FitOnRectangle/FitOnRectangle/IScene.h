#ifndef _ISCENE_H_
#define _ISCENE_H_

#if _DEBUG
#include <crtdbg.h>
#define new ::new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif

class IScene {
public:
	virtual ~IScene() = default;
	virtual void mInit() = 0;
	virtual void mUpdate() = 0;
	virtual void mRender() = 0;
	virtual void mFinal() = 0;
};

#endif // !_ISCENE_H_