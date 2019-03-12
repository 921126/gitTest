#include "stdafx.h"
#include "shopList.h"


shopList::shopList()
{
}


shopList::~shopList()
{
}

HRESULT shopList::init()
{
	_shopState = SHOP_SELECT_NONE;

	FRAMEMANAGER->addFrame("무기점", 420, 300, 10, 3);
	FRAMEMANAGER->addFrame("의상실", 610, 300, 10, 3);
	FRAMEMANAGER->addFrame("요리점", 420, 360, 10, 3);
	FRAMEMANAGER->addFrame("잡화점", 610, 360, 10, 3);   
	FRAMEMANAGER->addFrame("교회", 420, 420, 10, 3);
	FRAMEMANAGER->addFrame("병원", 610, 420, 10, 3);

	FRAMEMANAGER->addFrame("리턴", 420, 480, 7, 2);

	FRAMEMANAGER->addFrame("텍스트", 20, 420, 20, 6);

	//아이콘박스
	{
		_rc[0] = { 432, 307, 472, 347 };
		_rc[1] = { 622, 307, 662, 347 };
		_rc[2] = { 432, 367, 472, 407 };
		_rc[3] = { 622, 367, 662, 407 };
		_rc[4] = { 432, 427, 472, 467 };
		_rc[5] = { 622, 427, 662, 467 };
	}

	//선택박스
	{
		_selectRc[0] = { 420, 300, 600, 354 };
		_selectRc[1] = { 610, 300, 790, 354 };
		_selectRc[2] = { 420, 360, 600, 414 };
		_selectRc[3] = { 610, 360, 790, 414 };
		_selectRc[4] = { 420, 420, 600, 474 };
		_selectRc[5] = { 610, 420, 790, 474 };
		_selectRc[6] = { 420, 480, 546, 516 };
	}
	return S_OK;
}

void shopList::release()
{
}

void shopList::update()
{

		if (PtInD2D1Rect(_selectRc[0], _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_shopState = SELECT_WEAPON_SHOP;
			}
		}
		else if (PtInD2D1Rect(_selectRc[1], _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_shopState = SELECT_CLOTHES_SHOP;
			}
		}
		else if (PtInD2D1Rect(_selectRc[2], _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_shopState = SELECT_RESTAURANT_SHOP;
			}
		}
		else if (PtInD2D1Rect(_selectRc[3], _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_shopState = SELECT_GENERAL_SHOP;
			}
		}
		else if (PtInD2D1Rect(_selectRc[4], _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_shopState = SELECT_CHURCH;
			}
		}
		else if (PtInD2D1Rect(_selectRc[5], _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_shopState = SELECT_HOSPITAL;
			}
		}
		else if (PtInD2D1Rect(_selectRc[6], _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_shopState = SHOP_SELECT_RETURN;
				UIMANAGER->moveBeforeUI();
			}
		}
		else
		{
			if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
			{
				UIMANAGER->moveBeforeUI();
			}
		}
}

void shopList::render()
{
	FRAMEMANAGER->findMenuFrame("무기점")->render("스케쥴박스");
	IMAGEMANAGER->findImage("상점목록")->frameRender(_rc[0].left, _rc[0].top, 0, 0);
	FRAMEMANAGER->findMenuFrame("의상실")->render("스케쥴박스");
	IMAGEMANAGER->findImage("상점목록")->frameRender(_rc[1].left, _rc[1].top, 1, 0);
	FRAMEMANAGER->findMenuFrame("요리점")->render("스케쥴박스");
	IMAGEMANAGER->findImage("상점목록")->frameRender(_rc[2].left, _rc[2].top, 2, 0);
	FRAMEMANAGER->findMenuFrame("잡화점")->render("스케쥴박스");
	IMAGEMANAGER->findImage("상점목록")->frameRender(_rc[3].left, _rc[3].top, 3, 0);
	FRAMEMANAGER->findMenuFrame("교회")->render("스케쥴박스");
	IMAGEMANAGER->findImage("상점목록")->frameRender(_rc[4].left, _rc[4].top, 4, 0);
	FRAMEMANAGER->findMenuFrame("병원")->render("스케쥴박스");
	IMAGEMANAGER->findImage("상점목록")->frameRender(_rc[5].left, _rc[5].top, 5, 0);

	FRAMEMANAGER->findMenuFrame("리턴")->render("스케쥴박스");

	FRAMEMANAGER->findMenuFrame("텍스트")->render("텍스트박스");

	//텍스트 출력은 맨위

	WCHAR shopList[256];
	swprintf_s(shopList, L"딸과 함께 거리로 나왔습니다. \n어디로 가시겠습니까?");
	D2DMANAGER->drawText(shopList, 30, 425, 18, RGB(255,255,255));
	swprintf_s(shopList, L"무기점");
	D2DMANAGER->drawText(shopList, 475, 314, 24, RGB(255, 255, 255));
	swprintf_s(shopList, L"의상실");
	D2DMANAGER->drawText(shopList, 670, 314, 24, RGB(255, 255, 255));
	swprintf_s(shopList, L"요리점");
	D2DMANAGER->drawText(shopList, 475, 374, 24, RGB(255, 255, 255));
	swprintf_s(shopList, L"잡화점");
	D2DMANAGER->drawText(shopList, 670, 374, 24, RGB(255, 255, 255));
	swprintf_s(shopList, L"교회");
	D2DMANAGER->drawText(shopList, 475, 434, 24, RGB(255, 255, 255));
	swprintf_s(shopList, L"병원");
	D2DMANAGER->drawText(shopList, 670, 434, 24, RGB(255, 255, 255));

	swprintf_s(shopList, L"돌아가기");
	D2DMANAGER->drawText(shopList, 445, 488, 18, RGB(255, 255, 255));


	swprintf_s(shopList, L"현재선택번호: %d", _shopState);
	D2DMANAGER->drawText(shopList, 400, 10, 18, RGB(255, 255, 255));
}

