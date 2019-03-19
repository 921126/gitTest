#pragma once
#include "gameNode.h"
#include "dataNode.h"

class item : public gameNode
{
private:
	vector<pair<string, float>> _mItem;
	ITEM_TYPE _type;
	
	image* _img;
	string _name;

	int _price;
	int _frameX, _frameY;
	int _clothesFrameY;

	float _x, _y;

	bool _isWear;
	bool _isStore;

public:
	item();
	~item();

	HRESULT init();
	void release();
	void update();
	void render();

	void setItem(string name, int price, bool isStore, vector<pair<string, float>> mItem, int type, int frameX, int frameY);
	void setImage();
	void setXY(float x, float y);

	//============================================================================ GET & SET
	void setName(string name) { _name = name; }
	void setFrameY(int frameY) { _clothesFrameY = frameY; }
	void setIsWear(bool isWear) { _isWear = isWear; }

	int getFrameY() { return _clothesFrameY; }
	int getFrameX() { return _frameX; }
	int getPrice() { return _price; }

	float getX() { return _x; }
	float getY() { return _y; }

	bool getIsWear() { return _isWear; }
	bool getIsStroe() { return _isStore; }

	string getName() { return _name; }
	ITEM_TYPE getType() { return _type; }
	vector<pair<string, float>> getmItem() { return _mItem; }
};

