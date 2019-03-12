#include "stdafx.h"
#include "startScene.h"


startScene::startScene()
{
}


startScene::~startScene()
{
}

HRESULT startScene::init()
{
	//프레임
	FRAMEMANAGER->addFrame("시작선택", 290, 246, 12, 6);
	//선택박스
	for (int i = 0; i < 3; ++i)
	{
		_selectBox[i]._rc = { 308.f , 264.f + (i * 24), 488.f, 288.f + (i * 24)};
	}
	//선택상태
	_selectState = S_SELECT_NONE;
	return S_OK;
}

void startScene::release()
{
}

void startScene::update()
{

	if (PtInD2D1Rect(_selectBox[0]._rc, _ptMouse))
	{
		_selectState = S_SELECT_OPENING_START;
	}
	else if (PtInD2D1Rect(_selectBox[1]._rc, _ptMouse))
	{
		_selectState = S_SELECT_START;
	}
	else if (PtInD2D1Rect(_selectBox[2]._rc, _ptMouse))
	{
		_selectState = S_SELECT_LOAD;
	}
	else
	{
		_selectState = S_SELECT_NONE;
	}
}

void startScene::render()
{
	IMAGEMANAGER->findImage("배경")->render(0,0);
	FRAMEMANAGER->findMenuFrame("시작선택")->render("선택박스");

	for (int i = 0; i < 3; ++i)
	{
		switch (_selectState)
		{
		case S_SELECT_NONE:
			D2DMANAGER->drawRectangle(_selectBox[i]._rc);
		break;
		case S_SELECT_OPENING_START:
			D2DMANAGER->fillRectangle(RGB(255, 0, 255), _selectBox[0]._rc);
		break;
		case S_SELECT_START:
			D2DMANAGER->fillRectangle(RGB(255, 0, 255), _selectBox[1]._rc);
		break;
		case S_SELECT_LOAD:
			D2DMANAGER->fillRectangle(RGB(255, 0, 255), _selectBox[2]._rc);
		break;
		}
	}
}
