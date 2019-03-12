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
	FRAMEMANAGER->addFrame("�湮�ϱ�", 600, 240, 6, 16);
	FRAMEMANAGER->addFrame("���湮01", 175, 370, 25, 8);
	FRAMEMANAGER->addFrame("���湮02", 200, 370, 20, 8);
	FRAMEMANAGER->addFrame("���湮03", 250, 370, 20, 8);

	//���û���
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
	// to do �� �������� �ൿ �ֱ� ex) ���� ȭ�� 40 ������ ������ ���첨�� 
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
	IMAGEMANAGER->findImage("���̹���")->render(35, 120);
	if (!_isVisit && _vState == V_SELECT_NONE)
	{
		FRAMEMANAGER->findMenuFrame("���湮01")->render("�ؽ�Ʈ�ڽ�");

		swprintf_s(visit, L"���� �Խ��ϴ�.");
		D2DMANAGER->drawText(visit, 185, 380, 18, RGB(255, 255, 255));
	}
	else if(_isVisit)
	{
		FRAMEMANAGER->findMenuFrame("�湮�ϱ�")->render("���ùڽ�");
		FRAMEMANAGER->findMenuFrame("���湮02")->render("�ؽ�Ʈ�ڽ�");
		IMAGEMANAGER->findImage("������")->render( 60, 370);
		swprintf_s(visit, L"�Ա���. \n�̹��� ������ �������� �ų�?");
		D2DMANAGER->drawText(visit, 210, 380, 18, RGB(255, 255, 255));

		switch (_ptChek)
		{
		case V_PT_1:
			IMAGEMANAGER->findImage("������2")->render(_selectRc[0].left, _selectRc[0].top);
			break;
		case V_PT_2:
			IMAGEMANAGER->findImage("������2")->render(_selectRc[1].left, _selectRc[1].top);
			break;
		case V_PT_3:
			IMAGEMANAGER->findImage("������2")->render(_selectRc[2].left, _selectRc[2].top);
			break;
		case V_PT_4:
			IMAGEMANAGER->findImage("������2")->render(_selectRc[3].left, _selectRc[3].top);
			break;
		case V_PT_5:
			IMAGEMANAGER->findImage("������2")->render(_selectRc[4].left, _selectRc[4].top);
			break;
		case V_PT_6:
			IMAGEMANAGER->findImage("������2")->render(_selectRc[5].left, _selectRc[5].top);
			break;
		case V_PT_7:
			IMAGEMANAGER->findImage("������2")->render(_selectRc[6].left, _selectRc[6].top);
			break;
		case V_PT_8:
			IMAGEMANAGER->findImage("������2")->render(_selectRc[7].left, _selectRc[7].top);
			break;
		case V_PT_9:
			IMAGEMANAGER->findImage("������2")->render(_selectRc[8].left, _selectRc[8].top);
			break;
		case V_PT_10:
			IMAGEMANAGER->findImage("������2")->render(_selectRc[9].left, _selectRc[9].top);
			break;
		}

		//�������ִ� �װյ�

		swprintf_s(visit, L"������");
		D2DMANAGER->drawText(visit, 610, 260, 18, RGB(255, 255, 255));
		swprintf_s(visit, L"�������");
		D2DMANAGER->drawText(visit, 610, 285, 18, RGB(255, 255, 255));
		swprintf_s(visit, L"�屺");
		D2DMANAGER->drawText(visit, 610, 310, 18, RGB(255, 255, 255));
		swprintf_s(visit, L"���");
		D2DMANAGER->drawText(visit, 610, 335, 18, RGB(255, 255, 255));
		swprintf_s(visit, L"�ֱ�");
		D2DMANAGER->drawText(visit, 610, 360, 18, RGB(255, 255, 255));
		swprintf_s(visit, L"�ı�");
		D2DMANAGER->drawText(visit, 610, 385, 18, RGB(255, 255, 255));
		swprintf_s(visit, L"�պ�");
		D2DMANAGER->drawText(visit, 610, 410, 18, RGB(255, 255, 255));
		swprintf_s(visit, L"����");
		D2DMANAGER->drawText(visit, 610, 435, 18, RGB(255, 255, 255));
		swprintf_s(visit, L"����");
		D2DMANAGER->drawText(visit, 610, 460, 18, RGB(255, 255, 255));
		swprintf_s(visit, L"û�⹫��");
		D2DMANAGER->drawText(visit, 610, 485, 18, RGB(255, 255, 255));
	}
	switch (_vState)
	{
	case V_SELECT_GUARD:
		FRAMEMANAGER->findMenuFrame("���湮03")->render("�ؽ�Ʈ�ڽ�");
		IMAGEMANAGER->findImage("������")->render(60, 370);
		swprintf_s(visit, L"�Ա���. \n�̹��� ������ �������� �ų�?");
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

	swprintf_s(visit, L"���°���: %d", _vState);
	D2DMANAGER->drawText(visit, 300, 0, 18, RGB(255, 255, 255));
}

void visit::uiClose()
{
	_isVisit = false;
	_vState = V_SELECT_NONE;
	_ptChek = V_PT_NONE;
}
