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
	IMAGEMANAGER->render("���ι��");
	IMAGEMANAGER->render("���δ޷�");
	IMAGEMANAGER->render("����â", 600, 0);
	IMAGEMANAGER->frameRender("12���", 200, 262, 0, 3);

}
