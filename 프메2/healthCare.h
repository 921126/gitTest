#pragma once
#include "baseUi.h"

enum HEALTH_BASICS
{
	H_B_NONE,
	H_B_NOSTRESS,
	H_B_HEALTHY,
	H_B_COYLY,
	H_B_DIET,
};
enum HEALTH_STATE
{
	H_SELECT_NONE,

	H_SELECT_NOSTRESS,	//무리하지않는다
	H_SELECT_HEALTHY,	//튼튼하게
	H_SELECT_COYLY,		//얌전하게
	H_SELECT_DIET,		//다이어트시킨다
};
enum HEALTH_PT_CHEK
{
	H_PT_NONE,

	H_PT_1,
	H_PT_2,
	H_PT_3,
	H_PT_4
};
enum HEALTH_CHANGE
{
	H_CHANGE_NONE,

	H_CHANGE_THIS,
	H_CHANGE_NO
};
class healthCare : public baseUi
{
private:
	HEALTH_BASICS	_hBasice;
	HEALTH_STATE	_hState;
	HEALTH_PT_CHEK	_hPtChek;
	HEALTH_CHANGE	_hChange;
	D2D1_RECT_F		_selectRc[4];
	D2D1_RECT_F		_changeRc[2];

	bool _isThis;           //이걸로 바꿀께요
	bool _isNo;				//아 상태안바꿔욧 
	bool _iscomplete;		//완료됬냐?

public:
	healthCare();
	~healthCare();

	HRESULT init();
	void release();
	void update();
	void render();

	void uiClose();
	
	virtual int getHealthState();
};

