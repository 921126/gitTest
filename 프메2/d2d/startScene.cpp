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
	//���� ��Ʈ
	_bg = { 0, 0, 800, 600 };
	//������
	FRAMEMANAGER->addFrame("���ۼ���", 302, 246, 10, 6);
	//���ùڽ�
	_selectBox[0] = { 308, 262, 488, 282 };
	_selectBox[1] = { 308, 287, 488, 307 };
	_selectBox[2] = { 308, 312, 488, 332 };
	//���û���
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
			//to do �̵��� �� ȣ��
		}
	}
	else if (PtInD2D1Rect(_selectBox[1], _ptMouse))
	{
		_sState = S_SKIP_START;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			//to do �̵��� �� ȣ��
		}
	}
	else if (PtInD2D1Rect(_selectBox[2], _ptMouse))
	{
		_sState = S_DATA_LOAD;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			//to do �̵��� �� ȣ��
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
	FRAMEMANAGER->findMenuFrame("���ۼ���")->render("���ùڽ�");

	switch (_sState)
	{
	case S_OPENING_START:
		IMAGEMANAGER->findImage("������3")->render(_selectBox[0].left, _selectBox[0].top);
		break;
	case S_SKIP_START:
		IMAGEMANAGER->findImage("������3")->render(_selectBox[1].left, _selectBox[1].top);
		break;
	case S_DATA_LOAD:
		IMAGEMANAGER->findImage("������3")->render(_selectBox[2].left, _selectBox[2].top);
		break;
	}

	WCHAR str[128];
	swprintf_s(str, L"ó������ ����");
	D2DMANAGER->drawText(str, 311, 262, 16, RGB(255, 255, 255));
	swprintf_s(str, L"ó������(������ ��ŵ)");
	D2DMANAGER->drawText(str, 311, 287, 16, RGB(255, 255, 255));
	swprintf_s(str, L"�ð��� �ǵ�����");
	D2DMANAGER->drawText(str, 311, 315, 16, RGB(255, 255, 255));
}
