#pragma once
#include "gameNode.h"

//==================== ����Ͽ� ���
#include "mapTool.h"
#include "objectTool.h"

#include "testtttt.h"

#include "startScene.h"
#include "prologueScene.h"
#include "newPlayerScene.h"

#include "mainScene.h"



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