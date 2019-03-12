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

	FRAMEMANAGER->addFrame("방문하기", 600, 240, 6, 12);
	FRAMEMANAGER->addFrame("성방문01", 175, 370, 25, 8);
	FRAMEMANAGER->addFrame("성방문02", 200, 370, 20, 8);

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
	IMAGEMANAGER->findImage("성이미지")->render(35, 120);
	if (!_isVisit)
	{
		FRAMEMANAGER->findMenuFrame("성방문01")->render("텍스트박스");

		swprintf_s(visit, L"성에 왔습니다.");
		D2DMANAGER->drawText(visit, 185, 380, 18, RGB(255, 255, 255));
	}
	else
	{
		FRAMEMANAGER->findMenuFrame("방문하기")->render("선택박스");
		FRAMEMANAGER->findMenuFrame("성방문02")->render("텍스트박스");
		IMAGEMANAGER->findImage("문지기")->render( 60, 370);
		swprintf_s(visit, L"왔구나. \n이번엔 누구를 만나려는 거냐?");
		D2DMANAGER->drawText(visit, 210, 380, 18, RGB(255, 255, 255));
	}
}

void visit::uiClose()
{
	_isVisit = false;
}
