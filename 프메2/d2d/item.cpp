#include "stdafx.h"
#include "item.h"


item::item()
{
}


item::~item()
{
}

HRESULT item::init()
{
	return S_OK;
}

void item::release()
{
}

void item::update()
{
}

void item::render()
{
	IMAGEMANAGER->frameRender("items", _x, _y, _frameX, _frameY);
}

void item::setItem(string name, int price, bool isStore, vector<pair<string, float>> mItem, int type, int frameX, int frameY)
{
	_name = name;
	_price = price;
	_isStore = isStore;
	_mItem = mItem;
	_type = (ITEM_TYPE)type;
	_frameX = frameX;
	_frameY = frameY;

}

void item::setImage()
{
	switch (_type)
	{
	case ITEM_WEAPON:
	case ITEM_ARMOR:
	case ITEM_CLOTHES:

		_img = IMAGEMANAGER->findImage("items");

	break;
	}
}

void item::setXY(float x, float y)
{
	_x = x;
	_y = y;
}
