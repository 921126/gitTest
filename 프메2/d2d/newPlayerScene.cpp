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
	_nState = NEW_DAUGHTER_BRIT_SELECT;

	_isDataInput = true;
	_clearBtn = { 175, 430, 235, 455 };
	_returnBtn = { 270, 430, 330, 455 };

	BrithDayCalendar();

	return S_OK;
}

void newPlayerScene::release()
{
}

void newPlayerScene::update()
{

	switch (_nState)
	{
	case NEW_FATHER_NAME_INPUT:
		if (PtInD2D1Rect(_clearBtn, _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_nState = NEW_DAUGHTER_NAME_INPUT;
				if (_fatherName.size() > 8)
				{
					_fatherName.substr(0, 7);
				}
				_isDataInput = true;
				_inputData.clear();
			}
		}
		break;
	case NEW_DAUGHTER_NAME_INPUT:
		if (PtInD2D1Rect(_clearBtn, _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_nState = NEW_DAUGHTER_BRIT_SELECT;
				if (_daughterName.size() > 8)
				{
					_daughterName = _daughterName.substr(0, 7);
				}
				_princessInfo.firstName = _daughterName;
				_princessInfo.lastName = _fatherName;
			}
		}
		break;
	case NEW_DAUGHTER_BRIT_SELECT:
		BrithDayCalendarSelect();
		break;
	case NEW_FATHER_AGE_SELECT:
		break;
	case NEW_FATHER_BRIT_SELECT:
		break;
	case NEW_DAUGTHER_BTYPE_SELECT:
		break;
	}
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
		break;
	case NEW_DAUGHTER_NAME_INPUT:
		IMAGEMANAGER->findImage("캐릭터생성")->frameRender(0, 0, 0, 0);
		_isInputNone = true;
		D2D1_RECT_F _rc2;
		_rc2 = { (WINSIZEX / 2 - 150), 300, (WINSIZEX / 2 + 150), 350 };
		D2DMANAGER->fillRectangle(RGB(255, 255, 255), _rc2);
		if (_inputData.size())
		{
			list<TCHAR>::iterator iter = _inputData.begin();
			string str = "";
			for (; iter != _inputData.end(); iter++)
			{
				str += *iter;
			}
			_daughterName = str;
			D2DMANAGER->drawText(string2wstring(_daughterName).c_str(), 250, 305, 48, RGB(0, 0, 0));
		}

		D2DMANAGER->fillRectangle(RGB(255, 0, 255), _clearBtn);
		swprintf_s(newplayer, L"완료");
		D2DMANAGER->drawText(newplayer, 180, 430, 24);
		swprintf_s(newplayer, L"뒤로");
		D2DMANAGER->drawText(newplayer, 275, 430, 24);
		break;
	case NEW_DAUGHTER_BRIT_SELECT:
		IMAGEMANAGER->findImage("딸달력")->frameRender(0, 0, 0, 0);

		for (int i = 0; i < 31; ++i)
		{
			if (_isSelect[i])
			{
				D2DMANAGER->fillRectangle(RGB(255, 0, 255), _1mon[i]);
				IMAGEMANAGER->findImage("딸생일선택")->frameRender(_1mon[i].left, _1mon[i].top, 0, i);
			}
		}
		for (int i = 0; i < 30; ++i)
		{
			D2DMANAGER->fillRectangle(RGB(255, 0, 255), _2mon[i]);
		}

		swprintf_s(newplayer, L"%d", _princessInfo.year);
		D2DMANAGER->drawText(newplayer, 38, 73, 14, RGB(255,255,255));
		swprintf_s(newplayer, L"%d", _princessInfo.mon);
		D2DMANAGER->drawText(newplayer, 88, 73, 14, RGB(255, 255, 255));
		swprintf_s(newplayer, L"%d", _princessInfo.day);
		D2DMANAGER->drawText(newplayer, 113, 73, 14, RGB(255, 255, 255));
		break;
	case NEW_FATHER_AGE_SELECT:
		break;
	case NEW_FATHER_BRIT_SELECT:
		break;
	case NEW_DAUGTHER_BTYPE_SELECT:
		break;
	}
}

void newPlayerScene::BrithDayCalendar()
{
	for (int i = 0; i < 32; ++i)
	{
		if (i == 0)
		{
			_1mon[i] = { 241, 104, 261, 119 };
		}
		else if (1 <= i && i < 8)
		{
			_1mon[i] = { (float)61 + ((i - 1) * 30), 120, (float)81 + ((i - 1) * 30), 135 };

		}
		else if (8 <= i && i < 15)
		{
			_1mon[i] = { (float)61 + ((i - 8) * 30), 136, (float)81 + ((i - 8) * 30), 151 };
		}
		else if (15 <= i && i < 22)
		{
			_1mon[i] = { (float)61 + ((i - 15) * 30), 152, (float)81 + ((i - 15) * 30), 167 };
		}
		else if (22 <= i && i < 29)
		{
			_1mon[i] = { (float)61 + ((i - 22) * 30), 168, (float)81 + ((i - 22) * 30), 183 };
		}
		else
		{
			_1mon[i] = { (float)61 + ((i - 29) * 30), 184, (float)81 + ((i - 29) * 30), 199 };
		}
		_isSelect[i] = false;
	}

	for (int i = 0; i < 30; ++i)
	{
		if (0 <= i && i < 5)
		{
			_2mon[i] = { (float)372 + (i * 30), 104, (float)391 + (i * 30), 119 };
		}
		else if (6 <= i && i < 13)
		{
			_2mon[i] = { (float)312 + ((i - 6) * 30), 120, (float)331 + ((i - 6) * 30), 135 };
		}
		else if (13 <= i && i < 20)
		{
			_2mon[i] = { (float)312 + ((i - 13) * 30), 136, (float)331 + ((i - 13) * 30), 151 };
		}
		else if (20 <= i && i < 27)
		{
			_2mon[i] = { (float)312 + ((i - 20) * 30), 152, (float)331 + ((i - 20) * 30),167 };
		}
		else if( 27 <= i && i < 30)
		{
			_2mon[i] = { (float)312 + ((i - 27) * 30), 168, (float)331 + ((i - 27) * 30), 183 };
		}
	}
}

void newPlayerScene::BrithDayCalendarSelect()
{
	for (int i = 0; i < 31; ++i)
	{
		if (PtInD2D1Rect(_1mon[i], _ptMouse))
		{
			_isSelect[i] = true;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_princessInfo.year = 1200;
				_princessInfo.mon = 1;
				_princessInfo.day = i + 1;
				_princessInfo.age = 10;
			}
		}
		else
		{
			_isSelect[i] = false;
		}
	}
}
