#include "stdafx.h"
#include "mainUI.h"


mainUI::mainUI()
{
}


mainUI::~mainUI()
{
}

HRESULT mainUI::init()
{
	//메인메뉴 상단 선택박스
	{
		_mSelectBox[0] = { 600, 218, 650, 258 };
		_mSelectBox[1] = { 650, 218, 700, 258 };
		_mSelectBox[2] = { 700, 218, 750, 258 };
		_mSelectBox[3] = { 750, 218, 800, 258 };
	}
	//메인메뉴 하단 선택박스
	{
		_mSelectBox[4] = { 600, 258, 650, 298 };
		_mSelectBox[5] = { 650, 258, 700, 298 };
		_mSelectBox[6] = { 700, 258, 750, 298 };
		_mSelectBox[7] = { 750, 258, 800, 298 };

		_mSelectBox[8] = { 600, 298, 800, 338 };
	}

	_mState = M_STATE_NONE;
	_mSelect = M_SELECT_NONE;

	return S_OK;
}

void mainUI::release()
{
}

void mainUI::update()
{
	//메뉴 버튼 선택하기 
	if (PtInD2D1Rect(_mSelectBox[0], _ptMouse))
	{
		_mState = M_STATE_PLAYER_STATE;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_mSelect = M_SELECT_PLAYER_STATE;
			
			//to do: 이동할 UI
			UIMANAGER->selectBeforUI(UI_MAIN);
		}
	}
	else if (PtInD2D1Rect(_mSelectBox[2], _ptMouse))
	{
		_mState = M_STATE_DIET_STATE;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_mSelect = M_SELECT_DIET_STATE;
			UIMANAGER->selectBeforUI(UI_MAIN);
		}
	}
	else if (PtInD2D1Rect(_mSelectBox[3], _ptMouse))
	{
		_mState = M_STATE_INFO;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_mSelect = M_SELECT_INFO;
			UIMANAGER->selectBeforUI(UI_MAIN);
		}
	}
	else if (PtInD2D1Rect(_mSelectBox[4], _ptMouse))
	{
		_mState = M_STATE_SHOP;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_mSelect = M_SELECT_SHOP;
			UIMANAGER->selectBeforUI(UI_MAIN);
		}
	}
	else if (PtInD2D1Rect(_mSelectBox[6], _ptMouse))
	{
		_mState = M_STATE_ITEM;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_mSelect = M_SELECT_ITEM;
			UIMANAGER->selectBeforUI(UI_MAIN);
		}
	}
	else if (PtInD2D1Rect(_mSelectBox[7], _ptMouse))
	{
		_mState = M_STATE_SAVE;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_mSelect = M_SELECT_SAVE;
			UIMANAGER->selectBeforUI(UI_MAIN);
		}
	}
	else if (PtInD2D1Rect(_mSelectBox[8], _ptMouse))
	{
		_mState = M_STATE_SCHEDULE;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_mSelect = M_SELECT_SCHEDULE;
			UIMANAGER->selectBeforUI(UI_MAIN);
		}
	}
	else
	{
		_mState = M_STATE_NONE;
		_mSelect = M_SELECT_NONE;
	}
}

void mainUI::render()
{
	switch (_mState)
	{
	case M_STATE_PLAYER_STATE:
		IMAGEMANAGER->findImage("메인메뉴선택")->render(_mSelectBox[0].left, _mSelectBox[0].top);
		break;
	case M_STATE_DIET_STATE:
		IMAGEMANAGER->findImage("메인메뉴선택")->render(_mSelectBox[2].left, _mSelectBox[2].top);
		break;
	case M_STATE_INFO:
		IMAGEMANAGER->findImage("메인메뉴선택")->render(_mSelectBox[3].left, _mSelectBox[3].top);
		break;
	case M_STATE_SHOP:
		IMAGEMANAGER->findImage("메인메뉴선택")->render(_mSelectBox[4].left, _mSelectBox[4].top);
		break;
	case M_STATE_ITEM:
		IMAGEMANAGER->findImage("메인메뉴선택")->render(_mSelectBox[6].left, _mSelectBox[6].top);
		break;
	case M_STATE_SAVE:
		IMAGEMANAGER->findImage("메인메뉴선택")->render(_mSelectBox[7].left, _mSelectBox[7].top);
		break;
	case M_STATE_SCHEDULE:
		IMAGEMANAGER->findImage("스케쥴메뉴선택")->render(_mSelectBox[8].left, _mSelectBox[8].top);
		break;
	}
}
