#pragma once
#include "gameNode.h"


class mainScene : public gameNode
{
private:

	int _healtyState;
	bool _ismainScene;

public:
	mainScene();
	~mainScene();

	HRESULT init();
	void release();
	void update();
	void render();


	void healthyStateRender();
};

