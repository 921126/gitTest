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
	FRAMEMANAGER->addFrame("��ȸ����â", 600, 300, 5, 4);
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
	FRAMEMANAGER->findMenuFrame("��ȸ����â")->render("���ùڽ�");

}
