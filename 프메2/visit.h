#pragma once
#include "baseUi.h"

enum VISIT_STATE
{
	V_SELECT_NONE,

	V_SELECT_GUARD,		
	V_SELECT_KNIGHT,
	V_SELECT_GENERAL,
	V_SELECT_MINISTER,
	V_SELECT_BISHOP,
	V_SELECT_CONCUBINE,
	V_SELECT_QUEEN,
	V_SELECT_KING,
	V_SELECT_CLOWN,
	V_SELECT_PRINCE,

};
enum PT_CHEK
{
	V_PT_NONE,
	V_PT_1,
	V_PT_2,
	V_PT_3,
	V_PT_4,
	V_PT_5,
	V_PT_6,
	V_PT_7,
	V_PT_8,
	V_PT_9,
	V_PT_10
};
class visit : public baseUi
{
private:

	VISIT_STATE _vState;
	PT_CHEK		_ptChek;
	D2D1_RECT_F _selectRc[10];

	bool _isVisit;

public:
	visit();
	~visit();

	HRESULT init();
	void release();
	void update();
	void render();

	void uiClose();
};

