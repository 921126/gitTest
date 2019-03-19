#pragma once
#include "baseUi.h"

enum MAIN_STATE
{
	M_SELECT_NONE,

	M_SELECT_PLAYER_STATE,
	M_SELECT_TALK,
	M_SELECT_HEALTH_CARE,
	M_SELECT_INFO,
	M_SELECT_SHOP,
	M_SELECT_VISIT,
	M_SELECT_ITEM,
	M_SELECT_SAVE,

	M_SELECT_SCHEDULE
};
class mainUi : public baseUi
{
private:
	MAIN_STATE _mState;
	D2D1_RECT_F _selectBox[9];
public:
	mainUi();
	~mainUi();

	HRESULT init();
	void release();
	void update();
	void render();

};

