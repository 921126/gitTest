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
	_img = IMAGEMANAGER->findImage("�����۵�");
	_itemType = type;

	switch (type)
	{
	case WEAPON_NONE:
		break;
	case WEAPON_01:
		_itemName	= "���";
		_itemInfo	= "���� +3";
		_itemValue1 = 3;
		_buyPrice	= BUY_PRICE_WEAPON_01;
		break;
	case WEAPON_02:
		_itemName	= "������";
		_itemInfo	= "���� +6";
		_itemValue1 = 6;
		_buyPrice	= BUY_PRICE_WEAPON_02;
		break;
	case WEAPON_03:
		_itemName	= "ö�� �ܰ�";
		_itemInfo	= "���� +9";
		_itemValue1 = 9;
		_buyPrice	= BUY_PRICE_WEAPON_03;
		break;
	case WEAPON_04:
		_itemName	= "ö�� ���";
		_itemInfo	= "���� +12 / ���� -2";
		_itemValue1 = 12;
		_itemValue2 = 2;
		_buyPrice	= BUY_PRICE_WEAPON_04;
		break;
	case WEAPON_05:
		_itemName	= "��� ö��";
		_itemInfo	= "���� +18 / ��� -4";
		_itemValue1 = 18;
		_itemValue2 = 4;
		_buyPrice	= BUY_PRICE_WEAPON_05;
		break;
	case WEAPON_06:
		_itemName	= "�̽�����";
		_itemInfo	= "���� +20";
		_itemValue1 = 20;
		_buyPrice	= BUY_PRICE_WEAPON_06;
		break;
	case WEAPON_07:
		_itemName	= "���� �ܳ���";
		_itemInfo	= "���� +20 / ���� +10";
		_itemValue1 = 20;
		_itemValue2 = 10;
		_buyPrice	= BUY_PRICE_WEAPON_07;
		break;
	case ARMOR_NONE:
		break;
	case ARMOR_01:
		_itemName	= "��ũ ����";
		_itemInfo	= "��� +2 / ���� +50";
		_itemValue1 = 2;
		_itemValue2 = 50;
		_buyPrice	= BUY_PRICE_ARMOR_01;
		break;
	case ARMOR_02:
		_itemName	= "�̽��� ����";
		_itemInfo	= "��� +22 / �׸� +15";
		_itemValue1 = 22;
		_itemValue2 = 15;
		_buyPrice	= BUY_PRICE_ARMOR_02;
		break;
	case ARMOR_03:
		_itemName	= "ö ����";
		_itemInfo	= "��� +18 / ���� -15";
		_itemValue1 = 18;
		_itemValue2 = 15;
		_buyPrice	= BUY_PRICE_ARMOR_03;
		break;
	case ARMOR_04:
		_itemName	= "��罽 ����";
		_itemInfo	= "��� +14 / ���� -3";
		_itemValue1 = 14;
		_itemValue2 = 3;
		_buyPrice	= BUY_PRICE_ARMOR_04;
		break;
	case ARMOR_05:
		_itemName	= "���� ����";
		_itemInfo	= "��� +8";
		_itemValue1 = 8;
		_buyPrice	= BUY_PRICE_ARMOR_05;
		break;
	case CLOTHES_NONE:
		break;
	case CLOTHES_01:
		_itemName = "������";
		_buyPrice = BUY_PRICE_CLOTHES_01;
		break;
	case CLOTHES_02:
		_itemName = "�ܿ��";
		_buyPrice = BUY_PRICE_CLOTHES_02;
		break;
	case CLOTHES_03:
		_itemName = "���巹��";
		_itemInfo = "��ǰ +15";
		_itemValue1 = 15;
		_buyPrice = BUY_PRICE_CLOTHES_03;
		break;
	case CLOTHES_04:
		_itemName = "��ũ �巹��";
		_itemInfo = "��ǰ +40";
		_itemValue1 = 40;
		_buyPrice = BUY_PRICE_CLOTHES_04;
		break;
	case CLOTHES_05:
		_itemName = "���� �巹��";
		_itemInfo = "���� +50 / ������ -20";
		_itemValue1 = 50;
		_itemValue2 = 20;
		_buyPrice = BUY_PRICE_CLOTHES_05;
		break;
	case CLOTHES_06:
		_itemName = "���� �巹��";
		_itemInfo = "������ +40 / ������ -30";
		_itemValue1 = 40;
		_itemValue2 = 30;
		_buyPrice = BUY_PRICE_CLOTHES_06;
		break;
	case CLOTHES_07:
		_itemName = "��� ��";
		break;
	case GENERAL_NONE:
		break;
	case GENERAL_01:
		_itemName = "����";
		_itemInfo = "������ +5 / ��Ʈ���� -40";
		_itemValue1 = 5;
		_itemValue2 = 40;
		_buyPrice = BUY_PRICE_GENERAL_01;
		break;
	case GENERAL_02:
		_itemName = "����";
		_itemInfo = "��ǰ +10";
		_itemValue1 = 10;
		_buyPrice = BUY_PRICE_GENERAL_02;
		break;
	case GENERAL_03:
		_itemName = "å";
		_itemInfo = "���� +8";
		_itemValue1 = 8;
		_buyPrice = BUY_PRICE_GENERAL_03;
		break;
	case GENERAL_04:
		_itemName = "����";
		_itemInfo = "������ +12";
		_itemValue1 = 12;
		_buyPrice = BUY_PRICE_GENERAL_04;
		break;
	case GENERAL_05:
		_itemName = "����ȯ";
		_itemInfo = "HP ȸ��";
		_buyPrice = BUY_PRICE_GENERAL_05;
		break;
	case GENERAL_06:
		_itemName = "��ź";
		_itemInfo = "���ݿ�";
		_buyPrice = BUY_PRICE_GENERAL_06;
		break;
	case FOOD_NONE:
		break;
	case FOOD_01:
		_itemName = "����ũ";
		_itemInfo = "��Ʈ���� -50 / ü�� + 1.0";
		_itemValue1 = 50;
		_itemValue2 = (float)1.0;
		_buyPrice = BUY_PRICE_FOOD_01;
		break;
	case FOOD_02:
		_itemName = "�����丮";
		_itemInfo = "��Ʈ���� -30 / ü�� + 0.3";
		_itemValue1 = 30;
		_itemValue2 = (float)0.3;
		_buyPrice = BUY_PRICE_FOOD_02;
		break;
	case FOOD_03:
		_itemName = "���丮";
		_itemInfo = "ü�� +15 / ü�� +1.2";
		_itemValue1 = 15;
		_itemValue2 = (float)1.2;
		_buyPrice = BUY_PRICE_FOOD_03;
		break;
	case FOOD_04:
		_itemName = "����� ����";
		_itemInfo = "���� ������";
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

