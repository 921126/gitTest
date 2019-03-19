#include "stdafx.h"
#include "church.h"


church::church()
{
}


church::~church()
{
}

HRESULT church::init()
{
	FRAMEMANAGER->addFrame("교회선택창", 600, 300, 5, 4);
	return S_OK;
}

void church::release()
{
}

void church::update()
{

}

void church::render()
{
	FRAMEMANAGER->findMenuFrame("교회선택창")->render("선택박스");

}
