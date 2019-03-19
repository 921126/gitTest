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

	return S_OK;
}

void newPlayerScene::release()
{
}

void newPlayerScene::update()
{
}

void newPlayerScene::render()
{
	switch (_nState)
	{
	case NEW_FATHER_NAME_INPUT:
		IMAGEMANAGER->findImage("캐릭터생성")->frameRender(0,0,1,0);
		D2D1_RECT_F _rc;
		_rc = { 205, 300, 605, 350 };
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
			D2DMANAGER->drawText( string2wstring( _fatherName).c_str(), 210, 305, 48, RGB(0, 0, 0));
		}
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
}
