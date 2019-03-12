#pragma once
#include "baseUi.h"

enum VISIT_STATE
{
	V_SELECT_NONE,
	V_SELECT_GUARD,
	V_SELECT_KNIGHT,
	V_SELECT_MINISTER,
};
class visit : public baseUi
{
private:

	VISIT_STATE _vState;

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

