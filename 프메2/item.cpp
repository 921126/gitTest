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

HRESULT item::init(ITEM_TYPE type)
{
	_img = IMAGEMANAGER->findImage("아이템들");
	_itemType = type;

	switch (type)
	{
	case WEAPON_NONE:
		break;
	case WEAPON_01:
		_itemName	= "곤봉";
		_itemInfo	= "공격 +3";
		_itemValue1 = 3;
		_buyPrice	= BUY_PRICE_WEAPON_01;
		break;
	case WEAPON_02:
		_itemName	= "구리검";
		_itemInfo	= "공격 +6";
		_itemValue1 = 6;
		_buyPrice	= BUY_PRICE_WEAPON_02;
		break;
	case WEAPON_03:
		_itemName	= "철제 단검";
		_itemInfo	= "공격 +9";
		_itemValue1 = 9;
		_buyPrice	= BUY_PRICE_WEAPON_03;
		break;
	case WEAPON_04:
		_itemName	= "철제 장검";
		_itemInfo	= "공격 +12 / 전투 -2";
		_itemValue1 = 12;
		_itemValue2 = 2;
		_buyPrice	= BUY_PRICE_WEAPON_04;
		break;
	case WEAPON_05:
		_itemName	= "양손 철검";
		_itemInfo	= "공격 +18 / 방어 -4";
		_itemValue1 = 18;
		_itemValue2 = 4;
		_buyPrice	= BUY_PRICE_WEAPON_05;
		break;
	case WEAPON_06:
		_itemName	= "미스릴검";
		_itemInfo	= "공격 +20";
		_itemValue1 = 20;
		_buyPrice	= BUY_PRICE_WEAPON_06;
		break;
	case WEAPON_07:
		_itemName	= "동방 외날검";
		_itemInfo	= "공격 +20 / 전투 +10";
		_itemValue1 = 20;
		_itemValue2 = 10;
		_buyPrice	= BUY_PRICE_WEAPON_07;
		break;
	case ARMOR_NONE:
		break;
	case ARMOR_01:
		_itemName	= "실크 갑옷";
		_itemInfo	= "방어 +2 / 색기 +50";
		_itemValue1 = 2;
		_itemValue2 = 50;
		_buyPrice	= BUY_PRICE_ARMOR_01;
		break;
	case ARMOR_02:
		_itemName	= "미스릴 갑옷";
		_itemInfo	= "방어 +22 / 항마 +15";
		_itemValue1 = 22;
		_itemValue2 = 15;
		_buyPrice	= BUY_PRICE_ARMOR_02;
		break;
	case ARMOR_03:
		_itemName	= "철 갑옷";
		_itemInfo	= "방어 +18 / 전투 -15";
		_itemValue1 = 18;
		_itemValue2 = 15;
		_buyPrice	= BUY_PRICE_ARMOR_03;
		break;
	case ARMOR_04:
		_itemName	= "쇠사슬 갑옷";
		_itemInfo	= "방어 +14 / 전투 -3";
		_itemValue1 = 14;
		_itemValue2 = 3;
		_buyPrice	= BUY_PRICE_ARMOR_04;
		break;
	case ARMOR_05:
		_itemName	= "가죽 갑옷";
		_itemInfo	= "방어 +8";
		_itemValue1 = 8;
		_buyPrice	= BUY_PRICE_ARMOR_05;
		break;
	case CLOTHES_NONE:
		break;
	case CLOTHES_01:
		_itemName = "여름옷";
		_buyPrice = BUY_PRICE_CLOTHES_01;
		break;
	case CLOTHES_02:
		_itemName = "겨울옷";
		_buyPrice = BUY_PRICE_CLOTHES_02;
		break;
	case CLOTHES_03:
		_itemName = "목면드레스";
		_itemInfo = "기품 +15";
		_itemValue1 = 15;
		_buyPrice = BUY_PRICE_CLOTHES_03;
		break;
	case CLOTHES_04:
		_itemName = "실크 드레스";
		_itemInfo = "기품 +40";
		_itemValue1 = 40;
		_buyPrice = BUY_PRICE_CLOTHES_04;
		break;
	case CLOTHES_05:
		_itemName = "가죽 드레스";
		_itemInfo = "색기 +50 / 도덕성 -20";
		_itemValue1 = 50;
		_itemValue2 = 20;
		_buyPrice = BUY_PRICE_CLOTHES_05;
		break;
	case CLOTHES_06:
		_itemName = "가시 드레스";
		_itemInfo = "감수성 +40 / 도덕성 -30";
		_itemValue1 = 40;
		_itemValue2 = 30;
		_buyPrice = BUY_PRICE_CLOTHES_06;
		break;
	case CLOTHES_07:
		_itemName = "평상 복";
		break;
	case GENERAL_NONE:
		break;
	case GENERAL_01:
		_itemName = "인형";
		_itemInfo = "감수성 +5 / 스트레스 -40";
		_itemValue1 = 5;
		_itemValue2 = 40;
		_buyPrice = BUY_PRICE_GENERAL_01;
		break;
	case GENERAL_02:
		_itemName = "찻잔";
		_itemInfo = "기품 +10";
		_itemValue1 = 10;
		_buyPrice = BUY_PRICE_GENERAL_02;
		break;
	case GENERAL_03:
		_itemName = "책";
		_itemInfo = "지능 +8";
		_itemValue1 = 8;
		_buyPrice = BUY_PRICE_GENERAL_03;
		break;
	case GENERAL_04:
		_itemName = "시집";
		_itemInfo = "감수성 +12";
		_itemValue1 = 12;
		_buyPrice = BUY_PRICE_GENERAL_04;
		break;
	case GENERAL_05:
		_itemName = "쾌유환";
		_itemInfo = "HP 회복";
		_buyPrice = BUY_PRICE_GENERAL_05;
		break;
	case GENERAL_06:
		_itemName = "폭탄";
		_itemInfo = "공격용";
		_buyPrice = BUY_PRICE_GENERAL_06;
		break;
	case FOOD_NONE:
		break;
	case FOOD_01:
		_itemName = "케이크";
		_itemInfo = "스트레스 -50 / 체중 + 1.0";
		_itemValue1 = 50;
		_itemValue2 = (float)1.0;
		_buyPrice = BUY_PRICE_FOOD_01;
		break;
	case FOOD_02:
		_itemName = "물고기요리";
		_itemInfo = "스트레스 -30 / 체중 + 0.3";
		_itemValue1 = 30;
		_itemValue2 = (float)0.3;
		_buyPrice = BUY_PRICE_FOOD_02;
		break;
	case FOOD_03:
		_itemName = "고기요리";
		_itemInfo = "체력 +15 / 체중 +1.2";
		_itemValue1 = 15;
		_itemValue2 = (float)1.2;
		_buyPrice = BUY_PRICE_FOOD_03;
		break;
	case FOOD_04:
		_itemName = "고대의 우유";
		_itemInfo = "살이 빠진다";
		_itemValue1 = 1;
		break;
	}

	return S_OK;
}

void item::release()
{
	_img = nullptr;
}

void item::update()
{
}

void item::render()
{
}

string item::makeName(ITEM_TYPE type)
{
	return string();
}

