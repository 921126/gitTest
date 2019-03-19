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

	FRAMEMANAGER->addFrame("�ǰ�����", 600, 250, 10, 8);
	FRAMEMANAGER->addFrame("�ǰ�����01", 20, 420, 20, 8);
	FRAMEMANAGER->addFrame("�ǰ�����", 20, 300, 15, 2);
	FRAMEMANAGER->addFrame("����", 600, 250, 10, 5);
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

	FRAMEMANAGER->findMenuFrame("�ǰ�����01")->render("�ؽ�Ʈ�ڽ�");
	IMAGEMANAGER->findImage("ť��01")->render(385, 420);

	if (_hState == H_SELECT_NONE)
	{
		FRAMEMANAGER->findMenuFrame("�ǰ�����")->render("���ùڽ�");

		swprintf_s(healthCare, L"���δ�. \n�ư����� �ǰ������� \n� ��ħ���� �Ͻðڽ��ϱ�?");
		D2DMANAGER->drawText(healthCare, 30, 430, 18, RGB(255, 255, 255));

		switch (_hPtChek)
		{
		case H_PT_NONE:
			break;
		case H_PT_1:
			IMAGEMANAGER->findImage("������")->render(_selectRc[0].left, _selectRc[0].top);
			break;
		case H_PT_2:
			IMAGEMANAGER->findImage("������")->render(_selectRc[1].left, _selectRc[1].top);
			break;
		case H_PT_3:
			IMAGEMANAGER->findImage("������")->render(_selectRc[2].left, _selectRc[2].top);
			break;
		case H_PT_4:
			IMAGEMANAGER->findImage("������")->render(_selectRc[3].left, _selectRc[3].top);
			break;
		}

		swprintf_s(healthCare, L"�������� �ʴ´�");
		D2DMANAGER->drawText(healthCare, 610, 270, 18, RGB(255, 255, 255));
		swprintf_s(healthCare, L"��·�� ưư�ϰ�");
		D2DMANAGER->drawText(healthCare, 610, 300, 18, RGB(255, 255, 255));
		swprintf_s(healthCare, L"������ ���̷�");
		D2DMANAGER->drawText(healthCare, 610, 330, 18, RGB(255, 255, 255));
		swprintf_s(healthCare, L"���̾�Ʈ ��Ų��");
		D2DMANAGER->drawText(healthCare, 610, 360, 18, RGB(255, 255, 255));

	}

	switch (_hState)
	{
	case H_SELECT_NONE:
		break;
	case H_SELECT_NOSTRESS:

		if (!_iscomplete)
		{
			FRAMEMANAGER->findMenuFrame("�ǰ�����")->render("�ؽ�Ʈ�ڽ�");
			FRAMEMANAGER->findMenuFrame("����")->render("���ùڽ�");

			if (_isThis)
			{
				IMAGEMANAGER->findImage("������")->render(_changeRc[0].left, _changeRc[0].top);
			}
			if (_isNo)
			{
				IMAGEMANAGER->findImage("������")->render(_changeRc[1].left, _changeRc[1].top);
			}

			swprintf_s(healthCare, L"�������� �ʴ´�");
			D2DMANAGER->drawText(healthCare, 30, 306, 18, RGB(255, 255, 255));
			swprintf_s(healthCare, L"�� ��ħ����");
			D2DMANAGER->drawText(healthCare, 610, 270, 18, RGB(255, 255, 255));
			swprintf_s(healthCare, L"���ݱ������");
			D2DMANAGER->drawText(healthCare, 610, 300, 18, RGB(255, 255, 255));

			swprintf_s(healthCare, L"�� ��ħ�̶�� �Ŵ� �ĺ� \n30G ���ϴ�. \n�������� �Ļ�Ȱ�� ���� �� �ֽ��ϴ�.");
			D2DMANAGER->drawText(healthCare, 30, 430, 18, RGB(255, 255, 255));

		}
		else
		{
			switch (_hChange)
			{
			case H_CHANGE_NONE:
				break;
			case H_CHANGE_THIS:
				swprintf_s(healthCare, L"�� ��ħ�̶�� �Ŵ� �ĺ� \n30G ���ϴ�. \n�������� �Ļ�Ȱ�� ���� �� �ֽ��ϴ�.\n��, �˰ڽ��ϴ�. \n�����޺��� �׷��� �ϰڽ��ϴ�.");
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
			FRAMEMANAGER->findMenuFrame("�ǰ�����")->render("�ؽ�Ʈ�ڽ�");
			FRAMEMANAGER->findMenuFrame("����")->render("���ùڽ�");

			if (_isThis)
			{
				IMAGEMANAGER->findImage("������")->render(_changeRc[0].left, _changeRc[0].top);
			}
			if (_isNo)
			{
				IMAGEMANAGER->findImage("������")->render(_changeRc[1].left, _changeRc[1].top);
			}

			swprintf_s(healthCare, L"�������� �ʴ´�");
			D2DMANAGER->drawText(healthCare, 30, 306, 18, RGB(255, 255, 255));
			swprintf_s(healthCare, L"�� ��ħ����");
			D2DMANAGER->drawText(healthCare, 610, 270, 18, RGB(255, 255, 255));
			swprintf_s(healthCare, L"���ݱ������");
			D2DMANAGER->drawText(healthCare, 610, 300, 18, RGB(255, 255, 255));

			swprintf_s(healthCare, L"�� ��ħ�̶�� �Ŵ� �ĺ� \n80G ���ϴ�. \nü���� �ö󰡰���.");
			D2DMANAGER->drawText(healthCare, 30, 430, 18, RGB(255, 255, 255));

		}
		else
		{
			switch (_hChange)
			{
			case H_CHANGE_NONE:
				break;
			case H_CHANGE_THIS:
				swprintf_s(healthCare, L"�� ��ħ�̶�� �Ŵ� �ĺ� \n80G ���ϴ�. \nü���� �ö󰡰���.\n��, �˰ڽ��ϴ�. \n�����޺��� �׷��� �ϰڽ��ϴ�.");
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
			FRAMEMANAGER->findMenuFrame("�ǰ�����")->render("�ؽ�Ʈ�ڽ�");
			FRAMEMANAGER->findMenuFrame("����")->render("���ùڽ�");

			if (_isThis)
			{
				IMAGEMANAGER->findImage("������")->render(_changeRc[0].left, _changeRc[0].top);
			}
			if (_isNo)
			{
				IMAGEMANAGER->findImage("������")->render(_changeRc[1].left, _changeRc[1].top);
			}

			swprintf_s(healthCare, L"�������� �ʴ´�");
			D2DMANAGER->drawText(healthCare, 30, 306, 18, RGB(255, 255, 255));
			swprintf_s(healthCare, L"�� ��ħ����");
			D2DMANAGER->drawText(healthCare, 610, 270, 18, RGB(255, 255, 255));
			swprintf_s(healthCare, L"���ݱ������");
			D2DMANAGER->drawText(healthCare, 610, 300, 18, RGB(255, 255, 255));

			swprintf_s(healthCare, L"�� ��ħ�̶�� �Ŵ� �ĺ� \n10G ���ϴ�. \n�ణ �ǰ��� �δ��� ������ �𸨴ϴ�...");
			D2DMANAGER->drawText(healthCare, 30, 430, 18, RGB(255, 255, 255));

		}
		else
		{
			switch (_hChange)
			{
			case H_CHANGE_NONE:
				break;
			case H_CHANGE_THIS:
				swprintf_s(healthCare, L"��, �˰ڽ��ϴ�. \n�����޺��� �׷��� �ϰڽ��ϴ�.");
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
			FRAMEMANAGER->findMenuFrame("�ǰ�����")->render("�ؽ�Ʈ�ڽ�");
			FRAMEMANAGER->findMenuFrame("����")->render("���ùڽ�");

			if (_isThis)
			{
				IMAGEMANAGER->findImage("������")->render(_changeRc[0].left, _changeRc[0].top);
			}
			if (_isNo)
			{
				IMAGEMANAGER->findImage("������")->render(_changeRc[1].left, _changeRc[1].top);
			}

			swprintf_s(healthCare, L"�������� �ʴ´�");
			D2DMANAGER->drawText(healthCare, 30, 306, 18, RGB(255, 255, 255));
			swprintf_s(healthCare, L"�� ��ħ����");
			D2DMANAGER->drawText(healthCare, 610, 270, 18, RGB(255, 255, 255));
			swprintf_s(healthCare, L"���ݱ������");
			D2DMANAGER->drawText(healthCare, 610, 300, 18, RGB(255, 255, 255));

			swprintf_s(healthCare, L"�� ��ħ�̶�� �Ŵ� �ĺ� 5G �ۿ�\n���� �ʽ��ϴ�. �ư����� �����Ը�\n���̰� �ʹٸ�,�� ��ħ���� ������.\n��, ü���� ����� �Ҹ��ϹǷ�\n�����Ͻñ� �ٶ��ϴ�.");
			D2DMANAGER->drawText(healthCare, 30, 430, 18, RGB(255, 255, 255));

		}
		else
		{
			switch (_hChange)
			{
			case H_CHANGE_NONE:
				break;
			case H_CHANGE_THIS:
				swprintf_s(healthCare, L"��, �˰ڽ��ϴ�.\n�����޺��� �׷��� �ϰڽ��ϴ�.");
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
