#pragma once
#include "gameNode.h"

//==================== 씬등록용 헤더

#include "mainScene.h"
#include "startScene.h"
#include "newPlayerScene.h"

class playGround : public gameNode
{
private:

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};