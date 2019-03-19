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
	IMAGEMANAGER->render("���ι��");
	IMAGEMANAGER->render("���δ޷�");
	IMAGEMANAGER->render("����â", 600, 0);
	IMAGEMANAGER->frameRender("12���", 200, 262, 0, 3);

	healthyStateRender();
}

void mainScene::healthyStateRender()
{
	WCHAR mainScene[256];
	if (_healtyState == 0)
	{
		swprintf_s(mainScene, L"�ϰ͵�����");
		D2DMANAGER->drawText(mainScene, 615, 164, 18, RGB(255, 255, 255));
	}
	if (_healtyState == 1)
	{
		swprintf_s(mainScene, L"�������� �ʴ´�");
		D2DMANAGER->drawText(mainScene, 615, 164, 18, RGB(255, 255, 255));
	}
	if (_healtyState == 2)
	{
		swprintf_s(mainScene, L"��·�� ưư�ϰ�");
		D2DMANAGER->drawText(mainScene, 615, 164, 18, RGB(255, 255, 255));
	}
	if (_healtyState == 3)
	{
		swprintf_s(mainScene, L"������ ���̷�");
		D2DMANAGER->drawText(mainScene, 615, 164, 18, RGB(255, 255, 255));
	}
	if (_healtyState == 4)
	{
		swprintf_s(mainScene, L"���̾�Ʈ ��Ų��");
		D2DMANAGER->drawText(mainScene, 615, 164, 18, RGB(255, 255, 255));
	}
}
