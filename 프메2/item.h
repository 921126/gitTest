#pragma once
#include "gameNode.h"
#include "data.h"

enum ITEM_TYPE
{
	WEAPON_NONE,

	WEAPON_01,	//곤봉
	WEAPON_02,	//구리검
	WEAPON_03,	//철제 단검
	WEAPON_04,	//철제 장검
	WEAPON_05,	//양손 철검
	WEAPON_06,	//미스릴 검
	WEAPON_07,	//동방외날 검

	ARMOR_NONE = 100,

	ARMOR_01,	//실크 갑옷
	ARMOR_02,	//미스릴 갑옷
	ARMOR_03,	//철 갑옷
	ARMOR_04,	//쇠사글 갑옷
	ARMOR_05,	//가죽 갑옷 

	CLOTHES_NONE = 200,

	
	CLOTHES_01,	//여름 옷
	CLOTHES_02,	//겨울 옷
	CLOTHES_03,	//목면 드레스
	CLOTHES_04,	//실크 드레스
	CLOTHES_05,	//가죽 드레스
	CLOTHES_06,	//가시 드레스
	CLOTHES_07, //평상 복

	GENERAL_NONE = 300,

	GENERAL_01,	//인형
	GENERAL_02,	//찻잔
	GENERAL_03,	//책
	GENERAL_04,	//시집
	GENERAL_05,	//쾌유환
	GENERAL_06,	//폭탄

	FOOD_NONE	= 400,

	FOOD_01,	//케이크
	FOOD_02,	//물고기	요리
	FOOD_03,	//고기	요리
	FOOD_04,	//고대의 우유
};
enum ITEM_BUY_PRICE	
{
	BUY_PRICE_NONE,

	BUY_PRICE_WEAPON_01 = 15,		//곤봉
	BUY_PRICE_WEAPON_02 = 40,		//구리검
	BUY_PRICE_WEAPON_03 = 130,		//철제 단검
	BUY_PRICE_WEAPON_04 = 250,		//철제 장검
	BUY_PRICE_WEAPON_05 = 500,		//양손 철검
	BUY_PRICE_WEAPON_06 = 1200,		//미스릴 검
	BUY_PRICE_WEAPON_07 = 2000,		//동방외날 검

	BUY_PRICE_ARMOR_01 = 4480,		//실크 갑옷
	BUY_PRICE_ARMOR_02 = 2980,		//미스릴 갑옷
	BUY_PRICE_ARMOR_03 = 980,		//철 갑옷
	BUY_PRICE_ARMOR_04 = 498,		//쇠사글 갑옷
	BUY_PRICE_ARMOR_05 = 98,		//가죽 갑옷 

	BUY_PRICE_CLOTHES_01 = 70,		//여름 옷
	BUY_PRICE_CLOTHES_02 = 120,		//겨울 옷
	BUY_PRICE_CLOTHES_03 = 500,		//목면 드레스
	BUY_PRICE_CLOTHES_04 = 2000,	//실크 드레스
	BUY_PRICE_CLOTHES_05 = 3000,	//가죽 드레스
	BUY_PRICE_CLOTHES_06 = 2800,	//가시 드레스

	BUY_PRICE_GENERAL_01 = 120,		//인형
	BUY_PRICE_GENERAL_02 = 500,		//찻잔
	BUY_PRICE_GENERAL_03 = 120,		//책
	BUY_PRICE_GENERAL_04 = 400,		//시집
	BUY_PRICE_GENERAL_05 = 30,		//쾌유환
	BUY_PRICE_GENERAL_06 = 100,		//폭탄

	BUY_PRICE_FOOD_01 = 80,			//케이크
	BUY_PRICE_FOOD_02 = 120,		//물고기	요리
	BUY_PRICE_FOOD_03 = 200,		//고기	요리
};
class item : public singletonBase<item>
{
private:

	image*			_img;		//이미지
	D2D1_RECT_F		_rc;		//렉트
	
	string			_itemName;	//아이템 이름
	string			_itemInfo;	//아이템 정보
	ITEM_TYPE		_itemType;	//아이템 종류
	ITEM_BUY_PRICE	_buyPrice;	//아이템 가격

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

	//======================================= 겟 셋
	
	string getItemName(ITEM_TYPE type) { return _itemName; }
	string getItemInfo(ITEM_TYPE type) { return _itemInfo; }

	ITEM_TYPE getItemType() { return _itemType; }

	ITEM_BUY_PRICE	getBuyPrice(ITEM_TYPE type) { return _buyPrice; }
};

