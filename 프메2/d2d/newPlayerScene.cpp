#include "stdafx.h"
#include "newPlayerScene.h"
#include "princess.h"

newPlayerScene::newPlayerScene()
{
}


newPlayerScene::~newPlayerScene()
{
}

HRESULT newPlayerScene::init()
{
	_princess = SCENEMANAGER->getPrincessAddress();
	_nState = NEW_FATHER_NAME_INPUT;

	_isDataInput = true;
	_isclear = false;
	_clearBtn = { 175, 430, 235, 455 };
	_returnBtn = { 270, 430, 330, 455 };
	return S_OK;
}

void newPlayerScene::release()
{
}

void newPlayerScene::update()
{

	if (_nState == NEW_FATHER_NAME_INPUT)
	{
		if (PtInD2D1Rect(_clearBtn, _ptMouse))
		{
			_isclear = true;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_nState = NEW_DAUGHTER_NAME_INPUT;
			}
		}
	}

	/*
	switch (_nState)
	{
	case NEW_FATHER_NAME_INPUT:

		break;
	case NEW_DAUGHTER_NAME_INPUT:
		break;
	case NEW_DAUGHTER_BRIT_SELECT:
		break;
	case NEW_FATHER_AGE_SELECT:
		break;
	case NEW_FATHER_BRIT_SELECT:
		break;
	case NEW_DAUGTHER_BTYPE_SELECT:
		break;
	}
	*/
}

void newPlayerScene::render()
{
	WCHAR newplayer[1024];

	switch (_nState)
	{
	case NEW_FATHER_NAME_INPUT:
		IMAGEMANAGER->findImage("캐릭터생성")->frameRender(0,0,1,0);
		D2D1_RECT_F _rc;
		_rc = { (WINSIZEX /2 -150), 300, (WINSIZEX/2 + 150), 350 };
		D2DMANAGER->fillRectangle(RGB(255, 255, 255), _rc);
		if (_inputData.size())
		{
			list<TCHAR>::iterator iter = _inputData.begin();
			string str = "";
			for (; iter != _inputData.end(); iter++)
			{
				str += *iter;
			}
			_fatherName = str;
			D2DMANAGER->drawText(string2wstring(_fatherName).c_str(), 250, 305, 48, RGB(0, 0, 0));
		}

		D2DMANAGER->fillRectangle(RGB(255, 0, 255), _clearBtn);
		swprintf_s(newplayer, L"완료");
		D2DMANAGER->drawText(newplayer, 180, 430, 24);
		swprintf_s(newplayer, L"뒤로");
		D2DMANAGER->drawText(newplayer, 275, 430, 24);

		swprintf_s(newplayer, L"%d" , _isclear);
		D2DMANAGER->drawText(newplayer, 100, 430, 24);
		break;
	case NEW_DAUGHTER_NAME_INPUT:
		IMAGEMANAGER->findImage("캐릭터생성")->frameRender(0, 0, 2, 0);
		_isInputNone = true;

		break;
	case NEW_DAUGHTER_BRIT_SELECT:
		break;
	case NEW_FATHER_AGE_SELECT:
		break;
	case NEW_FATHER_BRIT_SELECT:
		break;
	case NEW_DAUGTHER_BTYPE_SELECT:
		break;
	}
}

void newPlayerScene::dautherNameCreat()
{

}
