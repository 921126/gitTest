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
	//배경용 렉트
	_bg = { 0, 0, 800, 600 };
	//프레임
	FRAMEMANAGER->addFrame("시작선택", 302, 246, 10, 6);
	//선택박스
	_selectBox[0] = { 308, 262, 488, 282 };
	_selectBox[1] = { 308, 287, 488, 307 };
	_selectBox[2] = { 308, 312, 488, 332 };
	//선택상태
	_sState = S_NONE;

	return S_OK;
}

void startScene::release()
{
}

void startScene::update()
{
	if (PtInD2D1Rect(_selectBox[0], _ptMouse))
	{
		_sState = S_OPENING_START;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			//to do 이동할 씬 호출
		}
	}
	else if (PtInD2D1Rect(_selectBox[1], _ptMouse))
	{
		_sState = S_SKIP_START;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			//to do 이동할 씬 호출
		}
	}
	else if (PtInD2D1Rect(_selectBox[2], _ptMouse))
	{
		_sState = S_DATA_LOAD;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			//to do 이동할 씬 호출
		}
	}
	else
	{
		_sState = S_NONE;
	}
}

void startScene::render()
{
	D2DMANAGER->fillRectangle(RGB(0, 0, 0), _bg);
	FRAMEMANAGER->findMenuFrame("시작선택")->render("선택박스");

	switch (_sState)
	{
	case S_OPENING_START:
		IMAGEMANAGER->findImage("선택중3")->render(_selectBox[0].left, _selectBox[0].top);
		break;
	case S_SKIP_START:
		IMAGEMANAGER->findImage("선택중3")->render(_selectBox[1].left, _selectBox[1].top);
		break;
	case S_DATA_LOAD:
		IMAGEMANAGER->findImage("선택중3")->render(_selectBox[2].left, _selectBox[2].top);
		break;
	}

	WCHAR str[128];
	swprintf_s(str, L"처음부터 시작");
	D2DMANAGER->drawText(str, 311, 262, 16, RGB(255, 255, 255));
	swprintf_s(str, L"처음부터(오프닝 스킵)");
	D2DMANAGER->drawText(str, 311, 287, 16, RGB(255, 255, 255));
	swprintf_s(str, L"시간을 되돌린다");
	D2DMANAGER->drawText(str, 311, 315, 16, RGB(255, 255, 255));
}
