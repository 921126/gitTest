#pragma once
#include "singletonBase.h"
#include "frame.h"
#include <map>

class frameManager : public singletonBase<frameManager>
{
public :
	typedef map<string, frame*>				mapFrameList;
	typedef map<string, frame*>::iterator	mapFrameIter;

private:
	mapFrameList _mFrameList;

public:
	frameManager();
	~frameManager();

	HRESULT init();
	void release();

	frame* addFrame(string key, UINT destX, UINT destY, UINT frameWidth, UINT frameHeight);
	frame* findMenuFrame(string key);
	void render(string key, string imgName);
};

