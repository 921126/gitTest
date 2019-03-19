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
		_firstName = _princess->getInfo().firstName;
		_lastName = _princess->getInfo().lastName;
		_dietType = _princess->getInfo().dietType;

		_age = _princess->getInfo().age;

	}
	{
		//02. 날짜
		_year = _princess->getDate().year;
		_mon = _princess->getDate().mon;
		_day = _princess->getDate().day;
		_dayday = _princess->getDate().dayday;

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

		_iyear.frameY = _year - 1200;
		_imon.frameY = _mon - 1;
		_iday.frameY = _day - 1;
		_idayday.frameY = _dayday;
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
	IMAGEMANAGER->findImage("year")->frameRender(68, 11, 0, _iyear.frameY);
	IMAGEMANAGER->findImage("mon")->frameRender(10, 40, 0, _imon.frameY);
	IMAGEMANAGER->findImage("day")->frameRender(88, 38, 0, _iday.frameY);
	IMAGEMANAGER->findImage("dayday")->frameRender(12, 70, 0, _idayday.frameY);

	D2DMANAGER->drawText(string2wstring(_lastName).c_str(), 615, 12, 18, RGB(255, 255, 255));
	D2DMANAGER->drawText(string2wstring(_firstName).c_str(), 615, 34, 18, RGB(255, 255, 255));
	D2DMANAGER->drawText(string2wstring(_dietType).c_str(), 615, 165, 18, RGB(255, 255, 255));

	D2DMANAGER->drawText(to_wstring(_age).c_str(), 615, 72, 28, RGB(255, 255, 255));
}
