#ifndef _ISCENE_H_
#define _ISCENE_H_

class IScene {
public:
	virtual ~IScene() = default;
	virtual void mInit() = 0;
	virtual void mUpdate() = 0;
	virtual void mRender() = 0;
	virtual void mFinal() = 0;
};

#endif // !_ISCENE_H_