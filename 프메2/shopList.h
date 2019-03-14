#pragma once
#include "baseUi.h"
#include "item.h"

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
enum VISIT_SHOP
{
	V_NONE,
	V_WEAPON_SHOP ,
	V_CLOTHES_SHOP,
	V_RESTAURANT,
	V_GENERAL_SHOP,
	V_CHURCH,
	V_HOSPITAL
};

typedef struct tagItemWeapon
{
	string name;
	string info;
	int price;
	float value1;
	float value2;
};
typedef struct tagItemArmor
{
	string name;
	string info;
	int price;
	float value1;
	float value2;
};
class shopList : public baseUi
{
private:
	SHOPLIST_STATE _shopState;
	VISIT_SHOP	   _vShop;

	tagItemWeapon _itemWeapon[7];
	tagItemArmor _itemArmor[5];

	D2D1_RECT_F _rc[7];
	D2D1_RECT_F _selectRc[7];

	D2D1_RECT_F _shopRc[2];

	bool _isItemBuy;	// 물건 구매
	bool _isOut;		// 가게 나서기 

public:
	shopList();
	~shopList();

	HRESULT init();
	void release();
	void update();
	void render();

	void uiClose();
	void itemDateSet();
};

