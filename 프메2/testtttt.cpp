#include "stdafx.h"
#include "testtttt.h"


testtttt::testtttt()
{
}


testtttt::~testtttt()
{
}

HRESULT testtttt::init()
{

	return S_OK;
}

void testtttt::release()
{
}

void testtttt::update()
{
	UIMANAGER->update();

}

void testtttt::render()
{
	IMAGEMANAGER->render("���ι��");
	//IMAGEMANAGER->render("���δ޷�");
	//IMAGEMANAGER->render("����â", 600, 0);
	//IMAGEMANAGER->frameRender("����â", 600, 218, 0, 0);

	IMAGEMANAGER->frameRender("12���", 200, 262, 0, 3);

	//UIMANAGER->render();
}
