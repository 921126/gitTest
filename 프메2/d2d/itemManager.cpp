#include "stdafx.h"
#include "itemManager.h"


itemManager::itemManager()
{
}


itemManager::~itemManager()
{
}

HRESULT itemManager::init()
{
	_type = DATA_WEAPON;
	loadData("data/weapon.csv");
	_type = DATA_ARMOR;
	loadData("data/armor.csv");

	return S_OK;
}

void itemManager::release()
{
}

void itemManager::update()
{
}

void itemManager::render()
{
}

void itemManager::loadData(const char * dataName)
{
	vector<string> vStr = TXTDATA->txtLoadCsv(dataName);

	for (int i = 0; i < vStr.size(); ++i)
	{
		bool isStore;
		char str[100000];
		strcpy_s(str, vStr[i].c_str());

		item* Item = new item;
		vector<pair<string, float>> mItem;
		vector<string> temp = TXTDATA->charArraySeparation(str);

		temp[2] == "O" ? isStore = true : isStore = false;

		for (int j = 3; j < temp.size() - 1; j += 2)
		{
			mItem.push_back(make_pair(temp[j], atof(temp[j + 1].c_str())));
		}

		switch (_type)
		{
		case DATA_WEAPON:
			Item->setItem(temp[0], atoi(temp[1].c_str()), isStore, mItem, 0, i, 0);
			_vWeapon.push_back(Item);
			break;
		case DATA_ARMOR:
			Item->setItem(temp[0], atoi(temp[1].c_str()), isStore, mItem, 1, i, 1);
			_vArmor.push_back(Item);
			break;
		case DATA_CLOTHES:
			Item->setItem(temp[0], atoi(temp[1].c_str()), isStore, mItem, 2, i, 2);
			_vClothes.push_back(Item);
			break;
		}
		_vTotal.push_back(Item);
	}
}
