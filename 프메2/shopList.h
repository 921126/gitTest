#pragma once
#include "baseUi.h"

enum SHOPLIST_STATE
{
	SHOP_SELECT_NONE,
	SELECT_WEAPON_SHOP,
	SELECT_CLOTHES_SHOP,
	SELECT_RESTAURANT_SHOP,
	SELECT_GENERAL_SHOP,
	SELECT_CHURCH,
	SELECT_HOSPITAL,
	SHOP_SELECT_RETURN
};
class shopList : public baseUi
{
private:
	SHOPLIST_STATE _shopState;

	D2D1_RECT_F _rc[7];
	D2D1_RECT_F _selectRc[7];
public:
	shopList();
	~shopList();

	HRESULT init();
	void release();
	void update();
	void render();
};

