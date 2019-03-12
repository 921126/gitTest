#include "stdafx.h"
#include "visit.h"


visit::visit()
{
}

visit::~visit()
{
}

HRESULT visit::init()
{
	_vState = V_SELECT_NONE;

	FRAMEMANAGER->addFrame("�湮�ϱ�", 600, 240, 6, 12);
	FRAMEMANAGER->addFrame("���湮01", 175, 370, 25, 8);
	FRAMEMANAGER->addFrame("���湮02", 200, 370, 20, 8);

	_isVisit = false;
	return S_OK;
}

void visit::release()
{
}

void visit::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		UIMANAGER->moveBeforeUI();
	}
	if (_vState == V_SELECT_NONE)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_isVisit = true;
		}
	}
}

void visit::render()
{
	WCHAR visit[256];
	IMAGEMANAGER->findImage("���̹���")->render(35, 120);
	if (!_isVisit)
	{
		FRAMEMANAGER->findMenuFrame("���湮01")->render("�ؽ�Ʈ�ڽ�");

		swprintf_s(visit, L"���� �Խ��ϴ�.");
		D2DMANAGER->drawText(visit, 185, 380, 18, RGB(255, 255, 255));
	}
	else
	{
		FRAMEMANAGER->findMenuFrame("�湮�ϱ�")->render("���ùڽ�");
		FRAMEMANAGER->findMenuFrame("���湮02")->render("�ؽ�Ʈ�ڽ�");
		IMAGEMANAGER->findImage("������")->render( 60, 370);
		swprintf_s(visit, L"�Ա���. \n�̹��� ������ �������� �ų�?");
		D2DMANAGER->drawText(visit, 210, 380, 18, RGB(255, 255, 255));
	}
}

void visit::uiClose()
{
	_isVisit = false;
}
