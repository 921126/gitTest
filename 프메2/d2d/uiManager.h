#pragma once

#include "singletonBase.h"
#include "baseUI.h"

enum UI_TYPE
{
	UI_NONE,

	UI_MAIN,
	UI_STATE,
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
};

