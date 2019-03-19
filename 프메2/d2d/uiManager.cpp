#include "stdafx.h"
#include "uiManager.h"


uiManager::uiManager()
{
}


uiManager::~uiManager()
{
}

HRESULT uiManager::init()
{
	//00. ¸ÞÀÎ
	{
		mainUI* mainScene = new mainUI;
		mainScene->init();
		_uiMap.insert(make_pair(UI_MAIN, mainScene));
	}
	return S_OK;
}

void uiManager::release()
{
}

void uiManager::update()
{
	if (_currentUI == UI_NONE) return;
	_uiMap[_currentUI]->update();
}

void uiManager::render()
{
	if (_currentUI == UI_NONE) return;
	_uiMap[_currentUI]->render();
}

void uiManager::moveBeforeUI()
{
	_uiMap[_currentUI]->uiClose();
	_currentUI = _beforeUI;
	_beforeUI = UI_NONE;
	selectUI(_currentUI);
}
