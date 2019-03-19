#pragma once
#include "baseUI.h"

enum MAIN_STATE
{
	M_STATE_NONE,

	M_STATE_PLAYER_STATE,
	M_STATE_DIET_STATE,
	M_STATE_INFO,
	M_STATE_SHOP,
	M_STATE_ITEM,
	M_STATE_SAVE,

	M_STATE_SCHEDULE,
};

enum MAIN_MENU_SELECT
{
	M_SELECT_NONE,

	M_SELECT_PLAYER_STATE,
	M_SELECT_DIET_STATE,
	M_SELECT_INFO,
	M_SELECT_SHOP,
	M_SELECT_ITEM,
	M_SELECT_SAVE,
	
	M_SELECT_SCHEDULE,
};

class mainUI : public baseUi
{
private:

	MAIN_STATE _mState;
	MAIN_MENU_SELECT _mSelect;
	D2D1_RECT_F _mSelectBox[9];

public:
	mainUI();
	~mainUI();

	HRESULT init();
	void release();
	void update();
	void render();

};

