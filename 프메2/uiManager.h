#pragma once

#include "singletonBase.h"
#include "baseUi.h"

//매니저사용할 유아이등록

#include "mainUi.h"
#include "talk.h"
#include "healthCare.h"
#include "shopList.h"
#include "visit.h"

enum UI_TYPE
{
	UI_NONE,

	UI_MAIN,

	UI_STATE,
	UI_TALK,
	UI_HEALTH_CARE,
	UI_INFO,
	UI_SHOP,
	UI_VISIT,
	UI_ITEM,
	UI_SAVE,
	UI_SCHEDULE,
};

class uiManager : public singletonBase<uiManager>
{
private:
	map<UI_TYPE, baseUi*> _uiMap;

	UI_TYPE _currentUI;
	UI_TYPE _beforeUI;

public:
	uiManager();
	~uiManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void moveBeforeUI();

	void selectUI(UI_TYPE type) { _currentUI = type; }
	void selectBeforUI(UI_TYPE type) { _beforeUI = type; }
	map<UI_TYPE, baseUi*> getUiMap() { return _uiMap; }
	HEALTH_BASICS getHealthState() { return (HEALTH_BASICS)_uiMap.find(UI_HEALTH_CARE)->second->getHealthState(); }

};

