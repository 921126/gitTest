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

}

void mainScene::render()
{
	IMAGEMANAGER->render("메인배경");
	IMAGEMANAGER->render("메인달력");
	IMAGEMANAGER->render("상태창", 600, 0);
	IMAGEMANAGER->frameRender("12살옷", 200, 262, 0, 3);

}
