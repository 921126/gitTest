#pragma once
#include "gameNode.h"

enum SELECT_START_STATE
{
	S_SELECT_NONE,			//아무것도 선택하고 있지 않음
	S_SELECT_OPENING_START,	//오프닝재생 시작 선택
	S_SELECT_START,			//오프닝스킵 시작 선택
	S_SELECT_LOAD,			//불러오기 선택
};
struct tagSelectBox
{
	D2D1_RECT_F _rc;
};
class startScene : public gameNode
{
private:

	tagSelectBox _selectBox[3];
	SELECT_START_STATE _selectState;

public:
	startScene();
	~startScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

