#include "stdafx.h"
#include "princess.h"


princess::princess()
{
}


princess::~princess()
{
}

HRESULT princess::init()
{

	return S_OK;
}

void princess::release()
{
}

void princess::update()
{
}

void princess::render()
{
}

bool princess::setItem(item * newItem)
{
	if (_vInventory.size() > 40) return false;
	_vInventory.push_back(newItem);
}

void princess::setDataItem(vector<item*> vTotal)
{
	for (int i = 0; i < _vItemName.size(); ++i)
	{
		for (int j = 0; j < vTotal.size(); ++j)
		{
			if (_vItemName[i] == vTotal[j]->getName())
			{
				_vInventory.push_back(vTotal[j]);
				break;
			}
		}
	}
}