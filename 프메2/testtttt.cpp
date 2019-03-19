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
	IMAGEMANAGER->render("메인배경");
	//IMAGEMANAGER->render("메인달력");
	//IMAGEMANAGER->render("상태창", 600, 0);
	//IMAGEMANAGER->frameRender("선택창", 600, 218, 0, 0);

	IMAGEMANAGER->frameRender("12살옷", 200, 262, 0, 3);

	//UIMANAGER->render();
}
