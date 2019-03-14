#pragma once
#include "gameNode.h"
#include "data.h"

enum ITEM_TYPE
{
	WEAPON_NONE,

	WEAPON_01,	//���
	WEAPON_02,	//������
	WEAPON_03,	//ö�� �ܰ�
	WEAPON_04,	//ö�� ���
	WEAPON_05,	//��� ö��
	WEAPON_06,	//�̽��� ��
	WEAPON_07,	//����ܳ� ��

	ARMOR_NONE = 100,

	ARMOR_01,	//��ũ ����
	ARMOR_02,	//�̽��� ����
	ARMOR_03,	//ö ����
	ARMOR_04,	//���� ����
	ARMOR_05,	//���� ���� 

	CLOTHES_NONE = 200,

	
	CLOTHES_01,	//���� ��
	CLOTHES_02,	//�ܿ� ��
	CLOTHES_03,	//��� �巹��
	CLOTHES_04,	//��ũ �巹��
	CLOTHES_05,	//���� �巹��
	CLOTHES_06,	//���� �巹��
	CLOTHES_07, //��� ��

	GENERAL_NONE = 300,

	GENERAL_01,	//����
	GENERAL_02,	//����
	GENERAL_03,	//å
	GENERAL_04,	//����
	GENERAL_05,	//����ȯ
	GENERAL_06,	//��ź

	FOOD_NONE	= 400,

	FOOD_01,	//����ũ
	FOOD_02,	//�����	�丮
	FOOD_03,	//���	�丮
	FOOD_04,	//����� ����
};
enum ITEM_BUY_PRICE	
{
	BUY_PRICE_NONE,

	BUY_PRICE_WEAPON_01 = 15,		//���
	BUY_PRICE_WEAPON_02 = 40,		//������
	BUY_PRICE_WEAPON_03 = 130,		//ö�� �ܰ�
	BUY_PRICE_WEAPON_04 = 250,		//ö�� ���
	BUY_PRICE_WEAPON_05 = 500,		//��� ö��
	BUY_PRICE_WEAPON_06 = 1200,		//�̽��� ��
	BUY_PRICE_WEAPON_07 = 2000,		//����ܳ� ��

	BUY_PRICE_ARMOR_01 = 4480,		//��ũ ����
	BUY_PRICE_ARMOR_02 = 2980,		//�̽��� ����
	BUY_PRICE_ARMOR_03 = 980,		//ö ����
	BUY_PRICE_ARMOR_04 = 498,		//���� ����
	BUY_PRICE_ARMOR_05 = 98,		//���� ���� 

	BUY_PRICE_CLOTHES_01 = 70,		//���� ��
	BUY_PRICE_CLOTHES_02 = 120,		//�ܿ� ��
	BUY_PRICE_CLOTHES_03 = 500,		//��� �巹��
	BUY_PRICE_CLOTHES_04 = 2000,	//��ũ �巹��
	BUY_PRICE_CLOTHES_05 = 3000,	//���� �巹��
	BUY_PRICE_CLOTHES_06 = 2800,	//���� �巹��

	BUY_PRICE_GENERAL_01 = 120,		//����
	BUY_PRICE_GENERAL_02 = 500,		//����
	BUY_PRICE_GENERAL_03 = 120,		//å
	BUY_PRICE_GENERAL_04 = 400,		//����
	BUY_PRICE_GENERAL_05 = 30,		//����ȯ
	BUY_PRICE_GENERAL_06 = 100,		//��ź

	BUY_PRICE_FOOD_01 = 80,			//����ũ
	BUY_PRICE_FOOD_02 = 120,		//�����	�丮
	BUY_PRICE_FOOD_03 = 200,		//���	�丮
};
class item : public singletonBase<item>
{
private:

	image*			_img;		//�̹���
	D2D1_RECT_F		_rc;		//��Ʈ
	
	string			_itemName;	//������ �̸�
	string			_itemInfo;	//������ ����
	ITEM_TYPE		_itemType;	//������ ����
	ITEM_BUY_PRICE	_buyPrice;	//������ ����

	int _itemValue1;
	int _itemValue2;

public:
	item();
	~item();

	HRESULT init();
	HRESULT init(ITEM_TYPE type);
	void release();
	void update();
	void render();

	string makeName(ITEM_TYPE type);

	//======================================= �� ��
	
	string getItemName(ITEM_TYPE type) { return _itemName; }
	string getItemInfo(ITEM_TYPE type) { return _itemInfo; }

	ITEM_TYPE getItemType() { return _itemType; }

	ITEM_BUY_PRICE	getBuyPrice(ITEM_TYPE type) { return _buyPrice; }
};

