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

	SHOP_W_ITEM_BUY,
	SHOP_C_ITEM_BUY,
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
	V_HOSPITAL,

	V_BUY_PAGE,
};

enum SELECT_ITEM
{
	SI_SELECT_NONE,

	S_SELECT_1,
	S_SELECT_2,
	S_SELECT_3,
	S_SELECT_4,
	S_SELECT_5,
	S_SELECT_6,
	S_SELECT_7,
	S_SELECT_8,
	S_SELECT_9,
	S_SELECT_10,
	S_SELECT_11,
	S_SELECT_12
};

typedef struct tagItemWeapon
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
	SELECT_ITEM		_SItem;

	tagItemWeapon _itemWeapon[30];

	D2D1_RECT_F _rc[7];				//�����ܹڽ�
	D2D1_RECT_F _selectRc[7];		//���� ����Ʈ ���� �ڽ�
	D2D1_RECT_F _itemRc[12];		//������ ���� �ڽ� 

	D2D1_RECT_F _shopRc[2];
	D2D1_RECT_F _stopRc;

	bool _isWItemBuy;	// ���� ����
	bool _isWOut;		// ���� ������ 

	bool _isCItemBuy;	// ���� ����
	bool _isCOut;		// ���� ������ 

	bool _isRealBuy;	// ���� ��¥ ����Ȯ��
	bool _isNoBuy;		// ���� ��� �ѷ�����
	
	bool _isItemInfo;	// ������ �����ۼ���
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

