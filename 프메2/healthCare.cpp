#include "stdafx.h"
#include "healthCare.h"


healthCare::healthCare()
{
}


healthCare::~healthCare()
{
}

HRESULT healthCare::init()
{
	_hBasice = H_B_NOSTRESS;
	_hState = H_SELECT_NONE;
	_hPtChek = H_PT_NONE;
	_hChange = H_CHANGE_NONE;

	_isThis = false; 
	_isNo	= false; 
	_iscomplete = false;

	FRAMEMANAGER->addFrame("건강선택", 600, 250, 10, 8);
	FRAMEMANAGER->addFrame("건강관리01", 20, 420, 20, 8);
	FRAMEMANAGER->addFrame("건강내용", 20, 300, 15, 2);
	FRAMEMANAGER->addFrame("결정", 600, 250, 10, 5);
	for (int i = 0; i < 4; ++i)
	{
		_selectRc[i] = { 605, (float)265 + (i * 30), 775, (float)295 + (i * 30) };
	}
	_changeRc[0] = { 605, 265, 775, 295 };
	_changeRc[1] = { 605, 295, 775, 325 };

	return S_OK;
}

void healthCare::release()
{
}

void healthCare::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		UIMANAGER->moveBeforeUI();
	}

	if (_hState == H_SELECT_NONE)
	{
		if (PtInD2D1Rect(_selectRc[0], _ptMouse))
		{
			_hPtChek = H_PT_1;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_hState = H_SELECT_NOSTRESS;
			}
		}
		else if (PtInD2D1Rect(_selectRc[1], _ptMouse))
		{
			_hPtChek = H_PT_2;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_hState = H_SELECT_HEALTHY;
			}
		}
		else if (PtInD2D1Rect(_selectRc[2], _ptMouse))
		{
			_hPtChek = H_PT_3;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_hState = H_SELECT_COYLY;
			}
		}
		else if (PtInD2D1Rect(_selectRc[3], _ptMouse))
		{
			_hPtChek = H_PT_4;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_hState = H_SELECT_DIET;
			}
		}
		else
		{
			_hPtChek = H_PT_NONE;
		}
	}
	if (_hState == H_SELECT_NOSTRESS)
	{
		if (PtInD2D1Rect(_changeRc[0], _ptMouse))
		{
			_isThis = true;
			_isNo = false;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_hChange = H_CHANGE_THIS;
				_hBasice = H_B_NOSTRESS;
				_iscomplete = true;
			}
		}
		else if (PtInD2D1Rect(_changeRc[1], _ptMouse))
		{
			_isThis = false;
			_isNo = true;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_hChange = H_CHANGE_NO;
				UIMANAGER->moveBeforeUI();
			}
		}
		else
		{
			_isThis = false;
			_isNo = false;
		}

		if (_hChange == H_CHANGE_THIS && _iscomplete)
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				UIMANAGER->moveBeforeUI();
			}
		}
	}
	if (_hState == H_SELECT_HEALTHY)
	{
		if (PtInD2D1Rect(_changeRc[0], _ptMouse))
		{
			_isThis = true;
			_isNo = false;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_hChange = H_CHANGE_THIS;
				_hBasice = H_B_HEALTHY;
				_iscomplete = true;
			}
		}
		else if (PtInD2D1Rect(_changeRc[1], _ptMouse))
		{
			_isThis = false;
			_isNo = true;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_hChange = H_CHANGE_NO;
				UIMANAGER->moveBeforeUI();
			}
		}
		else
		{
			_isThis = false;
			_isNo = false;
		}

		if (_hChange == H_CHANGE_THIS && _iscomplete)
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				UIMANAGER->moveBeforeUI();
			}
		}
	}
	if (_hState == H_SELECT_COYLY)
	{
		if (PtInD2D1Rect(_changeRc[0], _ptMouse))
		{
			_isThis = true;
			_isNo = false;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_hChange = H_CHANGE_THIS;
				_hBasice = H_B_COYLY;
				_iscomplete = true;
			}
		}
		else if (PtInD2D1Rect(_changeRc[1], _ptMouse))
		{
			_isThis = false;
			_isNo = true;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_hChange = H_CHANGE_NO;
				UIMANAGER->moveBeforeUI();
			}
		}
		else
		{
			_isThis = false;
			_isNo = false;
		}

		if (_hChange == H_CHANGE_THIS && _iscomplete)
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				UIMANAGER->moveBeforeUI();
			}
		}
	}
	if (_hState == H_SELECT_DIET)
	{
		if (PtInD2D1Rect(_changeRc[0], _ptMouse))
		{
			_isThis = true;
			_isNo = false;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_hChange = H_CHANGE_THIS;
				_hBasice = H_B_DIET;
				_iscomplete = true;
			}
		}
		else if (PtInD2D1Rect(_changeRc[1], _ptMouse))
		{
			_isThis = false;
			_isNo = true;
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_hChange = H_CHANGE_NO;
				UIMANAGER->moveBeforeUI();
			}
		}
		else
		{
			_isThis = false;
			_isNo = false;
		}

		if (_hChange == H_CHANGE_THIS && _iscomplete)
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				UIMANAGER->moveBeforeUI();
			}
		}
	}
}

void healthCare::render()
{
	WCHAR healthCare[256];

	FRAMEMANAGER->findMenuFrame("건강관리01")->render("텍스트박스");
	IMAGEMANAGER->findImage("큐브01")->render(385, 420);

	if (_hState == H_SELECT_NONE)
	{
		FRAMEMANAGER->findMenuFrame("건강선택")->render("선택박스");

		swprintf_s(healthCare, L"주인님. \n아가씨의 건강관리는 \n어떤 방침으로 하시겠습니까?");
		D2DMANAGER->drawText(healthCare, 30, 430, 18, RGB(255, 255, 255));

		switch (_hPtChek)
		{
		case H_PT_NONE:
			break;
		case H_PT_1:
			IMAGEMANAGER->findImage("선택중")->render(_selectRc[0].left, _selectRc[0].top);
			break;
		case H_PT_2:
			IMAGEMANAGER->findImage("선택중")->render(_selectRc[1].left, _selectRc[1].top);
			break;
		case H_PT_3:
			IMAGEMANAGER->findImage("선택중")->render(_selectRc[2].left, _selectRc[2].top);
			break;
		case H_PT_4:
			IMAGEMANAGER->findImage("선택중")->render(_selectRc[3].left, _selectRc[3].top);
			break;
		}

		swprintf_s(healthCare, L"무리하지 않는다");
		D2DMANAGER->drawText(healthCare, 610, 270, 18, RGB(255, 255, 255));
		swprintf_s(healthCare, L"어쨌든 튼튼하게");
		D2DMANAGER->drawText(healthCare, 610, 300, 18, RGB(255, 255, 255));
		swprintf_s(healthCare, L"얌전한 아이로");
		D2DMANAGER->drawText(healthCare, 610, 330, 18, RGB(255, 255, 255));
		swprintf_s(healthCare, L"다이어트 시킨다");
		D2DMANAGER->drawText(healthCare, 610, 360, 18, RGB(255, 255, 255));

	}

	switch (_hState)
	{
	case H_SELECT_NONE:
		break;
	case H_SELECT_NOSTRESS:

		if (!_iscomplete)
		{
			FRAMEMANAGER->findMenuFrame("건강내용")->render("텍스트박스");
			FRAMEMANAGER->findMenuFrame("결정")->render("선택박스");

			if (_isThis)
			{
				IMAGEMANAGER->findImage("선택중")->render(_changeRc[0].left, _changeRc[0].top);
			}
			if (_isNo)
			{
				IMAGEMANAGER->findImage("선택중")->render(_changeRc[1].left, _changeRc[1].top);
			}

			swprintf_s(healthCare, L"무리하지 않는다");
			D2DMANAGER->drawText(healthCare, 30, 306, 18, RGB(255, 255, 255));
			swprintf_s(healthCare, L"이 방침으로");
			D2DMANAGER->drawText(healthCare, 610, 270, 18, RGB(255, 255, 255));
			swprintf_s(healthCare, L"지금까지대로");
			D2DMANAGER->drawText(healthCare, 610, 300, 18, RGB(255, 255, 255));

			swprintf_s(healthCare, L"그 방침이라면 매달 식비가 \n30G 들어갑니다. \n무리없는 식생활을 보낼 수 있습니다.");
			D2DMANAGER->drawText(healthCare, 30, 430, 18, RGB(255, 255, 255));

		}
		else
		{
			switch (_hChange)
			{
			case H_CHANGE_NONE:
				break;
			case H_CHANGE_THIS:
				swprintf_s(healthCare, L"그 방침이라면 매달 식비가 \n30G 들어갑니다. \n무리없는 식생활을 보낼 수 있습니다.\n예, 알겠습니다. \n다음달부터 그렇게 하겠습니다.");
				D2DMANAGER->drawText(healthCare, 30, 430, 18, RGB(255, 255, 255));
				break;
			case H_CHANGE_NO:
				break;
			}
		}

		break;
	case H_SELECT_HEALTHY:
		if (!_iscomplete)
		{
			FRAMEMANAGER->findMenuFrame("건강내용")->render("텍스트박스");
			FRAMEMANAGER->findMenuFrame("결정")->render("선택박스");

			if (_isThis)
			{
				IMAGEMANAGER->findImage("선택중")->render(_changeRc[0].left, _changeRc[0].top);
			}
			if (_isNo)
			{
				IMAGEMANAGER->findImage("선택중")->render(_changeRc[1].left, _changeRc[1].top);
			}

			swprintf_s(healthCare, L"무리하지 않는다");
			D2DMANAGER->drawText(healthCare, 30, 306, 18, RGB(255, 255, 255));
			swprintf_s(healthCare, L"이 방침으로");
			D2DMANAGER->drawText(healthCare, 610, 270, 18, RGB(255, 255, 255));
			swprintf_s(healthCare, L"지금까지대로");
			D2DMANAGER->drawText(healthCare, 610, 300, 18, RGB(255, 255, 255));

			swprintf_s(healthCare, L"그 방침이라면 매달 식비가 \n80G 들어갑니다. \n체력이 올라가겠죠.");
			D2DMANAGER->drawText(healthCare, 30, 430, 18, RGB(255, 255, 255));

		}
		else
		{
			switch (_hChange)
			{
			case H_CHANGE_NONE:
				break;
			case H_CHANGE_THIS:
				swprintf_s(healthCare, L"그 방침이라면 매달 식비가 \n80G 들어갑니다. \n체력이 올라가겠죠.\n예, 알겠습니다. \n다음달부터 그렇게 하겠습니다.");
				D2DMANAGER->drawText(healthCare, 30, 430, 18, RGB(255, 255, 255));
				break;
			case H_CHANGE_NO:
				break;
			}
		}

		break;
	case H_SELECT_COYLY:
		if (!_iscomplete)
		{
			FRAMEMANAGER->findMenuFrame("건강내용")->render("텍스트박스");
			FRAMEMANAGER->findMenuFrame("결정")->render("선택박스");

			if (_isThis)
			{
				IMAGEMANAGER->findImage("선택중")->render(_changeRc[0].left, _changeRc[0].top);
			}
			if (_isNo)
			{
				IMAGEMANAGER->findImage("선택중")->render(_changeRc[1].left, _changeRc[1].top);
			}

			swprintf_s(healthCare, L"무리하지 않는다");
			D2DMANAGER->drawText(healthCare, 30, 306, 18, RGB(255, 255, 255));
			swprintf_s(healthCare, L"이 방침으로");
			D2DMANAGER->drawText(healthCare, 610, 270, 18, RGB(255, 255, 255));
			swprintf_s(healthCare, L"지금까지대로");
			D2DMANAGER->drawText(healthCare, 610, 300, 18, RGB(255, 255, 255));

			swprintf_s(healthCare, L"그 방침이라면 매달 식비가 \n10G 들어갑니다. \n약간 건강에 부담이 갈지도 모릅니다...");
			D2DMANAGER->drawText(healthCare, 30, 430, 18, RGB(255, 255, 255));

		}
		else
		{
			switch (_hChange)
			{
			case H_CHANGE_NONE:
				break;
			case H_CHANGE_THIS:
				swprintf_s(healthCare, L"예, 알겠습니다. \n다음달부터 그렇게 하겠습니다.");
				D2DMANAGER->drawText(healthCare, 30, 430, 18, RGB(255, 255, 255));
				break;
			case H_CHANGE_NO:
				break;
			}
		}
		break;
	case H_SELECT_DIET:
		if (!_iscomplete)
		{
			FRAMEMANAGER->findMenuFrame("건강내용")->render("텍스트박스");
			FRAMEMANAGER->findMenuFrame("결정")->render("선택박스");

			if (_isThis)
			{
				IMAGEMANAGER->findImage("선택중")->render(_changeRc[0].left, _changeRc[0].top);
			}
			if (_isNo)
			{
				IMAGEMANAGER->findImage("선택중")->render(_changeRc[1].left, _changeRc[1].top);
			}

			swprintf_s(healthCare, L"무리하지 않는다");
			D2DMANAGER->drawText(healthCare, 30, 306, 18, RGB(255, 255, 255));
			swprintf_s(healthCare, L"이 방침으로");
			D2DMANAGER->drawText(healthCare, 610, 270, 18, RGB(255, 255, 255));
			swprintf_s(healthCare, L"지금까지대로");
			D2DMANAGER->drawText(healthCare, 610, 300, 18, RGB(255, 255, 255));

			swprintf_s(healthCare, L"그 방침이라면 매달 식비가 5G 밖에\n들지 않습니다. 아가씨의 몸무게를\n줄이고 싶다면,이 방침으로 가시죠.\n단, 체력을 상당히 소모하므로\n주의하시기 바랍니다.");
			D2DMANAGER->drawText(healthCare, 30, 430, 18, RGB(255, 255, 255));

		}
		else
		{
			switch (_hChange)
			{
			case H_CHANGE_NONE:
				break;
			case H_CHANGE_THIS:
				swprintf_s(healthCare, L"예, 알겠습니다.\n다음달부터 그렇게 하겠습니다.");
				D2DMANAGER->drawText(healthCare, 30, 430, 18, RGB(255, 255, 255));
				break;
			case H_CHANGE_NO:
				break;
			}
		}
	break;
	}
}

void healthCare::uiClose()
{
	_hPtChek = H_PT_NONE;
	_hState = H_SELECT_NONE;
	_hChange = H_CHANGE_NONE;

	_isThis = false;
	_isNo = false;
	_iscomplete = false;
}

int healthCare::getHealthState()
{
	return (int)_hBasice;
}
