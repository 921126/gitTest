#pragma once
#include "gameNode.h"
class testtttt : public gameNode
{
private:

public:
	testtttt();
	~testtttt();

	HRESULT init();
	void release();
	void update();
	void render();
};

