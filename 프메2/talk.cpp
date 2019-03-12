#include "stdafx.h"
#include "talk.h"


talk::talk()
{
}


talk::~talk()
{
}

HRESULT talk::init()
{
	_tState = T_SELECT_NONE;

	FRAMEMANAGER->addFrame("톡선택창", 600, 260, 10, 7);

	//선택박스
	{
		_rc[0] = { 606, 276, 774, 306 };
		_rc[1] = { 606, 308, 774, 338 };
		_rc[2] = { 606, 340, 774, 370 };
	}


	_istalkpapa		= false;
	_ispoketmoney	= false;
	_issermon		= false;

	return S_OK;
}

void talk::release()
{
}

void talk::update()
{

	if (PtInD2D1Rect(_rc[0], _ptMouse))
	{
		_istalkpapa = true;
		_ispoketmoney = false;
		_issermon = false;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{            
			_tState = T_SELECT_TALK_WITHPAPA;
		}
	}
	else if (PtInD2D1Rect(_rc[1], _ptMouse))
	{
		_istalkpapa = false;
		_ispoketmoney = true;
		_issermon = false;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_tState = T_SELECT_POKET_MONEY;
		}
	}
	else if (PtInD2D1Rect(_rc[2], _ptMouse))
	{
		_istalkpapa = false;
		_ispoketmoney = false;
		_issermon = true;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_tState = T_SELECT_SERMON;
		}
	}
	else
	{
		_istalkpapa = false; 
		_ispoketmoney = false;
		_issermon = false;

		_tState = T_SELECT_NONE;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		UIMANAGER->moveBeforeUI();
	}
}

void talk::render()
{
	FRAMEMANAGER->findMenuFrame("톡선택창")->render("선택박스");

	if (_istalkpapa)
	{
		IMAGEMANAGER->findImage("선택중")->render(_rc[0].left, _rc[0].top);
	}
	if (_ispoketmoney)
	{
		IMAGEMANAGER->findImage("선택중")->render(_rc[1].left, _rc[1].top);
	}
	if (_issermon)
	{
		IMAGEMANAGER->findImage("선택중")->render(_rc[2].left, _rc[2].top);
	}
	switch (_tState)
	{
	case T_SELECT_NONE:
		break;
	case T_SELECT_TALK_WITHPAPA:
		break;
	case T_SELECT_POKET_MONEY:

		break;
	case T_SELECT_SERMON:

		break;
	}



	//================== 글씨는 언제나 맨위
	WCHAR talk[1024];
	swprintf_s(talk, L"부녀간의 이야기");
	D2DMANAGER->drawText(talk, 611, 279, 18, RGB(255,255,255));
	swprintf_s(talk, L"용돈");
	D2DMANAGER->drawText(talk, 611, 311, 18, RGB(255, 255, 255));
	swprintf_s(talk, L"설교");
	D2DMANAGER->drawText(talk, 611, 343, 18, RGB(255, 255, 255));
}
