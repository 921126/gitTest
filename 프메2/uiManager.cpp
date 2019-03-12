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
	//00. ����ȭ��
	{
		mainUi* main = new mainUi;
		main->init();
		_uiMap.insert(make_pair(UI_MAIN, main));
	}
	//01. �޴�
	{
		//01-02. ��ȭ
		{
			talk* talkScene = new talk;
			talkScene->init();
			_uiMap.insert(make_pair(UI_TALK, talkScene));
		}
		//01-05. ����
		{
			shopList* shopListScene = new shopList;
			shopListScene->init();
			_uiMap.insert(make_pair(UI_SHOP, shopListScene));
		}
		//01-06. �湮
		{
			visit* visitScene = new visit;
			visitScene->init();
			_uiMap.insert(make_pair(UI_VISIT, visitScene));
		}
	}
	//06. ��ȸ
	{
		//church* churchScene = new church;
		//churchScene->init();
		//_uiMap.insert(make_pair(UI_SHOP, churchScene));

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
	//map<UI_TYPE, baseUi*>::iterator iter = _uiMap.begin();
	//map<UI_TYPE, baseUi*>::iterator end = _uiMap.end();

	_uiMap[_currentUI]->uiClose();
	_currentUI = _beforeUI;
	_beforeUI = UI_NONE;
	selectUI(_currentUI);

}
