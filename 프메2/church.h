#pragma once
#include "baseUi.h"

enum CHURCH_STATE
{
	C_SELECT_NONE,				//선택안함
	C_SELECT_CONTRIBURION,		//기부하기
	C_SELECT_NOTCON,			//기부안하기
};
class church : public baseUi
{
private:

	CHURCH_STATE _cState;

public:
	church();
	~church();

	HRESULT init();
	void release();
	void update();
	void render();
};

