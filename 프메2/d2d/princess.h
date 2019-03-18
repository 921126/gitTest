#pragma once
#include "gameNode.h"
#include "dataNode.h"
#include "item.h"

class princess : public gameNode
{
private:

	vector<item*> _vInventory;
	vector<string> _vItemName;

	tagInfo _info;
	tagStatus _status;
	tagBodyStatus _bStatus;
	tagImage _face, _body;
	tagDate _date;

	SEASEON_TYPE _season;


public:
	princess();
	~princess();

	HRESULT init();
	void release();
	void update();
	void render();

	void setAge(int age);
	void changeStatus(string name, float value);
	void setStress(int stress);

	bool setItem(item* newItem);
	void setDataItem(vector<item*> vTotal);
	void deleteVItem(int index);


	//=========================================================================================== Get & Set

	void setInfo(tagInfo info) { _info = info; }
	void setStatus(tagStatus status) { _status = status; }
	void setBodyStatus(tagBodyStatus bStatus) { _bStatus = bStatus; }
	void setFatherName(string fatherName) { _info.lastName = fatherName; }
	void setSeason(int season) { _season = (SEASEON_TYPE)season; }
	
	void setDietType(string type) { _info.dietType = type; }
	void setVItemName(vector<string> vName) { _vItemName = vName; }
	void setStatus();

	void setDate(tagDate date) { _date = date; }
	void setYear(int year) { _date.year = year; }
	void setMonth(int mon) { _date.mon = mon; }
	void setDayDay(int dayday) { _date.dayday = dayday; }
	void setDay(int day) { _date.day = day; }
	void setGold(int gold)	{ _info.gold += gold; }

	int getGold()			{ return _info.gold; }
	int getDayDay() { return _date.dayday; }
	int getDay() { return _date.day; }


	tagInfo getInfo()			{ return _info; }
	tagInfo* getInfoPointer()	{ return &_info; }

	tagStatus getStatus()			{ return _status; }
	tagStatus* getStatusPointer()	{ return &_status; }

	tagBodyStatus getBodyStatus()			{ return _bStatus; }
	tagBodyStatus* getBodyStatusPointer()	{ return &_bStatus; }

	tagDate getDate()			{ return _date; }
	tagDate* getDatePointer()	{ return &_date; }

	string getFatherName() { return _info.lastName; }

	vector<item*> getVItem() { return _vInventory; }
};

