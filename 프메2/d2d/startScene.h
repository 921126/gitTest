#pragma once
#include "gameNode.h"

enum START_STATE
{
	S_NONE,
	S_OPENING_START,
	S_SKIP_START,
	S_DATA_LOAD
};

class startScene : public gameNode
{
private:
	START_STATE _sState;

	D2D1_RECT_F _selectBox[3];
	D2D1_RECT_F _bg;

public:
	startScene();
	~startScene();

	HRESULT init();
	void release();
	void update();
	void render();

};

