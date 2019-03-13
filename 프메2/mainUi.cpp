#include "stdafx.h"
#include "mainUi.h"


mainUi::mainUi()
{
}


mainUi::~mainUi()
{
}

HRESULT mainUi::init()
{
	//메인메뉴 상단 선택박스
	{
		_selectBox[0] = { 602, 220, 648, 256 };
		_selectBox[1] = { 652, 220, 698, 256 };
		_selectBox[2] = { 702, 220, 748, 256 };
		_selectBox[3] = { 752, 220, 798, 256 };
	}
	//메인메뉴 하단 선택박스
	{
		_selectBox[4] = { 602, 260, 648, 296 };
		_selectBox[5] = { 652, 260, 698, 296 };
		_selectBox[6] = { 702, 260, 748, 296 };
		_selectBox[7] = { 752, 260, 798, 296 };

		_selectBox[8] = { 602, 302, 798, 336 };
	}

	_mState = M_SELECT_NONE;
	return S_OK;
}

void mainUi::release()
{
}

void mainUi::update()
{
		//메뉴 버튼 선택하기 
		if (PtInD2D1Rect(_selectBox[0], _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_mState = M_SELECT_PLAYER_STATE;
			}
		}
		if (PtInD2D1Rect(_selectBox[1], _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_mState = M_SELECT_TALK;
				UIMANAGER->selectUI(UI_TALK);
				UIMANAGER->selectBeforUI(UI_MAIN);
			}
		}
		if (PtInD2D1Rect(_selectBox[2], _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_mState = M_SELECT_HEALTH_CARE;
				UIMANAGER->selectUI(UI_HEALTH_CARE);
				UIMANAGER->selectBeforUI(UI_MAIN);
			}
		}
		if (PtInD2D1Rect(_selectBox[3], _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_mState = M_SELECT_INFO;
			}
		}
		if (PtInD2D1Rect(_selectBox[4], _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_mState = M_SELECT_SHOP;
				UIMANAGER->selectUI(UI_SHOP);
				UIMANAGER->selectBeforUI(UI_MAIN);
			}
		}
		if (PtInD2D1Rect(_selectBox[5], _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_mState = M_SELECT_VISIT;
				UIMANAGER->selectUI(UI_VISIT);
				UIMANAGER->selectBeforUI(UI_MAIN);
			}
		}
		if (PtInD2D1Rect(_selectBox[6], _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_mState = M_SELECT_ITEM;
			}
		}
		if (PtInD2D1Rect(_selectBox[7], _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_mState = M_SELECT_SAVE;
			}
		}
		if (PtInD2D1Rect(_selectBox[8], _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_mState = M_SELECT_SCHEDULE;
			}
		}
}

void mainUi::render()
{
	IMAGEMANAGER->render("선택창", 600, 218);
}
