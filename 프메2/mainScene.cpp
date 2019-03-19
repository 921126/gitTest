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

	_ismainScene = true;
	UIMANAGER->selectUI(UI_MAIN);
	return S_OK;
}

void mainScene::release()
{
}

void mainScene::update()
{
	_healtyState = UIMANAGER->getHealthState();
}

void mainScene::render()
{
	IMAGEMANAGER->render("메인배경");
	IMAGEMANAGER->render("메인달력");
	IMAGEMANAGER->render("상태창", 600, 0);
	IMAGEMANAGER->frameRender("12살옷", 200, 262, 0, 3);

	healthyStateRender();
}

void mainScene::healthyStateRender()
{
	WCHAR mainScene[256];
	if (_healtyState == 0)
	{
		swprintf_s(mainScene, L"암것도엄슴");
		D2DMANAGER->drawText(mainScene, 615, 164, 18, RGB(255, 255, 255));
	}
	if (_healtyState == 1)
	{
		swprintf_s(mainScene, L"무리하지 않는다");
		D2DMANAGER->drawText(mainScene, 615, 164, 18, RGB(255, 255, 255));
	}
	if (_healtyState == 2)
	{
		swprintf_s(mainScene, L"어쨌든 튼튼하게");
		D2DMANAGER->drawText(mainScene, 615, 164, 18, RGB(255, 255, 255));
	}
	if (_healtyState == 3)
	{
		swprintf_s(mainScene, L"얌전한 아이로");
		D2DMANAGER->drawText(mainScene, 615, 164, 18, RGB(255, 255, 255));
	}
	if (_healtyState == 4)
	{
		swprintf_s(mainScene, L"다이어트 시킨다");
		D2DMANAGER->drawText(mainScene, 615, 164, 18, RGB(255, 255, 255));
	}
}
