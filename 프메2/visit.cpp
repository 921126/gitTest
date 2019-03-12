#include "stdafx.h"
#include "visit.h"


visit::visit()
{
}

visit::~visit()
{
}

HRESULT visit::init()
{
	_vState = V_SELECT_NONE;
	_ptChek = V_PT_NONE;
	FRAMEMANAGER->addFrame("방문하기", 600, 240, 6, 16);
	FRAMEMANAGER->addFrame("성방문01", 175, 370, 25, 8);
	FRAMEMANAGER->addFrame("성방문02", 200, 370, 20, 8);
	FRAMEMANAGER->addFrame("성방문03", 250, 370, 20, 8);

	//선택상자
	{
		for (int i = 0; i < 10; ++i)
		{
			_selectRc[i] = { 605, (float)260 + (i * 25), 703, (float)285 + (i * 25) };
		}
	}
	_isVisit = false;

	return S_OK;
}

void visit::release()
{
}

void visit::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		UIMANAGER->moveBeforeUI();
	}

	if (_ptChek == V_PT_NONE)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_isVisit = true;
		}
	}
	if (_isVisit)
	{
		if (PtInD2D1Rect(_selectRc[0], _ptMouse))
		{
			_ptChek = V_PT_1;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_vState = V_SELECT_GUARD;
				_isVisit = false;
			}
		}
		else if (PtInD2D1Rect(_selectRc[1], _ptMouse))
		{
			_ptChek = V_PT_2;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_vState = V_SELECT_KNIGHT;
			}
		}
		else if (PtInD2D1Rect(_selectRc[2], _ptMouse))
		{
			_ptChek = V_PT_3;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_vState = V_SELECT_GENERAL;
			}
		}
		else if (PtInD2D1Rect(_selectRc[3], _ptMouse))
		{
			_ptChek = V_PT_4;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_vState = V_SELECT_MINISTER;
			}
		}
		else if (PtInD2D1Rect(_selectRc[4], _ptMouse))
		{
			_ptChek = V_PT_5;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_vState = V_SELECT_BISHOP;
			}
		}
		else if (PtInD2D1Rect(_selectRc[5], _ptMouse))
		{
			_ptChek = V_PT_6;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_vState = V_SELECT_CONCUBINE;
			}
		}
		else if (PtInD2D1Rect(_selectRc[6], _ptMouse))
		{
			_ptChek = V_PT_7;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_vState = V_SELECT_QUEEN;
			}
		}
		else if (PtInD2D1Rect(_selectRc[7], _ptMouse))
		{
			_ptChek = V_PT_8;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_vState = V_SELECT_KING;
			}
		}
		else if (PtInD2D1Rect(_selectRc[8], _ptMouse))
		{
			_ptChek = V_PT_9;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_vState = V_SELECT_CLOWN;
			}
		}
		else if (PtInD2D1Rect(_selectRc[9], _ptMouse))
		{
			_ptChek = V_PT_10;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_vState = V_SELECT_PRINCE;
			}
		}
		else
		{
			_ptChek = V_PT_NONE;
		}

	}
	// to do 각 만났을때 행동 넣기 ex) 광대 화술 40 이전에 만나면 개띠꺼움 
	switch (_vState)
	{
	case V_SELECT_GUARD:
		break;
	case V_SELECT_KNIGHT:
		break;
	case V_SELECT_GENERAL:
		break;
	case V_SELECT_MINISTER:
		break;
	case V_SELECT_BISHOP:
		break;
	case V_SELECT_CONCUBINE:
		break;
	case V_SELECT_QUEEN:
		break;
	case V_SELECT_KING:
		break;
	case V_SELECT_CLOWN:
		break;
	case V_SELECT_PRINCE:
		break;
	}
}

void visit::render()
{
	WCHAR visit[256];
	IMAGEMANAGER->findImage("성이미지")->render(35, 120);
	if (!_isVisit && _vState == V_SELECT_NONE)
	{
		FRAMEMANAGER->findMenuFrame("성방문01")->render("텍스트박스");

		swprintf_s(visit, L"성에 왔습니다.");
		D2DMANAGER->drawText(visit, 185, 380, 18, RGB(255, 255, 255));
	}
	else if(_isVisit)
	{
		FRAMEMANAGER->findMenuFrame("방문하기")->render("선택박스");
		FRAMEMANAGER->findMenuFrame("성방문02")->render("텍스트박스");
		IMAGEMANAGER->findImage("문지기")->render( 60, 370);
		swprintf_s(visit, L"왔구나. \n이번엔 누구를 만나려는 거냐?");
		D2DMANAGER->drawText(visit, 210, 380, 18, RGB(255, 255, 255));

		switch (_ptChek)
		{
		case V_PT_1:
			IMAGEMANAGER->findImage("선택중2")->render(_selectRc[0].left, _selectRc[0].top);
			break;
		case V_PT_2:
			IMAGEMANAGER->findImage("선택중2")->render(_selectRc[1].left, _selectRc[1].top);
			break;
		case V_PT_3:
			IMAGEMANAGER->findImage("선택중2")->render(_selectRc[2].left, _selectRc[2].top);
			break;
		case V_PT_4:
			IMAGEMANAGER->findImage("선택중2")->render(_selectRc[3].left, _selectRc[3].top);
			break;
		case V_PT_5:
			IMAGEMANAGER->findImage("선택중2")->render(_selectRc[4].left, _selectRc[4].top);
			break;
		case V_PT_6:
			IMAGEMANAGER->findImage("선택중2")->render(_selectRc[5].left, _selectRc[5].top);
			break;
		case V_PT_7:
			IMAGEMANAGER->findImage("선택중2")->render(_selectRc[6].left, _selectRc[6].top);
			break;
		case V_PT_8:
			IMAGEMANAGER->findImage("선택중2")->render(_selectRc[7].left, _selectRc[7].top);
			break;
		case V_PT_9:
			IMAGEMANAGER->findImage("선택중2")->render(_selectRc[8].left, _selectRc[8].top);
			break;
		case V_PT_10:
			IMAGEMANAGER->findImage("선택중2")->render(_selectRc[9].left, _selectRc[9].top);
			break;
		}

		//만날수있는 닝겐들

		swprintf_s(visit, L"문지기");
		D2DMANAGER->drawText(visit, 610, 260, 18, RGB(255, 255, 255));
		swprintf_s(visit, L"근위기사");
		D2DMANAGER->drawText(visit, 610, 285, 18, RGB(255, 255, 255));
		swprintf_s(visit, L"장군");
		D2DMANAGER->drawText(visit, 610, 310, 18, RGB(255, 255, 255));
		swprintf_s(visit, L"대신");
		D2DMANAGER->drawText(visit, 610, 335, 18, RGB(255, 255, 255));
		swprintf_s(visit, L"주교");
		D2DMANAGER->drawText(visit, 610, 360, 18, RGB(255, 255, 255));
		swprintf_s(visit, L"후궁");
		D2DMANAGER->drawText(visit, 610, 385, 18, RGB(255, 255, 255));
		swprintf_s(visit, L"왕비");
		D2DMANAGER->drawText(visit, 610, 410, 18, RGB(255, 255, 255));
		swprintf_s(visit, L"국왕");
		D2DMANAGER->drawText(visit, 610, 435, 18, RGB(255, 255, 255));
		swprintf_s(visit, L"광대");
		D2DMANAGER->drawText(visit, 610, 460, 18, RGB(255, 255, 255));
		swprintf_s(visit, L"청년무관");
		D2DMANAGER->drawText(visit, 610, 485, 18, RGB(255, 255, 255));
	}
	switch (_vState)
	{
	case V_SELECT_GUARD:
		FRAMEMANAGER->findMenuFrame("성방문03")->render("텍스트박스");
		IMAGEMANAGER->findImage("문지기")->render(60, 370);
		swprintf_s(visit, L"왔구나. \n이번엔 누구를 만나려는 거냐?");
		D2DMANAGER->drawText(visit, 210, 380, 18, RGB(255, 255, 255));
		break;
	case V_SELECT_KNIGHT:
		break;
	case V_SELECT_GENERAL:
		break;
	case V_SELECT_MINISTER:
		break;
	case V_SELECT_BISHOP:
		break;
	case V_SELECT_CONCUBINE:
		break;
	case V_SELECT_QUEEN:
		break;
	case V_SELECT_KING:
		break;
	case V_SELECT_CLOWN:
		break;
	case V_SELECT_PRINCE:
		break;
	}

	swprintf_s(visit, L"상태값요: %d", _vState);
	D2DMANAGER->drawText(visit, 300, 0, 18, RGB(255, 255, 255));
}

void visit::uiClose()
{
	_isVisit = false;
	_vState = V_SELECT_NONE;
	_ptChek = V_PT_NONE;
}
