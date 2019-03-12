#include "stdafx.h"
#include "frameManager.h"


frameManager::frameManager()
{
}


frameManager::~frameManager()
{
}

HRESULT frameManager::init()
{
	return S_OK;
}

void frameManager::release()
{
	mapFrameIter miFrameList = _mFrameList.begin();

	for (; miFrameList != _mFrameList.end();)
	{
		if (miFrameList->second != nullptr)
		{
			miFrameList->second->release();
			SAFE_DELETE(miFrameList->second);
			miFrameList++;
		}
	}
	_mFrameList.clear();
}

frame * frameManager::addFrame(string key, UINT destX, UINT destY, UINT frameWidth, UINT frameHeight)
{
	frame* newFrame = findMenuFrame(key);

	if (newFrame) return newFrame;

	newFrame = new frame;
	if (FAILED(newFrame->init(destX, destY, frameWidth, frameHeight)))
	{
		SAFE_DELETE(newFrame);
		return nullptr;
	}

	_mFrameList.insert(make_pair(key, newFrame));

	return newFrame;
}

frame * frameManager::findMenuFrame(string key)
{
	mapFrameIter find = _mFrameList.find(key);

	//변경할 씬을 못찾았다면
	if (find == _mFrameList.end())
	{
		return nullptr;
	}

	return find->second;
}

void frameManager::render(string key, string imgName)
{
	mapFrameIter find = _mFrameList.find(key);

	if (find == _mFrameList.end()) return;
	
	find->second->render(imgName);
}
