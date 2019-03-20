#include "stdafx.h"
#include "mainScene.h"


mainScene::mainScene()
{
}


mainScene::~mainScene()
{
}

HRESULT mainScene::init()
{
	//_princess = SCENEMANAGER->getPrincessAddress();
	//_princess->setAge(_princess->getInfo().age);

	_princess = new princess;
	_princess->init();

	//=========================================== 정보 초기화
	{
		//01. 개인정보
		

	}
	{
		//02. 날짜

		if (_mon == 1 || _mon == 3 || _mon == 5 || _mon == 7 || _mon == 8 || _mon == 10 || _mon == 12)
		{
			_lastDay = 31;
		}
		else if (_mon == 2)
		{
			_lastDay = 28;
		}
		else
		{
			_lastDay = 30;
		}

		//_iyear.frameY = _year - 1200;
		//_imon.frameY = _mon - 1;
		//_iday.frameY = _day - 1;
		//_idayday.frameY = _dayday;
	}

	UIMANAGER->selectUI(UI_MAIN);

	return S_OK;
}

void mainScene::release()
{
}

void mainScene::update()
{
}

void mainScene::render()
{
	WCHAR str[1024];

	IMAGEMANAGER->findImage("메인배경")->render(1);
	IMAGEMANAGER->findImage("메인달력")->render(1);
	IMAGEMANAGER->findImage("메인스텟")->render(600, 0);
	IMAGEMANAGER->findImage("메인메뉴")->render(600, 218);
	//IMAGEMANAGER->findImage("year")->frameRender(68, 11, 0, _iyear.frameY);
	//IMAGEMANAGER->findImage("mon")->frameRender(10, 40, 0, _imon.frameY);
	//IMAGEMANAGER->findImage("day")->frameRender(88, 38, 0, _iday.frameY);
	//IMAGEMANAGER->findImage("dayday")->frameRender(12, 70, 0, _idayday.frameY);

	if (_age == 10)
	{
		IMAGEMANAGER->findImage("10age_clothes")->frameRender(200, 304, 0, 0);
		IMAGEMANAGER->findImage("10age_face")->frameRender(294, 173, 0, 0);
	}
	D2DMANAGER->drawText(string2wstring(_princess->getPrincessInfo().lastName).c_str(), 615, 12, 18, RGB(255, 255, 255));
	D2DMANAGER->drawText(string2wstring(_princess->getPrincessInfo().firstName).c_str(), 615, 34, 18, RGB(255, 255, 255));
	D2DMANAGER->drawText(string2wstring(_dietType).c_str(), 615, 165, 18, RGB(255, 255, 255));

	D2DMANAGER->drawText(to_wstring(_princess->getPrincessInfo().age).c_str(), 615, 72, 28, RGB(255, 255, 255));
}
