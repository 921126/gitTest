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
	//임시데이터
	{
		_info.year = 1200;
		_info.mon = 3;
		_info.day = 18;
		_info.dayday = 0;

		_info.firstName = "도도";
		_info.lastName = "오";
		_info.bloodType = BTYPE_O;
		_info.strBloodType = "O";
		_info.age = 10;
		_info.dietType = "무리하지 않는다";
		_info.gold = 100000;

		_bStatus.height = 145.11;
		_bStatus.weight = 41.32;
		_bStatus.bast = 78.33;
		_bStatus.waist = 58.01;
		_bStatus.hip = 78.11;
		_bStatus.clothesType = 0;

		_date.fristName = _info.firstName;
		_date.lastName = _info.lastName;
		_date.year = _info.year;
		_date.mon = _info.mon;
		_date.day = _info.day;
		_date.dayday = _info.dayday;
		_date.faceType = FACE_NOMAL;

		//계절나누기
		if (3 <= _info.mon && _info.mon < 6)
		{
			_season = SPRING;
		}
		if (6 <= _info.mon && _info.mon < 9)
		{
			_season = SUMMER;
		}
		if (9 <= _info.mon && _info.mon < 11)
		{
			_season = AUTUMN;
		}
		if (_info.mon == 1 || _info.mon == 2 || _info.mon == 11 || _info.mon == 12)
		{
			_season = WINTER;
		}
	}

	setStatus();


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

void princess::setAge(int age)
{
	_info.age = age;

}

void princess::changeStatus(string name, float value)
{
	if (name == "공격력")
	{
		if (_status.attk_power < 0)
		{
			_status.attk_power = 0;
		}
		_status.attk_power += value;
	}
}

void princess::setStress(int stress)
{
	//************************************************************ 스트레스 체크용 셋함수 원하는 값넣어서 스트레스 값 조정하긔 
	//예외처리 만약에 스트레스가 0보다 작다면
	if (_status.stress < 0)
	{
		_status.stress = 0;
	}
	_status.stress = stress;
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

void princess::deleteVItem(int index)
{
	vector<item*>::iterator viItem;
	viItem = _vInventory.begin() + index;

	for (int i = 0; i < (*viItem)->getmItem().size(); ++i)
	{
		changeStatus((*viItem)->getmItem()[i].first, -(*viItem)->getmItem()[i].second);
	}
}

void princess::setStatus()
{
	switch (_info.mon)
	{
	case 1:
		if (_info.day <= 19)
			_status.Guardian.constellation = "염소자리", _status.Guardian.indexX = 6;
		else
			_status.Guardian.constellation = "물병자리", _status.Guardian.indexX = 7;
		break;
	case 2:
		if (_info.day <= 18)
			_status.Guardian.constellation = "물병자리", _status.Guardian.indexX = 7;
		else
			_status.Guardian.constellation = "물고기자리", _status.Guardian.indexX = 8;
		break;
	case 3:
		if (_info.day <= 20)
			_status.Guardian.constellation = "물고기자리", _status.Guardian.indexX = 8;
		else
			_status.Guardian.constellation = "양자리", _status.Guardian.indexX = 5;
		break;
	case 4:
		if (_info.day <= 19)
			_status.Guardian.constellation = "양자리", _status.Guardian.indexX = 5;
		else
			_status.Guardian.constellation = "황소자리", _status.Guardian.indexX = 3;
		break;
	case 5:
		if (_info.day <= 20)
			_status.Guardian.constellation = "황소자리", _status.Guardian.indexX = 3;
		else
			_status.Guardian.constellation = "쌍둥이자리", _status.Guardian.indexX = 2;
		break;
	case 6:
		if (_info.day <= 21)
			_status.Guardian.constellation = "쌍둥이자리", _status.Guardian.indexX = 2;
		else
			_status.Guardian.constellation = "게자리", _status.Guardian.indexX = 1;
		break;
	case 7:
		if (_info.day <= 22)
			_status.Guardian.constellation = "게자리", _status.Guardian.indexX = 1;
		else
			_status.Guardian.constellation = "사자자리", _status.Guardian.indexX = 0;
		break;
	case 8:
		if (_info.day <= 22)
			_status.Guardian.constellation = "사자자리", _status.Guardian.indexX = 0;
		else
			_status.Guardian.constellation = "처녀자리", _status.Guardian.indexX = 2;
		break;
	case 9:
		if (_info.day <= 22)
			_status.Guardian.constellation = "처녀자리", _status.Guardian.indexX = 2;
		else
			_status.Guardian.constellation = "천칭자리", _status.Guardian.indexX = 3;
		break;
	case 10:
		if (_info.day <= 23)
			_status.Guardian.constellation = "천칭자리", _status.Guardian.indexX = 3;
		else
			_status.Guardian.constellation = "전갈자리", _status.Guardian.indexX = 9;
		break;
	case 11:
		if (_info.day <= 22)
			_status.Guardian.constellation = "전갈자리", _status.Guardian.indexX = 9;
		else
			_status.Guardian.constellation = "사수자리", _status.Guardian.indexX = 4;
		break;
	case 12:
		if (_info.day <= 21)
			_status.Guardian.constellation = "사수자리", _status.Guardian.indexX = 4;
		else
			_status.Guardian.constellation = "염소자리", _status.Guardian.indexX = 6;
		break;
	}
	vector<string> vStr = TXTDATA->txtLoadCsv("data/status.csv", _status.Guardian.constellation.c_str());

	_status.Guardian.planet = vStr[0];
	_status.Guardian.name = vStr[1];

	_status.hp = atoi(vStr[3].c_str());
	_status.muscular_strength = atoi(vStr[4].c_str());
	_status.intelligence = atoi(vStr[5].c_str());
	_status.elegance = atoi(vStr[6].c_str());
	_status.charm = atoi(vStr[7].c_str());
	_status.morality = atoi(vStr[8].c_str());
	_status.faith = atoi(vStr[9].c_str());
	_status.sensitivity = atoi(vStr[10].c_str());

	_status.warrior_appraisal = atoi(vStr[11].c_str());
	_status.cambat_skill = atoi(vStr[12].c_str());
	_status.attk_power = atoi(vStr[13].c_str());
	_status.magic_appraisal = atoi(vStr[14].c_str());
	_status.magic_skill = atoi(vStr[15].c_str());
	_status.magic_power = atoi(vStr[16].c_str());
	_status.magicdef_power = atoi(vStr[17].c_str());

	_status.sociable_appraisal = atoi(vStr[18].c_str());
	_status.etiquette = atoi(vStr[19].c_str());
	_status.art = atoi(vStr[20].c_str());
	_status.talking_sense = atoi(vStr[21].c_str());

	_status.housework_appraisal = atoi(vStr[22].c_str());
	_status.cooking = atoi(vStr[23].c_str());
	_status.cleaning = atoi(vStr[24].c_str());
	_status.charactre = atoi(vStr[25].c_str());

	_status.total = atoi(vStr[26].c_str());
}
