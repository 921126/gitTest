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
	_vShop = V_NONE;

	//리스트 프레임
	{
		FRAMEMANAGER->addFrame("무기점", 420, 300, 10, 3);
		FRAMEMANAGER->addFrame("의상실", 610, 300, 10, 3);
		FRAMEMANAGER->addFrame("요리점", 420, 360, 10, 3);
		FRAMEMANAGER->addFrame("잡화점", 610, 360, 10, 3);
		FRAMEMANAGER->addFrame("교회", 420, 420, 10, 3);
		FRAMEMANAGER->addFrame("병원", 610, 420, 10, 3);

		FRAMEMANAGER->addFrame("리턴", 420, 480, 7, 2);
	}
	//텍스트 상자 프레임
	{
		FRAMEMANAGER->addFrame("텍스트", 20, 420, 20, 6);
		FRAMEMANAGER->addFrame("상점주인", 145, 260, 22, 8);
	}
	//아이템 상자 프레임
	{
		FRAMEMANAGER->addFrame("아이템상자1", 5, 415, 11, 5);
		FRAMEMANAGER->addFrame("아이템상자2", 203, 415, 11, 5);
		FRAMEMANAGER->addFrame("아이템상자3", 401, 415, 11, 5);
		FRAMEMANAGER->addFrame("아이템상자4", 599, 415, 11, 5);

		FRAMEMANAGER->addFrame("아이템상자5", 5, 505, 11, 5);
		FRAMEMANAGER->addFrame("아이템상자6", 203, 505, 11, 5);
		FRAMEMANAGER->addFrame("아이템상자7", 401, 505, 11, 5);
		FRAMEMANAGER->addFrame("아이템상자8", 599, 505, 11, 5);
	}
	FRAMEMANAGER->addFrame("무기점선택", 600, 260, 10, 6);

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

	//상점안에서 선택
	{
		_shopRc[0] = { 605, 280, 775, 310 };
		_shopRc[1] = { 605, 315, 775, 345 };

		_isItemBuy = false;
	}

	itemDateSet();

	return S_OK;
}

void shopList::release()
{
}

void shopList::update()
{
	if (_shopState == SHOP_SELECT_NONE)
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
	if (_shopState == SELECT_WEAPON_SHOP)
	{		
		if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
		{
			_shopState = SHOP_SELECT_NONE;
		}

		//아무것도 선택이 안된 상태에서만!
		if (_vShop == V_NONE)
		{
			if (PtInD2D1Rect(_shopRc[0], _ptMouse))
			{
				_isItemBuy = true;
				_isOut = false;
				if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
				{
					_vShop = V_WEAPON_SHOP;
				}
			}
			else if (PtInD2D1Rect(_shopRc[1], _ptMouse))
			{
				_isItemBuy = false;
				_isOut = true;
				if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
				{
					_vShop = V_NONE;
					_shopState = SHOP_SELECT_NONE;
				}
			}
			else
			{
				_isItemBuy = false;
				_isOut = false;
			}
		}

		if (_vShop == V_WEAPON_SHOP)
		{
			
		}
	}
}

void shopList::render()
{

	WCHAR shopList[256];
	string G = " G";
	IMAGEMANAGER->findImage("거리이미지")->render(20, 110);
	if (_shopState == SHOP_SELECT_NONE)
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
		swprintf_s(shopList, L"딸과 함께 거리로 나왔습니다. \n어디로 가시겠습니까?");
		D2DMANAGER->drawText(shopList, 30, 425, 18, RGB(255, 255, 255));
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

	}
	if (_shopState == SELECT_WEAPON_SHOP)
	{
		IMAGEMANAGER->findImage("거리사람들")->frameRender(5, 260, 0, 0);
		FRAMEMANAGER->findMenuFrame("상점주인")->render("텍스트박스");

		swprintf_s(shopList, L"무기점의 제노\n\n어서옵쇼. \n무기도 방어구도 좋은 것들만 모아뒀다구" );
		D2DMANAGER->drawText(shopList, 160, 280, 18, RGB(255, 255, 255));

		if (_vShop == V_NONE)
		{
			FRAMEMANAGER->findMenuFrame("무기점선택")->render("선택박스");

			if (_isItemBuy)
			{
				IMAGEMANAGER->findImage("선택중")->render(_shopRc[0].left, _shopRc[0].top);
			}
			else if (_isOut)
			{
				IMAGEMANAGER->findImage("선택중")->render(_shopRc[1].left, _shopRc[1].top);
			}

			swprintf_s(shopList, L"물건을 산다");
			D2DMANAGER->drawText(shopList, 610, 285, 18, RGB(255, 255, 255));
			swprintf_s(shopList, L"가게를 나선다");
			D2DMANAGER->drawText(shopList, 610, 320, 18, RGB(255, 255, 255));
		}

		if (_vShop == V_WEAPON_SHOP)
		{
			FRAMEMANAGER->findMenuFrame("아이템상자1")->render("스케쥴박스");
			IMAGEMANAGER->findImage("아이템들")->frameRender(16, 422, 0, 0);
			D2DMANAGER->drawText(string2wstring( _itemWeapon[1].name).c_str(), 60, 422, 18, RGB(255,255,255));
			D2DMANAGER->drawText(to_wstring(_itemWeapon[1].price).c_str(), 60, 440, 18, RGB(255, 255, 255));
			swprintf_s(shopList, L"G");
			D2DMANAGER->drawText(shopList, 80, 440, 18, RGB(255, 255, 255));
			D2DMANAGER->drawText(string2wstring(_itemWeapon[1].info).c_str(), 15, 475, 18, RGB(255, 255, 255));

			FRAMEMANAGER->findMenuFrame("아이템상자2")->render("스케쥴박스");
			IMAGEMANAGER->findImage("아이템들")->frameRender(214, 422, 1, 0);
			D2DMANAGER->drawText(string2wstring(_itemWeapon[2].name).c_str(), 259, 422, 18, RGB(255, 255, 255));
			D2DMANAGER->drawText(to_wstring(_itemWeapon[2].price).c_str(), 259, 440, 18, RGB(255, 255, 255));
			swprintf_s(shopList, L"G");
			D2DMANAGER->drawText(shopList, 279, 440, 18, RGB(255, 255, 255));
			D2DMANAGER->drawText(string2wstring(_itemWeapon[2].info).c_str(), 214, 475, 18, RGB(255, 255, 255));
			FRAMEMANAGER->findMenuFrame("아이템상자3")->render("스케쥴박스");
			FRAMEMANAGER->findMenuFrame("아이템상자4")->render("스케쥴박스");

			FRAMEMANAGER->findMenuFrame("아이템상자5")->render("스케쥴박스");
			FRAMEMANAGER->findMenuFrame("아이템상자6")->render("스케쥴박스");
			FRAMEMANAGER->findMenuFrame("아이템상자7")->render("스케쥴박스");
			FRAMEMANAGER->findMenuFrame("아이템상자8")->render("스케쥴박스");
		}
	}

	swprintf_s(shopList, L"현재선택번호: %d", _shopState);
	D2DMANAGER->drawText(shopList, 400, 10, 18, RGB(255, 255, 255));
}

void shopList::uiClose()
{
	_shopState = SHOP_SELECT_NONE;
	_isItemBuy = false;
	_isOut = false;
}

void shopList::itemDateSet()
{

	//if (_vShop == V_WEAPON_SHOP)
	{
		item itemData;
		for (int ii = WEAPON_01; ii <= WEAPON_07; ++ii)
		{
			itemData.init((ITEM_TYPE)ii);

			_itemWeapon[ii].name = itemData.getItemName((ITEM_TYPE)ii);
			_itemWeapon[ii].price = itemData.getBuyPrice((ITEM_TYPE)ii);
			_itemWeapon[ii].info = itemData.getItemInfo((ITEM_TYPE)ii);
		}
		for (int jj = ARMOR_01; jj <= ARMOR_05; ++jj)
		{
			itemData.init((ITEM_TYPE)jj);

			_itemArmor[jj - ARMOR_01].name = itemData.getItemName((ITEM_TYPE)jj);
			_itemArmor[jj - ARMOR_01].price = itemData.getBuyPrice((ITEM_TYPE)jj);
			_itemArmor[jj - ARMOR_01].info = itemData.getItemInfo((ITEM_TYPE)jj);
		}
	}

}

