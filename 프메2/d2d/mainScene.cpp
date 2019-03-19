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

	_firstName = _princess->getDate().fristName;
	_year = _princess->getDate().year;
	_mon = _princess->getDate().mon;
	_day = _princess->getDate().day;
	_dayday = _princess->getDate().dayday;

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
	IMAGEMANAGER->findImage("메인배경")->render(1);
	IMAGEMANAGER->findImage("메인달력")->render(1);
	IMAGEMANAGER->findImage("메인스텟")->render(600, 0);

	WCHAR str[128];
	swprintf_s(str, L"%d", _year);
	D2DMANAGER->drawText(str, 65, 7, 22, RGB(255,255,255));
}
