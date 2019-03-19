#pragma once
#include "gameNode.h"
class prologueScene : public gameNode
{
private:

public:
	prologueScene();
	~prologueScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

