#pragma once
#include "gameNode.h"
#include "data.h"

class item : public gameNode
{
private:

	ITEM_TYPE _type;
	vector<map<string, float>> _vitem;

	string _itemName;

	int _itemPrice;
	int _frameX, frameY;
	bool _isPutonClothes;		//이옷입을거니?
	bool _isStore;

public:
	item();
	~item();

	HRESULT init();
	void release();
	void update();
	void render();

	void setItem(string name, int price, bool isStore, vector<map<string, float>> _Vitem, int type, int frameX);
};

