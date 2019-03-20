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
	_isClear = false;
	_clearBtn = { 169, 437, 208, 461 };
	_returnBtn = { 270, 430, 330, 455 };

	BrithDayCalendar();

	for (int i = 0; i < 10; ++i)
	{
		_fatherAge[i] = { (float)260 + i * 30, 349, (float)270 + i * 30, 366 };
		_isAgeSelect[i] = false;
	}

	for (int i = 0; i < 4; ++i)
	{
		_isbtypeSelect[i] = false;
	}
	_bloodyType[0] = { 252, 349, 272, 366 };
	_bloodyType[1] = { 331, 349, 351, 366 };
	_bloodyType[2] = { 414, 349, 434, 366 };
	_bloodyType[3] = { 501, 349, 521, 366 };

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
		fatherNameInput();
		break;
	case NEW_DAUGHTER_NAME_INPUT:
		daughterNameInput();
		break;
	case NEW_DAUGHTER_BRIT_SELECT:
		BrithDayCalendarSelect();
		statusSetting();
		break;
	case NEW_FATHER_AGE_SELECT:

		for (int i = 0; i < 10; ++i)
		{
			if (PtInD2D1Rect(_fatherAge[i], _ptMouse))
			{
				_isAgeSelect[i] = true;
				
				if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
				{
					if (_fatherage <= 0)
					{
						_fatherage += i;
					}
					else if (_fatherage * 10 < 100)
					{
						_fatherage *= 10;
						_fatherage += i;
					}
					else if (_fatherage * 10 >= 100)
					{
						_fatherage *= 10;
						_fatherage %= 100;
						_fatherage += i;
					}
				}
			}
			else
			{
				_isAgeSelect[i] = false;
			}
		}
		if (PtInD2D1Rect(_clearBtn, _ptMouse))
		{
			_isClear = true;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_nState = NEW_FATHER_BRIT_SELECT;
			}
		}
		else
		{
			_isClear = false;
		}
		break;
	case NEW_FATHER_BRIT_SELECT:
		BrithDayCalendarSelect2();
		break;
	case NEW_DAUGTHER_BTYPE_SELECT:

		for (int i = 0; i < 4; ++i)
		{
			if (PtInD2D1Rect(_bloodyType[i], _ptMouse))
			{
				_isbtypeSelect[i] = true;
				if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
				{
					_bloodType = i;
					_princessInfo.bloodType = (BLOOD_TYPE)_bloodType;
					
					tagInfo princessInfo;
					
					princessInfo.lastName = _princessInfo.lastName;
					princessInfo.firstName = _princessInfo.firstName; 

					princessInfo.bloodType = _princessInfo.bloodType;
					princessInfo.year = _princessInfo.year;
					princessInfo.mon = _princessInfo.mon;
					princessInfo.day = _princessInfo.day;
					//요일넣어야함

					princessInfo.age = _princessInfo.age;
					princessInfo.gold = 500;

					princessInfo.height = RND->getFromIntTo(136, 152);
					int base = princessInfo.height = 136;
					princessInfo.weight = 29.20 + (base * 0.95);
					princessInfo.bast = 67.50 + (base * 0.5);
					princessInfo.waist = 47.51 + (base * 0.62);
					princessInfo.hip = 70.72 + (base * 0.52);

					princessInfo.foodStyle = PLAYER_FOODSTYLE::NOT_OVER;

					if (princessInfo.mon == 12 || princessInfo.mon == 1 || princessInfo.mon == 2)
					{
						princessInfo.seaseonType = WINTER;
					}
					else if (princessInfo.mon == 3 || princessInfo.mon == 4 || princessInfo.mon == 5)
					{
						princessInfo.seaseonType = SPRING;
					}
					else if (princessInfo.mon == 6 || princessInfo.mon == 7 || princessInfo.mon == 8)
					{
						princessInfo.seaseonType = SUMMER;
					}
					else if (princessInfo.mon == 9 || princessInfo.mon == 10 || princessInfo.mon == 11)
					{
						princessInfo.seaseonType = AUTUMN;
					}

					if (princessInfo.mon == 1)
					{
						if (princessInfo.day == 2 || princessInfo.day == 9 || princessInfo.day == 16 || princessInfo.day == 23 || princessInfo.day == 30)
						{
							princessInfo.dayday = SUN;
						}
						if (princessInfo.day == 3 || princessInfo.day == 10 || princessInfo.day == 17 || princessInfo.day == 24 || princessInfo.day == 31)
						{
							princessInfo.dayday = MON;
						}
					}

					SCENEMANAGER->changeScene("main");
					
				}
			}
			else
			{
				_isbtypeSelect[i] = false;
			}
		}
		break;
	}
}

void newPlayerScene::render()
{
	WCHAR newplayer[1024];

	switch (_nState)
	{
	case NEW_FATHER_NAME_INPUT:
		fatherNameRender();
		break;
	case NEW_DAUGHTER_NAME_INPUT:
		daughterNAmeRender();
		break;
	case NEW_DAUGHTER_BRIT_SELECT:
		IMAGEMANAGER->findImage("캐릭터생성배경")->frameRender(0, 0, 2, 0);
		BrithDayCalendarRender();
		break;
	case NEW_FATHER_AGE_SELECT:
		IMAGEMANAGER->findImage("캐릭터생성배경")->frameRender(0, 0, 3, 0);
		for (int i = 0; i < 10; ++i)
		{
			if (_isAgeSelect[i])
			{
				IMAGEMANAGER->findImage("아빠나이선택")->frameRender(_fatherAge[i].left, _fatherAge[i].top, 0, i);
			}
			swprintf_s(newplayer, L"%d", _fatherage);
			D2DMANAGER->drawText(newplayer, 373, 304, 24, RGB(0, 0, 0));
		}
		if (_isClear)
		{
			IMAGEMANAGER->findImage("캐릭터생성선택")->frameRender(_clearBtn.left, _clearBtn.top, 1, 0);
		}
		
		break;
	case NEW_FATHER_BRIT_SELECT:
		IMAGEMANAGER->findImage("캐릭터생성배경")->frameRender(0, 0, 4, 0);
		BrithDayCalendarRender();
		break;
	case NEW_DAUGTHER_BTYPE_SELECT:
		IMAGEMANAGER->findImage("캐릭터생성배경")->frameRender(0, 0, 5, 0);

		for (int i = 0; i < 4; ++i)
		{
			if (_isbtypeSelect[i])
			{
				IMAGEMANAGER->findImage("딸혈액형")->frameRender(_bloodyType[i].left, _bloodyType[i].top, 0, i);
			}
		}
		break;
	}
}

void newPlayerScene::fatherNameInput()
{
	if (PtInD2D1Rect(_clearBtn, _ptMouse))
	{
		_isClear = true;
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
	else
	{
		_isClear = false;
	}
}

void newPlayerScene::fatherNameRender()
{
	WCHAR newplayer[1024];
	IMAGEMANAGER->findImage("캐릭터생성배경")->frameRender(0, 0, 0, 0);
	D2D1_RECT_F _rc;
	_rc = { (WINSIZEX / 2 - 150), 300, (WINSIZEX / 2 + 150), 350 };
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


	if (_isClear)
	{
		IMAGEMANAGER->findImage("캐릭터생성선택")->frameRender(_clearBtn.left, _clearBtn.top, 1, 0);
	}
	else
	{
		IMAGEMANAGER->findImage("캐릭터생성선택")->frameRender(_clearBtn.left, _clearBtn.top, 0, 0);
	}
}

void newPlayerScene::daughterNameInput()
{
	if (PtInD2D1Rect(_clearBtn, _ptMouse))
	{
		_isClear = true;
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
	else
	{
		_isClear = false;
	}
}

void newPlayerScene::daughterNAmeRender()
{
	WCHAR newplayer[1024];
	IMAGEMANAGER->findImage("캐릭터생성배경")->frameRender(0, 0, 1, 0);
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

	if (_isClear)
	{
		IMAGEMANAGER->findImage("캐릭터생성선택")->frameRender(_clearBtn.left, _clearBtn.top, 1, 1);
	}
	else
	{
		IMAGEMANAGER->findImage("캐릭터생성선택")->frameRender(_clearBtn.left, _clearBtn.top, 0, 0);
	}
}

void newPlayerScene::BrithDayCalendar()
{
	for (int i = 0; i < 31; ++i)
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
	for (int i = 0; i < 29; ++i)
	{
		if (0 <= i && i < 5)
		{
			_2mon[i] = { (float)371 + (i * 30), 104, (float)391 + (i * 30), 119 };
		}
		else if (5 <= i && i < 12)
		{
			_2mon[i] = { (float)311 + ((i - 5) * 30), 120, (float)331 + ((i - 5) * 30), 135 };
		}
		else if (12 <= i && i < 19)
		{
			_2mon[i] = { (float)311 + ((i - 12) * 30), 136, (float)331 + ((i - 12) * 30), 151 };
		}
		else if (19 <= i && i < 26)
		{
			_2mon[i] = { (float)311 + ((i - 19) * 30), 152, (float)331 + ((i - 19) * 30),167 };
		}
		else
		{
			_2mon[i] = { (float)311 + ((i - 26) * 30), 168, (float)331 + ((i - 26) * 30), 183 };
		}

		_isSelect2[i] = false;
	}
	for (int i = 0; i < 31; ++i)
	{
		if (0 <= i && i < 4)
		{
			_3mon[i] = { (float)651 + (i * 30), 104, (float)671 + (i * 30), 119 };
		}
		else if (4 <= i && i < 11)
		{
			_3mon[i] = { (float)561 + ((i - 4) * 30), 120, (float)581 + ((i - 4) * 30), 135 };
		}
		else if (11 <= i && i < 18)
		{
			_3mon[i] = { (float)561 + ((i - 11) * 30),  136, (float)581 + ((i - 11) * 30), 151 };
		}
		else if (18 <= i && i < 25)
		{
			_3mon[i] = { (float)561 + ((i - 18) * 30), 152, (float)581 + ((i - 18) * 30), 167 };
		}
		else
		{
			_3mon[i] = { (float)561 + ((i - 25) * 30), 168, (float)581 + ((i - 25) * 30), 183 };
		}

		_isSelect3[i] = false;
	}

	for (int i = 0; i < 30; ++i)
	{
		if (i == 0)
		{
			_4mon[i] = { 241, 212, 261, 227 };
		}
		else if (1 <= i && i < 8)
		{
			_4mon[i] = { (float)61 + ((i - 1) * 30), 228, (float)81 + ((i - 1) * 30), 243 };
		}
		else if (8 <= i && i < 15)
		{
			_4mon[i] = { (float)61 + ((i - 8) * 30), 244, (float)81 + ((i - 8) * 30), 259 };
		}
		else if (15 <= i && i < 22)
		{
			_4mon[i] = { (float)61 + ((i - 15) * 30), 260, (float)81 + ((i - 15) * 30), 275 };
		}
		else if (22 <= i && i < 29)
		{
			_4mon[i] = { (float)61 + ((i - 22) * 30), 276, (float)81 + ((i - 22) * 30), 291 };
		}
		else
		{
			_4mon[i] = { (float)61 + ((i - 29) * 30), 292, (float)81 + ((i - 29) * 30), 307 };
		}
		_isSelect4[i] = false;
	}

	for (int i = 0; i < 31; ++i)
	{
		if (0 <= i && i < 6)
		{
			_5mon[i] = { (float)341 + (i * 30), 212, (float)361 + (i * 30) , 227 };
		}
		else if (6 <= i && i < 13)
		{
			_5mon[i] = { (float)311 + ((i - 6) * 30), 228, (float)331 + ((i - 6) * 30), 243 };
		}
		else if (13 <= i && i < 20)
		{
			_5mon[i] = { (float)311 + ((i - 13) * 30), 244, (float)331 + ((i - 13) * 30), 259 };
		}
		else if (20 <= i && i < 27)
		{
			_5mon[i] = { (float)311 + ((i - 20) * 30), 260, (float)331 + ((i - 20) * 30), 275 };
		}
		else
		{
			_5mon[i] = { (float)311 + ((i - 27) * 30), 276, (float)331 + ((i - 27) * 30), 291 };
		}
		_isSelect5[i] = false;
	}

	for (int i = 0; i < 30; ++i)
	{
		if (0 <= i && i < 3)
		{
			_6mon[i] = { (float) 681 + (i * 30), 212 , (float) 701 + (i*30), 227 };
		}
		else if (3 <= i && i < 10)
		{
			_6mon[i] = { (float)561 + ((i - 3) * 30), 228, (float)581 + ((i - 3) * 30), 243 };
		}
		else if (10 <= i && i < 17)
		{
			_6mon[i] = { (float)561 + ((i - 10) * 30), 244, (float)581 + ((i - 10) * 30), 259 };

		}
		else if (17 <= i && i < 24)
		{
			_6mon[i] = { (float)561 + ((i - 17) * 30), 260, (float)581 + ((i - 17) * 30), 275 };

		}
		else
		{
			_6mon[i] = { (float)561 + ((i - 24) * 30), 276, (float)581 + ((i - 24) * 30), 291 };
		}
		_isSelect6[i] = false;
	}
	for (int i = 0; i < 31; ++i)
	{
		if (i == 0)
		{
			_7mon[i] = { 241, 320, 261, 335 };
		}
		else if (1 <= i && i < 8)
		{
			_7mon[i] = { (float)61 + ((i - 1) * 30), 336, (float)81 + ((i - 1) * 30), 351 };
		}
		else if (8 <= i && i < 15)
		{
			_7mon[i] = { (float)61 + ((i - 8) * 30), 352, (float)81 + ((i - 8) * 30), 367 };
		}
		else if (15 <= i && i < 22)
		{
			_7mon[i] = { (float)61 + ((i - 15) * 30), 368, (float)81 + ((i - 15) * 30), 383 };
		}
		else if (22 <= i && i < 29)
		{
			_7mon[i] = { (float)61 + ((i - 22) * 30), 384, (float)81 + ((i - 22) * 30), 399 };
		}
		else
		{
			_7mon[i] = { (float)61 + ((i - 29) * 30), 400, (float)81 + ((i - 29) * 30), 415 };
		}
		_isSelect7[i] = false;
	}
	for (int i = 0; i < 31; ++i)
	{
		if (0 <= i && i < 5)
		{
			_8mon[i] = { (float)371 + (i * 30), 320, (float)391 + (i * 30), 335 };
		}
		else if (5 <= i && i < 12)
		{
			_8mon[i] = { (float)311 + ((i - 5) * 30), 336, (float)331 + ((i - 5) * 30), 351 };

		}
		else if (12 <= i && i < 19)
		{
			_8mon[i] = { (float)311 + ((i - 12) * 30), 352, (float)331 + ((i - 12) * 30), 367 };

		}
		else if (19 <= i && i < 26)
		{
			_8mon[i] = { (float)311 + ((i - 19) * 30), 368, (float)331 + ((i - 19) * 30), 383 };
		}
		else
		{
			_8mon[i] = { (float)311 + ((i - 26) * 30), 384, (float)331 + ((i - 26) * 30), 399 };
		}
		_isSelect8[i] = false;
	}

	for (int i = 0; i < 30; ++i)
	{
		if (0 <= i && i < 2)
		{
			_9mon[i] = { (float)711 + (i * 30), 320, (float)731 + (i * 30), 335 };
		}
		else if (2 <= i && i < 9)
		{
			_9mon[i] = { (float)561 + ((i - 2) * 30), 336, (float)581 + ((i - 2) * 30), 351 };
		}
		else if (9 <= i && i < 16)
		{
			_9mon[i] = { (float)561 + ((i - 9) * 30), 352, (float)581 + ((i - 9) * 30), 367 };

		}
		else if (16 <= i && i < 23)
		{
			_9mon[i] = { (float)561 + ((i - 16) * 30), 368, (float)581 + ((i - 16) * 30), 383 };

		}
		else
		{

			_9mon[i] = { (float)561 + ((i - 23) * 30), 384, (float)581 + ((i - 23) * 30), 399 };
		}
		_isSelect9[i] = false;
	}
	for (int i = 0; i < 31; ++i)
	{
		if (0 <= i && i < 7)
		{
			_10mon[i] = { (float)61 + (i * 30), 428, (float)81 + (i * 30), 443 };
		}
		else if (7 <= i && i < 14)
		{
			_10mon[i] = { (float)61 + ((i - 7) * 30), 444, (float)81 + ((i - 7) * 30), 459 };
		}
		else if (14 <= i && i < 21)
		{
			_10mon[i] = { (float)61 + ((i - 14) * 30), 460, (float)81 + ((i - 14) * 30), 475 };
		}
		else if (21 <= i && i < 28)
		{
			_10mon[i] = { (float)61 + ((i - 21) * 30), 476, (float)81 + ((i - 21) * 30), 491 };
		}
		else
		{
			_10mon[i] = { (float)61 + ((i - 28) * 30), 492, (float)81 + ((i - 28) * 30), 507 };
		}
		_isSelect10[i] = false;
	}
	for (int i = 0; i < 30; ++i)
	{
		if (0 <= i && i < 4)
		{
			_11mon[i] = { (float)401 + (i * 30), 428, (float)421 + (i * 30), 443 };
		}
		else if (4 <= i && i < 11)
		{
			_11mon[i] = { (float)311 + ((i - 4) * 30), 444, (float)331 + ((i - 4) * 30), 459 };
		}
		else if (11 <= i && i < 18)
		{
			_11mon[i] = { (float)311 + ((i - 11) * 30), 460, (float)331 + ((i - 11) * 30), 475 };

		}
		else if (18 <= i && i < 25)
		{
			_11mon[i] = { (float)311 + ((i - 18) * 30), 476, (float)331 + ((i - 18) * 30), 491 };

		}
		else
		{
			_11mon[i] = { (float)311 + ((i - 25) * 30), 492, (float)331 + ((i - 25) * 30), 507 };

		}
		_isSelect11[i] = false;
	}

	for (int i = 0; i < 31; ++i)
	{
		if (0 <= i && i < 2)
		{
			_12mon[i] = { (float)711 + (i * 30), 428, (float)731 + (i * 30), 443 };
		}
		else if (2 <= i && i < 9)
		{
			_12mon[i] = { (float)561 + ((i - 2) * 30), 444, (float)581 + ((i - 2) * 30), 459 };
		}
		else if (9 <= i && i < 16)
		{
			_12mon[i] = { (float)561 + ((i - 9) * 30), 460, (float)581 + ((i - 9) * 30), 475 };
		}
		else if (16 <= i && i < 23)
		{
			_12mon[i] = { (float)561 + ((i - 16) * 30), 476, (float)581 + ((i - 16) * 30), 491 };
		}
		else if (23 <= i && i < 30)
		{
			_12mon[i] = { (float)561 + ((i - 23) * 30), 492, (float)581 + ((i - 23) * 30), 507 };
		}
		else
		{
			_12mon[i] = { (float)561 + ((i - 30) * 30), 508, (float)581 + ((i - 30) * 30), 523 };
		}
		_isSelect12[i] = false;
	}
}

void newPlayerScene::BrithDayCalendarSelect()
{
	for (int i = 0; i < 31; ++i)
	{
		if (PtInD2D1Rect(_1mon[i], _ptMouse))
		{
			_isSelect[i] = true;

			_princessInfo.year = 1200;
			_princessInfo.mon = 1;
			_princessInfo.day = i + 1;
			_princessInfo.age = 10;
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
	for (int i = 0; i < 29; ++i)
	{
		if (PtInD2D1Rect(_2mon[i], _ptMouse))
		{
			_isSelect2[i] = true;

			_princessInfo.year = 1200;
			_princessInfo.mon = 2;
			_princessInfo.day = i + 1;
			_princessInfo.age = 10;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_princessInfo.year = 1200;
				_princessInfo.mon = 2;
				_princessInfo.day = i + 1;
				_princessInfo.age = 10;
			}
		}
		else
		{
			_isSelect2[i] = false;
		}
	}
	for (int i = 0; i < 31; ++i)
	{
		if (PtInD2D1Rect(_3mon[i], _ptMouse))
		{
			_isSelect3[i] = true;
			_princessInfo.year = 1200;
			_princessInfo.mon = 3;
			_princessInfo.day = i + 1;
			_princessInfo.age = 10;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_princessInfo.year = 1200;
				_princessInfo.mon = 3;
				_princessInfo.day = i + 1;
				_princessInfo.age = 10;

				_nState = NEW_FATHER_AGE_SELECT;
			}
		}
		else
		{
			_isSelect3[i] = false;
		}
	}
	for (int i = 0; i < 30; ++i)
	{
		if (PtInD2D1Rect(_4mon[i], _ptMouse))
		{
			_isSelect4[i] = true;
			_princessInfo.year = 1200;
			_princessInfo.mon = 4;
			_princessInfo.day = i + 1;
			_princessInfo.age = 10;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_princessInfo.year = 1200;
				_princessInfo.mon = 4;
				_princessInfo.day = i + 1;
				_princessInfo.age = 10;

				_nState = NEW_FATHER_AGE_SELECT;
			}
		}
		else
		{
			_isSelect4[i] = false;
		}
	}
	for (int i = 0; i < 31; ++i)
	{
		if (PtInD2D1Rect(_5mon[i], _ptMouse))
		{
			_isSelect5[i] = true;
			_princessInfo.year = 1200;
			_princessInfo.mon = 5;
			_princessInfo.day = i + 1;
			_princessInfo.age = 10;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_princessInfo.year = 1200;
				_princessInfo.mon = 5;
				_princessInfo.day = i + 1;
				_princessInfo.age = 10;

				_nState = NEW_FATHER_AGE_SELECT;
			}
		}
		else
		{
			_isSelect5[i] = false;
		}
	}
	for (int i = 0; i < 30; ++i)
	{
		if (PtInD2D1Rect(_6mon[i], _ptMouse))
		{
			_isSelect6[i] = true;
			_princessInfo.year = 1200;
			_princessInfo.mon = 6;
			_princessInfo.day = i + 1;
			_princessInfo.age = 10;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_princessInfo.year = 1200;
				_princessInfo.mon = 6;
				_princessInfo.day = i + 1;
				_princessInfo.age = 10;
				_nState = NEW_FATHER_AGE_SELECT;
			}
		}
		else
		{
			_isSelect6[i] = false;
		}
	}
	for (int i = 0; i < 31; ++i)
	{
		if (PtInD2D1Rect(_7mon[i], _ptMouse))
		{
			_isSelect7[i] = true;
			_princessInfo.year = 1200;
			_princessInfo.mon = 7;
			_princessInfo.day = i + 1;
			_princessInfo.age = 10;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_princessInfo.year = 1200;
				_princessInfo.mon = 7;
				_princessInfo.day = i + 1;
				_princessInfo.age = 10;
				_nState = NEW_FATHER_AGE_SELECT;
			}
		}
		else
		{
			_isSelect7[i] = false;
		}
	}
	for (int i = 0; i < 31; ++i)
	{
		if (PtInD2D1Rect(_8mon[i], _ptMouse))
		{
			_isSelect8[i] = true;
			_princessInfo.year = 1200;
			_princessInfo.mon = 8;
			_princessInfo.day = i + 1;
			_princessInfo.age = 10;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_princessInfo.year = 1200;
				_princessInfo.mon = 8;
				_princessInfo.day = i + 1;
				_princessInfo.age = 10;
				_nState = NEW_FATHER_AGE_SELECT;
			}
		}
		else
		{
			_isSelect8[i] = false;
		}
	}
	for (int i = 0; i < 30; ++i)
	{
		if (PtInD2D1Rect(_9mon[i], _ptMouse))
		{
			_isSelect9[i] = true;
			_princessInfo.year = 1200;
			_princessInfo.mon = 9;
			_princessInfo.day = i + 1;
			_princessInfo.age = 10;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_princessInfo.year = 1200;
				_princessInfo.mon = 9;
				_princessInfo.day = i + 1;
				_princessInfo.age = 10;
				_nState = NEW_FATHER_AGE_SELECT;
			}
		}
		else
		{
			_isSelect9[i] = false;
		}
	}
	for (int i = 0; i < 31; ++i)
	{
		if (PtInD2D1Rect(_10mon[i], _ptMouse))
		{
			_isSelect10[i] = true;
			_princessInfo.year = 1200;
			_princessInfo.mon = 10;
			_princessInfo.day = i + 1;
			_princessInfo.age = 10;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_princessInfo.year = 1200;
				_princessInfo.mon = 10;
				_princessInfo.day = i + 1;
				_princessInfo.age = 10;
				_nState = NEW_FATHER_AGE_SELECT;
			}
		}
		else
		{
			_isSelect10[i] = false;
		}
	}
	for (int i = 0; i < 30; ++i)
	{
		if (PtInD2D1Rect(_11mon[i], _ptMouse))
		{
			_isSelect11[i] = true;
			_princessInfo.year = 1200;
			_princessInfo.mon = 11;
			_princessInfo.day = i + 1;
			_princessInfo.age = 10;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_princessInfo.year = 1200;
				_princessInfo.mon = 11;
				_princessInfo.day = i + 1;
				_princessInfo.age = 10;
				_nState = NEW_FATHER_AGE_SELECT;
			}
		}
		else
		{
			_isSelect11[i] = false;
		}
	}
	for (int i = 0; i < 31; ++i)
	{
		if (PtInD2D1Rect(_12mon[i], _ptMouse))
		{
			_isSelect12[i] = true;
			_princessInfo.year = 1200;
			_princessInfo.mon = 12;
			_princessInfo.day = i + 1;
			_princessInfo.age = 10;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_princessInfo.year = 1200;
				_princessInfo.mon = 12;
				_princessInfo.day = i + 1;
				_princessInfo.age = 10;
				_nState = NEW_FATHER_AGE_SELECT;
			}
		}
		else
		{
			_isSelect12[i] = false;
		}
	}
}

void newPlayerScene::BrithDayCalendarSelect2()
{

	for (int i = 0; i < 31; ++i)
	{
		if (PtInD2D1Rect(_1mon[i], _ptMouse))
		{
			_isSelect[i] = true;
			_fatherYear = 1200 - _fatherage + 1;
			_fathermon = 1;
			_fatherday = i + 1;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_fatherYear = 1200 - _fatherage + 1;
				_fathermon = 1;
				_fatherday = i + 1;
				_nState = NEW_DAUGTHER_BTYPE_SELECT;
			}
		}
		else
		{
			_isSelect[i] = false;
		}
	}
	for (int i = 0; i < 29; ++i)
	{
		if (PtInD2D1Rect(_2mon[i], _ptMouse))
		{
			_isSelect2[i] = true;
			_fatherYear = 1200 - _fatherage + 1;
			_fathermon = 2;
			_fatherday = i + 1;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_fatherYear = 1200 - _fatherage + 1;
				_fathermon = 2;
				_fatherday = i + 1;
				_nState = NEW_DAUGTHER_BTYPE_SELECT;
			}
		}
		else
		{
			_isSelect2[i] = false;
		}
	}
	for (int i = 0; i < 31; ++i)
	{
		if (PtInD2D1Rect(_3mon[i], _ptMouse))
		{
			_isSelect3[i] = true;
			_fatherYear = 1200 - _fatherage + 1;
			_fathermon = 3;
			_fatherday = i + 1;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_fatherYear = 1200 - _fatherage + 1;
				_fathermon = 3;
				_fatherday = i + 1;
				_nState = NEW_DAUGTHER_BTYPE_SELECT;
			}
		}
		else
		{
			_isSelect3[i] = false;
		}
	}
	for (int i = 0; i < 30; ++i)
	{
		if (PtInD2D1Rect(_4mon[i], _ptMouse))
		{
			_isSelect4[i] = true;
			_fatherYear = 1200 - _fatherage + 1;
			_fathermon = 4;
			_fatherday = i + 1;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_fatherYear = 1200 - _fatherage + 1;
				_fathermon = 4;
				_fatherday = i + 1;
				_nState = NEW_DAUGTHER_BTYPE_SELECT;
			}
		}
		else
		{
			_isSelect4[i] = false;
		}
	}
	for (int i = 0; i < 31; ++i)
	{
		if (PtInD2D1Rect(_5mon[i], _ptMouse))
		{
			_isSelect5[i] = true;
			_fatherYear = 1200 - _fatherage + 1;
			_fathermon = 5;
			_fatherday = i + 1;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_fatherYear = 1200 - _fatherage + 1;
				_fathermon = 5;
				_fatherday = i + 1;
				_nState = NEW_DAUGTHER_BTYPE_SELECT;
			}
		}
		else
		{
			_isSelect5[i] = false;
		}
	}
	for (int i = 0; i < 30; ++i)
	{
		if (PtInD2D1Rect(_6mon[i], _ptMouse))
		{
			_isSelect6[i] = true;
			_fatherYear = 1200 - _fatherage + 1;
			_fathermon = 6;
			_fatherday = i + 1;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_fatherYear = 1200 - _fatherage + 1;
				_fathermon = 6;
				_fatherday = i + 1;
				_nState = NEW_DAUGTHER_BTYPE_SELECT;
			}
		}
		else
		{
			_isSelect6[i] = false;
		}
	}
	for (int i = 0; i < 31; ++i)
	{
		if (PtInD2D1Rect(_7mon[i], _ptMouse))
		{
			_isSelect7[i] = true;
			_fatherYear = 1200 - _fatherage + 1;
			_fathermon = 7;
			_fatherday = i + 1;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_fatherYear = 1200 - _fatherage + 1;
				_fathermon = 7;
				_fatherday = i + 1;
				_nState = NEW_DAUGTHER_BTYPE_SELECT;
			}
		}
		else
		{
			_isSelect7[i] = false;
		}
	}
	for (int i = 0; i < 31; ++i)
	{
		if (PtInD2D1Rect(_8mon[i], _ptMouse))
		{
			_isSelect8[i] = true;
			_fatherYear = 1200 - _fatherage + 1;
			_fathermon = 8;
			_fatherday = i + 1;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_fatherYear = 1200 - _fatherage + 1;
				_fathermon = 8;
				_fatherday = i + 1;
				_nState = NEW_DAUGTHER_BTYPE_SELECT;
			}
		}
		else
		{
			_isSelect8[i] = false;
		}
	}
	for (int i = 0; i < 30; ++i)
	{
		if (PtInD2D1Rect(_9mon[i], _ptMouse))
		{
			_isSelect9[i] = true;
			_fatherYear = 1200 - _fatherage + 1;
			_fathermon = 9;
			_fatherday = i + 1;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_fatherYear = 1200 - _fatherage + 1;
				_fathermon = 9;
				_fatherday = i + 1;
				_nState = NEW_DAUGTHER_BTYPE_SELECT;
			}
		}
		else
		{
			_isSelect9[i] = false;
		}
	}
	for (int i = 0; i < 31; ++i)
	{
		if (PtInD2D1Rect(_10mon[i], _ptMouse))
		{
			_isSelect10[i] = true;
			_fatherYear = 1200 - _fatherage + 1;
			_fathermon = 10;
			_fatherday = i + 1;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_fatherYear = 1200 - _fatherage + 1;
				_fathermon = 10;
				_fatherday = i + 1;
				_nState = NEW_DAUGTHER_BTYPE_SELECT;
			}
		}
		else
		{
			_isSelect10[i] = false;
		}
	}
	for (int i = 0; i < 30; ++i)
	{
		if (PtInD2D1Rect(_11mon[i], _ptMouse))
		{
			_isSelect11[i] = true;
			_fatherYear = 1200 - _fatherage + 1;
			_fathermon = 11;
			_fatherday = i + 1;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_fatherYear = 1200 - _fatherage + 1;
				_fathermon = 11;
				_fatherday = i + 1;
				_nState = NEW_DAUGTHER_BTYPE_SELECT;
			}
		}
		else
		{
			_isSelect11[i] = false;
		}
	}
	for (int i = 0; i < 31; ++i)
	{
		if (PtInD2D1Rect(_12mon[i], _ptMouse))
		{
			_isSelect12[i] = true;
			_fatherYear = 1200 - _fatherage + 1;
			_fathermon = 12;
			_fatherday = i + 1;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_fatherYear = 1200 - _fatherage + 1;
				_fathermon = 12;
				_fatherday = i + 1;
				_nState = NEW_DAUGTHER_BTYPE_SELECT;
			}
		}
		else
		{
			_isSelect12[i] = false;
		}
	}
}

void newPlayerScene::statusSetting()
{
	switch (_princessInfo.mon)
	{
	case 1:
		if (_princessInfo.day <= 19)
			_princessStatus.Guardian.constellation = "염소자리";
		else
			_princessStatus.Guardian.constellation = "물병자리";
		break;
	case 2:
		if (_princessInfo.day <= 18)
			_princessStatus.Guardian.constellation = "물병자리";
		else
			_princessStatus.Guardian.constellation = "물고기자리";
		break;
	case 3:
		if (_princessInfo.day <= 20)
			_princessStatus.Guardian.constellation = "물고기자리";
		else
			_princessStatus.Guardian.constellation = "양자리";
		break;
	case 4:
		if (_princessInfo.day <= 19)
			_princessStatus.Guardian.constellation = "양자리";
		else
			_princessStatus.Guardian.constellation = "황소자리";
		break;
	case 5:
		if (_princessInfo.day <= 20)
			_princessStatus.Guardian.constellation = "황소자리";
		else
			_princessStatus.Guardian.constellation = "쌍둥이자리";
		break;
	case 6:
		if (_princessInfo.day <= 21)
			_princessStatus.Guardian.constellation = "쌍둥이자리";
		else
			_princessStatus.Guardian.constellation = "게자리";
		break;
	case 7:
		if (_princessInfo.day <= 22)
			_princessStatus.Guardian.constellation = "게자리";
		else
			_princessStatus.Guardian.constellation = "사자자리";
		break;
	case 8:
		if (_princessInfo.day <= 22)
			_princessStatus.Guardian.constellation = "사자자리";
		else
			_princessStatus.Guardian.constellation = "처녀자리";
		break;
	case 9:
		if (_princessInfo.day <= 22)
			_princessStatus.Guardian.constellation = "처녀자리";
		else
			_princessStatus.Guardian.constellation = "천칭자리";
		break;
	case 10:
		if (_princessInfo.day <= 23)
			_princessStatus.Guardian.constellation = "천칭자리";
		else
			_princessStatus.Guardian.constellation = "전갈자리";
		break;
	case 11:
		if (_princessInfo.day <= 22)
			_princessStatus.Guardian.constellation = "전갈자리";
		else
			_princessStatus.Guardian.constellation = "사수자리";
		break;
	case 12:
		if (_princessInfo.day <= 21)
			_princessStatus.Guardian.constellation = "사수자리";
		else
			_princessStatus.Guardian.constellation = "염소자리";
		break;
	}
	vector<string> vStr = TXTDATA->txtLoadCsv("data/status.csv", _princessStatus.Guardian.constellation.c_str());

	_princessStatus.Guardian.planet = vStr[0];
	_princessStatus.Guardian.name = vStr[1];

	_princessStatus.hp = atoi(vStr[3].c_str());
	_princessStatus.muscular_strength = atoi(vStr[4].c_str());
	_princessStatus.intelligence = atoi(vStr[5].c_str());
	_princessStatus.elegance = atoi(vStr[6].c_str());
	_princessStatus.charm = atoi(vStr[7].c_str());
	_princessStatus.morality = atoi(vStr[8].c_str());
	_princessStatus.faith = atoi(vStr[9].c_str());
	_princessStatus.sensitivity = atoi(vStr[10].c_str());

	_princessStatus.warrior_appraisal = atoi(vStr[11].c_str());
	_princessStatus.cambat_skill = atoi(vStr[12].c_str());
	_princessStatus.attk_power = atoi(vStr[13].c_str());
	_princessStatus.magic_appraisal = atoi(vStr[14].c_str());
	_princessStatus.magic_skill = atoi(vStr[15].c_str());
	_princessStatus.magic_power = atoi(vStr[16].c_str());
	_princessStatus.magicdef_power = atoi(vStr[17].c_str());

	_princessStatus.sociable_appraisal = atoi(vStr[18].c_str());
	_princessStatus.etiquette = atoi(vStr[19].c_str());
	_princessStatus.art = atoi(vStr[20].c_str());
	_princessStatus.talking_sense = atoi(vStr[21].c_str());

	_princessStatus.housework_appraisal = atoi(vStr[22].c_str());
	_princessStatus.cooking = atoi(vStr[23].c_str());
	_princessStatus.cleaning = atoi(vStr[24].c_str());
	_princessStatus.charactre = atoi(vStr[25].c_str());

	_princessStatus.total = atoi(vStr[26].c_str());
}

void newPlayerScene::BrithDayCalendarRender()
{
	WCHAR newplayer[1024];
	for (int i = 0; i < 31; ++i)
	{
		if (_isSelect[i])
		{
			if (_nState == NEW_DAUGHTER_BRIT_SELECT)
			{
				IMAGEMANAGER->findImage("딸생일선택")->frameRender(_1mon[i].left, _1mon[i].top, 0, i);
				swprintf_s(newplayer, L"%d", _princessInfo.year);
				D2DMANAGER->drawText(newplayer, 38, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _princessInfo.mon);
				D2DMANAGER->drawText(newplayer, 88, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _princessInfo.day);
				D2DMANAGER->drawText(newplayer, 113, 73, 14, RGB(255, 255, 255));
			}
			if (_nState == NEW_FATHER_BRIT_SELECT)
			{
				IMAGEMANAGER->findImage("아빠생일선택")->frameRender(_1mon[i].left, _1mon[i].top, 0, i);
				swprintf_s(newplayer, L"%d", _fatherYear);
				D2DMANAGER->drawText(newplayer, 38, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _fathermon);
				D2DMANAGER->drawText(newplayer, 88, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _fatherday);
				D2DMANAGER->drawText(newplayer, 113, 73, 14, RGB(255, 255, 255));
			}
		}
		if (_isSelect3[i])
		{
			if (_nState == NEW_DAUGHTER_BRIT_SELECT)
			{
				IMAGEMANAGER->findImage("딸생일선택")->frameRender(_3mon[i].left, _3mon[i].top, 0, i);
				swprintf_s(newplayer, L"%d", _princessInfo.year);
				D2DMANAGER->drawText(newplayer, 38, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _princessInfo.mon);
				D2DMANAGER->drawText(newplayer, 88, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _princessInfo.day);
				D2DMANAGER->drawText(newplayer, 113, 73, 14, RGB(255, 255, 255));
			}
			

			if (_nState == NEW_FATHER_BRIT_SELECT)
			{
				IMAGEMANAGER->findImage("아빠생일선택")->frameRender(_3mon[i].left, _3mon[i].top, 0, i);
				swprintf_s(newplayer, L"%d", _fatherYear);
				D2DMANAGER->drawText(newplayer, 38, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _fathermon);
				D2DMANAGER->drawText(newplayer, 88, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _fatherday);
				D2DMANAGER->drawText(newplayer, 113, 73, 14, RGB(255, 255, 255));
			}
		}
		if (_isSelect5[i])
		{
			if (_nState == NEW_DAUGHTER_BRIT_SELECT)
			{
				IMAGEMANAGER->findImage("딸생일선택")->frameRender(_5mon[i].left, _5mon[i].top, 0, i);
				swprintf_s(newplayer, L"%d", _princessInfo.year);
				D2DMANAGER->drawText(newplayer, 38, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _princessInfo.mon);
				D2DMANAGER->drawText(newplayer, 88, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _princessInfo.day);
				D2DMANAGER->drawText(newplayer, 113, 73, 14, RGB(255, 255, 255));
			}
			

			if (_nState == NEW_FATHER_BRIT_SELECT)
			{
				IMAGEMANAGER->findImage("아빠생일선택")->frameRender(_5mon[i].left, _5mon[i].top, 0, i);
				swprintf_s(newplayer, L"%d", _fatherYear);
				D2DMANAGER->drawText(newplayer, 38, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _fathermon);
				D2DMANAGER->drawText(newplayer, 88, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _fatherday);
				D2DMANAGER->drawText(newplayer, 113, 73, 14, RGB(255, 255, 255));
			}
		}
		if (_isSelect7[i])
		{
			if (_nState == NEW_DAUGHTER_BRIT_SELECT)
			{
				IMAGEMANAGER->findImage("딸생일선택")->frameRender(_7mon[i].left, _7mon[i].top, 0, i);
				swprintf_s(newplayer, L"%d", _princessInfo.year);
				D2DMANAGER->drawText(newplayer, 38, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _princessInfo.mon);
				D2DMANAGER->drawText(newplayer, 88, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _princessInfo.day);
				D2DMANAGER->drawText(newplayer, 113, 73, 14, RGB(255, 255, 255));
			}
			

			if (_nState == NEW_FATHER_BRIT_SELECT)
			{
				IMAGEMANAGER->findImage("아빠생일선택")->frameRender(_7mon[i].left, _7mon[i].top, 0, i);
				swprintf_s(newplayer, L"%d", _fatherYear);
				D2DMANAGER->drawText(newplayer, 38, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _fathermon);
				D2DMANAGER->drawText(newplayer, 88, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _fatherday);
				D2DMANAGER->drawText(newplayer, 113, 73, 14, RGB(255, 255, 255));
			}
		}
		if (_isSelect8[i])
		{
			if (_nState == NEW_DAUGHTER_BRIT_SELECT)
			{
				IMAGEMANAGER->findImage("딸생일선택")->frameRender(_8mon[i].left, _8mon[i].top, 0, i);
				swprintf_s(newplayer, L"%d", _princessInfo.year);
				D2DMANAGER->drawText(newplayer, 38, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _princessInfo.mon);
				D2DMANAGER->drawText(newplayer, 88, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _princessInfo.day);
				D2DMANAGER->drawText(newplayer, 113, 73, 14, RGB(255, 255, 255));
			}
			

			if (_nState == NEW_FATHER_BRIT_SELECT)
			{
				IMAGEMANAGER->findImage("아빠생일선택")->frameRender(_8mon[i].left, _8mon[i].top, 0, i);
				swprintf_s(newplayer, L"%d", _fatherYear);
				D2DMANAGER->drawText(newplayer, 38, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _fathermon);
				D2DMANAGER->drawText(newplayer, 88, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _fatherday);
				D2DMANAGER->drawText(newplayer, 113, 73, 14, RGB(255, 255, 255));
			}
		}
		if (_isSelect10[i])
		{
			if (_nState == NEW_DAUGHTER_BRIT_SELECT)
			{
				IMAGEMANAGER->findImage("딸생일선택")->frameRender(_10mon[i].left, _10mon[i].top, 0, i);
				swprintf_s(newplayer, L"%d", _princessInfo.year);
				D2DMANAGER->drawText(newplayer, 38, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _princessInfo.mon);
				D2DMANAGER->drawText(newplayer, 88, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _princessInfo.day);
				D2DMANAGER->drawText(newplayer, 113, 73, 14, RGB(255, 255, 255));
			}
			

			if (_nState == NEW_FATHER_BRIT_SELECT)
			{
				IMAGEMANAGER->findImage("아빠생일선택")->frameRender(_10mon[i].left, _10mon[i].top, 0, i);
				swprintf_s(newplayer, L"%d", _fatherYear);
				D2DMANAGER->drawText(newplayer, 38, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _fathermon);
				D2DMANAGER->drawText(newplayer, 88, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _fatherday);
				D2DMANAGER->drawText(newplayer, 113, 73, 14, RGB(255, 255, 255));
			}
		}
		if (_isSelect12[i])
		{
			if (_nState == NEW_DAUGHTER_BRIT_SELECT)
			{
				IMAGEMANAGER->findImage("딸생일선택")->frameRender(_12mon[i].left, _12mon[i].top, 0, i);
				swprintf_s(newplayer, L"%d", _princessInfo.year);
				D2DMANAGER->drawText(newplayer, 38, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _princessInfo.mon);
				D2DMANAGER->drawText(newplayer, 88, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _princessInfo.day);
				D2DMANAGER->drawText(newplayer, 113, 73, 14, RGB(255, 255, 255));
			}
			
			if (_nState == NEW_FATHER_BRIT_SELECT)
			{
				IMAGEMANAGER->findImage("아빠생일선택")->frameRender(_12mon[i].left, _12mon[i].top, 0, i);
				swprintf_s(newplayer, L"%d", _fatherYear);
				D2DMANAGER->drawText(newplayer, 38, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _fathermon);
				D2DMANAGER->drawText(newplayer, 88, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _fatherday);
				D2DMANAGER->drawText(newplayer, 113, 73, 14, RGB(255, 255, 255));
			}
		}
	}
	for (int i = 0; i < 29; ++i)
	{
		if (_isSelect2[i])
		{
			if (_nState == NEW_DAUGHTER_BRIT_SELECT)
			{
				IMAGEMANAGER->findImage("딸생일선택")->frameRender(_2mon[i].left, _2mon[i].top, 0, i);
				swprintf_s(newplayer, L"%d", _princessInfo.year);
				D2DMANAGER->drawText(newplayer, 38, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _princessInfo.mon);
				D2DMANAGER->drawText(newplayer, 88, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _princessInfo.day);
				D2DMANAGER->drawText(newplayer, 113, 73, 14, RGB(255, 255, 255));
			}
			
			if (_nState == NEW_FATHER_BRIT_SELECT)
			{
				IMAGEMANAGER->findImage("아빠생일선택")->frameRender(_2mon[i].left, _2mon[i].top, 0, i);
				swprintf_s(newplayer, L"%d", _fatherYear);
				D2DMANAGER->drawText(newplayer, 38, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _fathermon);
				D2DMANAGER->drawText(newplayer, 88, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _fatherday);
				D2DMANAGER->drawText(newplayer, 113, 73, 14, RGB(255, 255, 255));
			}
		}
	}
	for (int i = 0; i < 30; ++i)
	{
		if (_isSelect4[i])
		{
			if (_nState == NEW_DAUGHTER_BRIT_SELECT) 
			{
				IMAGEMANAGER->findImage("딸생일선택")->frameRender(_4mon[i].left, _4mon[i].top, 0, i);
				swprintf_s(newplayer, L"%d", _princessInfo.year);
				D2DMANAGER->drawText(newplayer, 38, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _princessInfo.mon);
				D2DMANAGER->drawText(newplayer, 88, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _princessInfo.day);
				D2DMANAGER->drawText(newplayer, 113, 73, 14, RGB(255, 255, 255));
			}
			
			if (_nState == NEW_FATHER_BRIT_SELECT)
			{
				IMAGEMANAGER->findImage("아빠생일선택")->frameRender(_4mon[i].left, _4mon[i].top, 0, i);
				swprintf_s(newplayer, L"%d", _fatherYear);
				D2DMANAGER->drawText(newplayer, 38, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _fathermon);
				D2DMANAGER->drawText(newplayer, 88, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _fatherday);
				D2DMANAGER->drawText(newplayer, 113, 73, 14, RGB(255, 255, 255));
			}
		}
		if (_isSelect6[i])
		{
			if (_nState == NEW_DAUGHTER_BRIT_SELECT)
			{
				IMAGEMANAGER->findImage("딸생일선택")->frameRender(_6mon[i].left, _6mon[i].top, 0, i);
				swprintf_s(newplayer, L"%d", _princessInfo.year);
				D2DMANAGER->drawText(newplayer, 38, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _princessInfo.mon);
				D2DMANAGER->drawText(newplayer, 88, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _princessInfo.day);
				D2DMANAGER->drawText(newplayer, 113, 73, 14, RGB(255, 255, 255));
			}
			
			if (_nState == NEW_FATHER_BRIT_SELECT)
			{
				IMAGEMANAGER->findImage("아빠생일선택")->frameRender(_6mon[i].left, _6mon[i].top, 0, i);
				swprintf_s(newplayer, L"%d", _fatherYear);
				D2DMANAGER->drawText(newplayer, 38, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _fathermon);
				D2DMANAGER->drawText(newplayer, 88, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _fatherday);
				D2DMANAGER->drawText(newplayer, 113, 73, 14, RGB(255, 255, 255));
			}
		}
		if (_isSelect9[i])
		{
			if (_nState == NEW_DAUGHTER_BRIT_SELECT)
			{
				IMAGEMANAGER->findImage("딸생일선택")->frameRender(_9mon[i].left, _9mon[i].top, 0, i);
				swprintf_s(newplayer, L"%d", _princessInfo.year);
				D2DMANAGER->drawText(newplayer, 38, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _princessInfo.mon);
				D2DMANAGER->drawText(newplayer, 88, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _princessInfo.day);
				D2DMANAGER->drawText(newplayer, 113, 73, 14, RGB(255, 255, 255));
			}
			

			if (_nState == NEW_FATHER_BRIT_SELECT)
			{
				IMAGEMANAGER->findImage("아빠생일선택")->frameRender(_9mon[i].left, _9mon[i].top, 0, i);
				swprintf_s(newplayer, L"%d", _fatherYear);
				D2DMANAGER->drawText(newplayer, 38, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _fathermon);
				D2DMANAGER->drawText(newplayer, 88, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _fatherday);
				D2DMANAGER->drawText(newplayer, 113, 73, 14, RGB(255, 255, 255));
			}
		}
		if (_isSelect11[i])
		{
			if (_nState == NEW_DAUGHTER_BRIT_SELECT)
			{
				IMAGEMANAGER->findImage("딸생일선택")->frameRender(_11mon[i].left, _11mon[i].top, 0, i);
				swprintf_s(newplayer, L"%d", _princessInfo.year);
				D2DMANAGER->drawText(newplayer, 38, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _princessInfo.mon);
				D2DMANAGER->drawText(newplayer, 88, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _princessInfo.day);
				D2DMANAGER->drawText(newplayer, 113, 73, 14, RGB(255, 255, 255));
			}
			

			if (_nState == NEW_FATHER_BRIT_SELECT)
			{
				IMAGEMANAGER->findImage("아빠생일선택")->frameRender(_11mon[i].left, _11mon[i].top, 0, i);
				swprintf_s(newplayer, L"%d", _fatherYear);
				D2DMANAGER->drawText(newplayer, 38, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _fathermon);
				D2DMANAGER->drawText(newplayer, 88, 73, 14, RGB(255, 255, 255));
				swprintf_s(newplayer, L"%d", _fatherday);
				D2DMANAGER->drawText(newplayer, 113, 73, 14, RGB(255, 255, 255));
			}
		}
	}
}

void newPlayerScene::dataSetting()
{

}
