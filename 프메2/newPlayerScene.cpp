#include "stdafx.h"
#include "newPlayerScene.h"


newPlayerScene::newPlayerScene()
{
}


newPlayerScene::~newPlayerScene()
{
}

HRESULT newPlayerScene::init()
{
	_step = NEWPLAYER_FAMILY_NAME;
	_chosung = CHO_NONE;

	_selectCho = -1;
	_selectjung = 0 ;
	_selectjong = 0 ;
	//段失酵什
	{
		for (int i = 0; i < 19; ++i)
		{
			if (i < 6)
			{
				_cho[i] = { (float)150 + (i * 32), 300,(float)180 + (i * 32), 330 };
			}
			if (i >= 6 && i < 12)
			{
				_cho[i] = { (float)150 + ((i-6) * 32), 332,(float)180 + ((i-6) * 32), 362 };
			}
			if (i >= 12 && i < 18)
			{
				_cho[i] = { (float)150 + ((i - 12) * 32), 364, (float)180 + ((i - 12) * 32), 394 };
			}
		}
	}
	return S_OK;
}

void newPlayerScene::release()
{
}

void newPlayerScene::update()
{
	choSelect();
}

void newPlayerScene::render()
{
	WCHAR str[128];
	switch (_step)
	{
	case NEWPLAYER_FAMILY_NAME:
		IMAGEMANAGER->findImage("蝶遣斗持失識澱")->frameRender(0, 0, 1, 0);
		swprintf_s(str, L"雁重税 失精 巷譲脊艦猿? (4切 戚鎧)");
		D2DMANAGER->drawText(str, 200, 260, 24, RGB(255,255,255));
		choRender();

		swprintf_s(str, L"%d", _selectCho);
		D2DMANAGER->drawText(str, 200, 240, 24, RGB(255, 255, 255));
		swprintf_s(str, L"%c", _hagul);
		D2DMANAGER->drawText(str, 300, 240, 24, RGB(255, 255, 255));
		break;
	case NEWPLAYER_DAUGHTER_NAME:
		break;
	case NEWPLAYER_DAUGHTER_BIRTHDAY:
		break;
	case NEWPLAYER_AGE:
		break;
	case NEWPLAYER_BIRTHDAY:
		break;
	case NEWPLAYER_DAUGHTER_BLOODYTYPE:
		break;
	}
}

void newPlayerScene::choSelect()
{
	
	if (PtInD2D1Rect(_cho[0], _ptMouse))
	{
		_chosung = CHO_0;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_selectCho = 0;
		}
		
	}
	else if (PtInD2D1Rect(_cho[1], _ptMouse))
	{
		_chosung = CHO_1;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_selectCho = 1;
		}
	}
	else if (PtInD2D1Rect(_cho[2], _ptMouse))
	{
		_chosung = CHO_2;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_selectCho = 2;
		}
	}
	else if (PtInD2D1Rect(_cho[3], _ptMouse))
	{
		_chosung = CHO_3;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_selectCho = 3;
		}
	}
	else if (PtInD2D1Rect(_cho[4], _ptMouse))
	{
		_chosung = CHO_4;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_selectCho = 4;
		}
	}
	else if (PtInD2D1Rect(_cho[5], _ptMouse))
	{
		_chosung = CHO_5;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_selectCho = 5;
		}
	}
	else if (PtInD2D1Rect(_cho[6], _ptMouse))
	{
		_chosung = CHO_6;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_selectCho = 6;
		}
	}
	else if (PtInD2D1Rect(_cho[7], _ptMouse))
	{
		_chosung = CHO_7;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_selectCho = 7;
		}
	}
	else if (PtInD2D1Rect(_cho[8], _ptMouse))
	{
		_chosung = CHO_8;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_selectCho = 8;
		}
	}
	else if (PtInD2D1Rect(_cho[9], _ptMouse))
	{
		_chosung = CHO_9;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_selectCho = 9;
		}
	}
	else if (PtInD2D1Rect(_cho[10], _ptMouse))
	{
		_chosung = CHO_10;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_selectCho = 10;
		}
	}
	else if (PtInD2D1Rect(_cho[11], _ptMouse))
	{
		_chosung = CHO_11;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_selectCho = 11;
		}
	}
	else if (PtInD2D1Rect(_cho[12], _ptMouse))
	{
		_chosung = CHO_12;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_selectCho = 12;
		}
	}
	else if (PtInD2D1Rect(_cho[13], _ptMouse))
	{
		_chosung = CHO_13;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_selectCho = 13;
		}
	}
	else if (PtInD2D1Rect(_cho[14], _ptMouse))
	{
		_chosung = CHO_14;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_selectCho = 14;
		}
	}
	else if (PtInD2D1Rect(_cho[15], _ptMouse))
	{
		_chosung = CHO_15;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_selectCho = 15;
		}
	}
	else if (PtInD2D1Rect(_cho[16], _ptMouse))
	{
		_chosung = CHO_16;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_selectCho = 16;
		}
	}
	else if (PtInD2D1Rect(_cho[17], _ptMouse))
	{
		_chosung = CHO_17;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_selectCho = 17;
		}
	}
	else if (PtInD2D1Rect(_cho[18], _ptMouse))
	{
		_chosung = CHO_18;
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_selectCho = 18;
		}
	}
	else
	{
		_chosung = CHO_NONE;
		//_selectCho = -1;
	}
	hangul();
}

void newPlayerScene::choRender()
{
	//奄沙事雌
	{
		IMAGEMANAGER->findImage("段失_0")->frameRender(_cho[0].left, _cho[0].top, 0, 0);
		IMAGEMANAGER->findImage("段失_1")->frameRender(_cho[1].left, _cho[1].top, 0, 0);
		IMAGEMANAGER->findImage("段失_2")->frameRender(_cho[2].left, _cho[2].top, 0, 0);
		IMAGEMANAGER->findImage("段失_3")->frameRender(_cho[3].left, _cho[3].top, 0, 0);
		IMAGEMANAGER->findImage("段失_4")->frameRender(_cho[4].left, _cho[4].top, 0, 0);
		IMAGEMANAGER->findImage("段失_5")->frameRender(_cho[5].left, _cho[5].top, 0, 0);
		IMAGEMANAGER->findImage("段失_6")->frameRender(_cho[6].left, _cho[6].top, 0, 0);
		IMAGEMANAGER->findImage("段失_7")->frameRender(_cho[7].left, _cho[7].top, 0, 0);
		IMAGEMANAGER->findImage("段失_8")->frameRender(_cho[8].left, _cho[8].top, 0, 0);
		IMAGEMANAGER->findImage("段失_9")->frameRender(_cho[9].left, _cho[9].top, 0, 0);
		IMAGEMANAGER->findImage("段失_10")->frameRender(_cho[10].left, _cho[10].top, 0, 0);
		IMAGEMANAGER->findImage("段失_11")->frameRender(_cho[11].left, _cho[11].top, 0, 0);
		IMAGEMANAGER->findImage("段失_12")->frameRender(_cho[12].left, _cho[12].top, 0, 0);
		IMAGEMANAGER->findImage("段失_13")->frameRender(_cho[13].left, _cho[13].top, 0, 0);
		IMAGEMANAGER->findImage("段失_14")->frameRender(_cho[14].left, _cho[14].top, 0, 0);
		IMAGEMANAGER->findImage("段失_15")->frameRender(_cho[15].left, _cho[15].top, 0, 0);
		IMAGEMANAGER->findImage("段失_16")->frameRender(_cho[16].left, _cho[16].top, 0, 0);
		IMAGEMANAGER->findImage("段失_17")->frameRender(_cho[17].left, _cho[17].top, 0, 0);
		IMAGEMANAGER->findImage("段失_18")->frameRender(_cho[18].left, _cho[18].top, 0, 0);
	}
	
	switch (_chosung)
	{
	case CHO_0:
		IMAGEMANAGER->findImage("段失_0")->frameRender(_cho[0].left, _cho[0].top, 1, 0);
	break;
	case CHO_1:
		IMAGEMANAGER->findImage("段失_1")->frameRender(_cho[1].left, _cho[1].top, 1, 0);
	break;
	case CHO_2:
		IMAGEMANAGER->findImage("段失_2")->frameRender(_cho[2].left, _cho[2].top, 1, 0);
		
	break;
	case CHO_3:
		IMAGEMANAGER->findImage("段失_3")->frameRender(_cho[3].left, _cho[3].top, 1, 0);
		
	break;
	case CHO_4:
		IMAGEMANAGER->findImage("段失_4")->frameRender(_cho[4].left, _cho[4].top, 1, 0);
		
	break;
	case CHO_5:
		IMAGEMANAGER->findImage("段失_5")->frameRender(_cho[5].left, _cho[5].top, 1, 0);
		
	break;
	case CHO_6:
		IMAGEMANAGER->findImage("段失_6")->frameRender(_cho[6].left, _cho[6].top, 1, 0);
		
	break;
	case CHO_7:
		IMAGEMANAGER->findImage("段失_7")->frameRender(_cho[7].left, _cho[7].top, 1, 0);
		
	break;
	case CHO_8:
		IMAGEMANAGER->findImage("段失_8")->frameRender(_cho[8].left, _cho[8].top, 1, 0);
		
	break;
	case CHO_9:
		IMAGEMANAGER->findImage("段失_9")->frameRender(_cho[9].left, _cho[9].top, 1, 0);
		
	break;
	case CHO_10:
		IMAGEMANAGER->findImage("段失_10")->frameRender(_cho[10].left, _cho[10].top, 1, 0);
		
	break;
	case CHO_11:
		IMAGEMANAGER->findImage("段失_11")->frameRender(_cho[11].left, _cho[11].top, 1, 0);
		
	break;
	case CHO_12:
		IMAGEMANAGER->findImage("段失_12")->frameRender(_cho[12].left, _cho[12].top, 1, 0);
		
	break;
	case CHO_13:
		IMAGEMANAGER->findImage("段失_13")->frameRender(_cho[13].left, _cho[13].top, 1, 0);
		
	break;
	case CHO_14:
		IMAGEMANAGER->findImage("段失_14")->frameRender(_cho[14].left, _cho[14].top, 1, 0);
		
	break;
	case CHO_15:
		IMAGEMANAGER->findImage("段失_15")->frameRender(_cho[15].left, _cho[15].top, 1, 0);
		
	break;
	case CHO_16:
		IMAGEMANAGER->findImage("段失_16")->frameRender(_cho[16].left, _cho[16].top, 1, 0);
		
	break;
	case CHO_17:
		IMAGEMANAGER->findImage("段失_17")->frameRender(_cho[17].left, _cho[17].top, 1, 0);
	
	break;
	case CHO_18:
		IMAGEMANAGER->findImage("段失_18")->frameRender(_cho[18].left, _cho[18].top, 1, 0);
	break;
	}
}

void newPlayerScene::hangul()
{
	_hagul = BASE_CODE + 28 * 21 * _selectCho + 28 * _selectjung + _selectjong;

}

