#pragma once
#include "gameNode.h"
#include "item.h"

enum DATA_TYPE
{
	DATA_WEAPON,
	DATA_ARMOR,
	DATA_CLOTHES,
};
class itemManager : public gameNode
{
private:
	vector<item*> _vWeapon;
	vector<item*> _vArmor;
	vector<item*> _vClothes;
	vector<item*> _vTotal;

	DATA_TYPE _type;

public:
	itemManager();
	~itemManager();

	HRESULT init();
	void release();
	void update();
	void render();
	void loadData(const char* dataName);

	vector<item*> getVWeapon() { return _vWeapon; }
	vector<item*> getVArmor() { return _vArmor; }
	vector<item*> getVClothes() { return _vClothes; }
	vector<item*> getVTotal() { return _vTotal; }
};

