#pragma once
#include "baseUi.h"

enum TALK_STATE
{
	T_SELECT_NONE,

	T_SELECT_TALK_WITHPAPA,
	T_SELECT_POKET_MONEY,
	T_SELECT_SERMON,
};
class talk : public baseUi
{
private:

	TALK_STATE _tState;
	D2D1_RECT_F _rc[3];

	bool _istalkpapa;
	bool _ispoketmoney;
	bool _issermon;
public:
	talk();
	~talk();

	HRESULT init();
	void release();
	void update();
	void render();
};

