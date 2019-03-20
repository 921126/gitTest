#pragma once
#include "gameNode.h"
#include "dataNode.h"
#include "item.h"

class princess : public gameNode
{
private:

	vector<item*> _vInventory;
	vector<string> _vItemName;

	tagInfo _princess;
	HOME_STATE _homeState;


public:
	princess();
	~princess();

	HRESULT init();
	void release();
	void update();
	void render();

	bool setItem(item* newItem);
	void setDataItem(vector<item*> vTotal);

	//=========================================================================================== Get & Set

	void setPrincessInfo(tagInfo princess) { _princess = princess; }
	tagInfo getPrincessInfo() { return _princess; }

	void setHomeState(HOME_STATE homeState) { _homeState = homeState; }
	HOME_STATE getHomeState() { return _homeState; }

	vector<item*> getVItem() { return _vInventory; }
};

