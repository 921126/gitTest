#include "stdafx.h"
#include "objectTool.h"


objectTool::objectTool()
{
}


objectTool::~objectTool()
{
}

HRESULT objectTool::init()
{
	//�̹���
	{
		_sampleImg_Obj[1] = IMAGEMANAGER->findImage(OBJECT_INFO[OBJECT_1]);
		_sampleImg_Obj[2] = IMAGEMANAGER->findImage(OBJECT_INFO[OBJECT_2]);
		_sampleImg_Obj[3] = IMAGEMANAGER->findImage(OBJECT_INFO[OBJECT_3]);
		_sampleImg_Obj[4] = IMAGEMANAGER->findImage(OBJECT_INFO[OBJECT_4]);
		_sampleImg_Obj[5] = IMAGEMANAGER->findImage(OBJECT_INFO[OBJECT_5]);
		_sampleImg_Obj[6] = IMAGEMANAGER->findImage(OBJECT_INFO[OBJECT_6]);
		_sampleImg_Obj[7] = IMAGEMANAGER->findImage(OBJECT_INFO[OBJECT_7]);
		_sampleImg_Obj[8] = IMAGEMANAGER->findImage(OBJECT_INFO[OBJECT_8]);
		_sampleImg_Obj[9] = IMAGEMANAGER->findImage(OBJECT_INFO[OBJECT_9]);
	}

	//ī�޶� ��ġ ����ֱ�
	CAMERA->init(0, 0, 4000, 1880);

	_currentPage = OBJECT_1;

	//Ÿ�� ���ÿ� ����
	_isTileSelect = false;
	//����Ÿ�� ����
	setSampleTile();
	setTile();

	//��ư
	_leftButton = { 570, 260, 670, 300 };
	_rightButton = { 680, 260, 780, 300 };

	_sizeUpWidth = { 570, 400, 780, 440 };
	_sizeUpHeight = { 570, 450, 780, 490 };
	_sizeDownWidth = { 570, 500, 780, 540 };
	_sizeDownHeight = { 570, 550, 780, 590 };

	_sampleTileRange = { 560, 0, 800, 240 };

	return S_OK;
}

void objectTool::release()
{
}

void objectTool::update()
{
	//ī�޶� �̵�
	CAMERA->mapToolMove();
	_sampleTileRange = { 560 + CAMERA ->getPosX(), 0 + CAMERA->getPosY(), 800 + CAMERA->getPosX(), 240 + CAMERA->getPosY() };
	buttonsetting();
	selectSampleMap();
	setMap();
	mapSizeUpDown();

	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		mapSave();
	}
	if (KEYMANAGER->isOnceKeyUp(VK_F2))
	{
		mapLoad();
	}
}

void objectTool::render()
{
	{
	//	D2DMANAGER->drawRectangle(_sampleTileRange);
	//	D2DMANAGER->fillRectangle(RGB(255, 0, 255), _sampleTileRange);
	}
	IMAGEMANAGER->findImage(OBJECT_INFO[_currentPage])->render(CAMERA->getPosX() + SAMPLE_TILE_START, CAMERA->getPosY() + 0);

	//��ư �׸���
	{

		IMAGEMANAGER->findImage("�����̵���ư")->frameRender(_leftButton.left + CAMERA->getPosX(), _leftButton.top + CAMERA->getPosY(), 0, 1);
		IMAGEMANAGER->findImage("�����̵���ư")->frameRender(_rightButton.left + CAMERA->getPosX(), _rightButton.top + CAMERA->getPosY(), 0, 0);

		IMAGEMANAGER->findImage("����������ư")->frameRender(_sizeUpWidth.left + CAMERA->getPosX(), _sizeUpWidth.top + CAMERA->getPosY(), 0, 0);
		IMAGEMANAGER->findImage("����������ư")->frameRender(_sizeUpHeight.left + CAMERA->getPosX(), _sizeUpHeight.top + CAMERA->getPosY(), 0, 2);
		IMAGEMANAGER->findImage("����������ư")->frameRender(_sizeDownWidth.left + CAMERA->getPosX(), _sizeDownWidth.top + CAMERA->getPosY(), 0, 1);
		IMAGEMANAGER->findImage("����������ư")->frameRender(_sizeDownHeight.left + CAMERA->getPosX(), _sizeDownHeight.top + CAMERA->getPosY(), 0, 3);

		D2DMANAGER->drawRectangle(_leftButton.left + CAMERA->getPosX(), _leftButton.top + CAMERA->getPosY(), _leftButton.right + CAMERA->getPosX(), _leftButton.bottom + CAMERA->getPosY());
		D2DMANAGER->drawRectangle(_rightButton.left + CAMERA->getPosX(), _rightButton.top + CAMERA->getPosY(), _rightButton.right + CAMERA->getPosX(), _rightButton.bottom + CAMERA->getPosY());

		D2DMANAGER->drawRectangle(_sizeUpWidth.left + CAMERA->getPosX(), _sizeUpWidth.top + CAMERA->getPosY(), _sizeUpWidth.right + CAMERA->getPosX(), _sizeUpWidth.bottom + CAMERA->getPosY());
		D2DMANAGER->drawRectangle(_sizeUpHeight.left + CAMERA->getPosX(), _sizeUpHeight.top + CAMERA->getPosY(), _sizeUpHeight.right + CAMERA->getPosX(), _sizeUpHeight.bottom + CAMERA->getPosY());
		D2DMANAGER->drawRectangle(_sizeDownWidth.left + CAMERA->getPosX(), _sizeDownWidth.top + CAMERA->getPosY(), _sizeDownWidth.right + CAMERA->getPosX(), _sizeDownWidth.bottom + CAMERA->getPosY());
		D2DMANAGER->drawRectangle(_sizeDownHeight.left + CAMERA->getPosX(), _sizeDownHeight.top + CAMERA->getPosY(), _sizeDownHeight.right + CAMERA->getPosX(), _sizeDownHeight.bottom + CAMERA->getPosY());
	}
	//����Ÿ�� ��Ʈ�׸���
	for (int i = 0; i < SAMPLETILE; ++i)
	{
		for (int j = 0; j < SAMPLETILE; ++j)
		{
			D2DMANAGER->drawRectangle(CAMERA->getPosX() + _sampleTile_Obj[i][j].sampleRc.left
				, CAMERA->getPosY() + _sampleTile_Obj[i][j].sampleRc.top
				, CAMERA->getPosX() + _sampleTile_Obj[i][j].sampleRc.right
				, CAMERA->getPosY() + _sampleTile_Obj[i][j].sampleRc.bottom);
		}
	}
	//�� ����
	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			//���׸��� �� ī�޶� �����ֱ� ����ó��
			if (_vvRect[i][j].left - CAMERA->getPosX() < 0) continue;
			if (_vvRect[i][j].right - CAMERA->getPosX() > CAMERA_RANGE) continue;

			//�������� �� �׸���
			D2DMANAGER->drawRectangle(_vvRect[i][j].left, _vvRect[i][j].top, _vvRect[i][j].right, _vvRect[i][j].bottom);

			//����ó��2
			if (_vvTile[i][j]->terrainImageIndex != TERRAIN_NONE)
			{
				IMAGEMANAGER->findImage(TERRAIN_INFO[_vvTile[i][j]->terrainImageIndex])->frameRender(_vvRect[i][j].left, _vvRect[i][j].top, _vvTile[i][j]->terrainFrameX, _vvTile[i][j]->terrainFrameY);
			}

			if (_vvTile[i][j]->objectImageIndex != OBJECT_NONE)
			{
				//�������� Ÿ�� �׸���
				
				IMAGEMANAGER->findImage(OBJECT_INFO[_vvTile[i][j]->objectImageIndex])->frameRender(_vvRect[i][j].left, _vvRect[i][j].top, _vvTile[i][j]->objectFrameX, _vvTile[i][j]->objectFrameY);
			}
		}
	}

	//�ʾ� �����

	if (_isTileSelect)
	{
		IMAGEMANAGER->findImage(OBJECT_INFO[_currentPage])->frameRender(_ptMouse.x, _ptMouse.y, _selectSampleTile.currentX, _selectSampleTile.currentY, 0.5f);
	}

}

void objectTool::setSampleTile()
{
	for (int i = 0; i < SAMPLETILE; ++i)
	{
		for (int j = 0; j < SAMPLETILE; ++j)
		{
			_sampleTile_Obj[i][j].frameX = 0;
			_sampleTile_Obj[i][j].frameY = 0;
			_sampleTile_Obj[i][j].sampleRc = {  (float)(WINSIZEX - SAMPLE_TILE_SIZE) + (j *TILE_SIZE),			//����Ʈ
												(float)(i * TILE_SIZE),											//ž
												(float)(WINSIZEX - SAMPLE_TILE_SIZE) + ((j + 1) * TILE_SIZE),		//����Ʈ
												(float)((i + 1) * TILE_SIZE) };
		}
	}
}

void objectTool::setTile()
{
	//��
	TILEX = 100;
	TILEY = 47;
	for (int i = 0; i < TILEY; ++i)
	{
		vector<tagTile*>		vTile;
		vector<D2D1_RECT_F>		vRect;

		for (int j = 0; j < TILEX; ++j)
		{
			tagTile* tempTile = new tagTile;
			D2D1_RECT_F *tempRect = new D2D1_RECT_F;

			tempTile->terrainFrameX = 0;
			tempTile->terrainFrameY = 0;

			tempTile->objectFrameX = 0;
			tempTile->objectFrameY = 0;


			tempTile->attr |= ATTR_NONE;		//�Ӽ�
			tempTile->terrainImageIndex = TERRAIN_NONE;
			tempTile->objectImageIndex = OBJECT_NONE;

			*tempRect = { (float)j * TILE_SIZE, (float)i * TILE_SIZE, (float)(j + 1) * TILE_SIZE, (float)(i + 1) * TILE_SIZE };

			//���Ϳ� ����ֱ�
			vTile.push_back(tempTile);
			vRect.push_back(*tempRect);
		}
		//�ѹ��� ���Ϳ� ����ֱ�
		_vvTile.push_back(vTile);
		_vvRect.push_back(vRect);
	}
}

void objectTool::setMap()
{
	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			if (PtInD2D1Rect(_sampleTileRange, _ptMouse)) continue;

			if (PtInD2D1Rect(_vvRect[i][j], _ptMouse))
			{
				//�׸���
				if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
				{
					_vvTile[i][j]->objectImageIndex = _currentPage;
					_vvTile[i][j]->objectFrameX = _selectSampleTile.currentX;
					_vvTile[i][j]->objectFrameY = _selectSampleTile.currentY;
					//_vvTile[i][j]->attr = setAttribute(TERRAIN_INFO[_vvTile[i][j]->terrainImageIndex], _vvTile[i][j]->terrainFrameX, _vvTile[i][j]->terrainFrameY);
				}
				//�����
				if (KEYMANAGER->isStayKeyDown(VK_RBUTTON))
				{
					for (int i = 0; i < TILEY; ++i)
					{
						for (int j = 0; j < TILEX; ++j)
						{
							_vvTile[i][j]->objectImageIndex = OBJECT_NONE;
							_vvTile[i][j]->objectFrameX = 0;
							_vvTile[i][j]->objectFrameY = 0;
							//_vvTile[i][j]->attr = setAttribute(TERRAIN_INFO[_vvTile[i][j]->terrainImageIndex], _vvTile[i][j]->terrainFrameX, _vvTile[i][j]->terrainFrameY);
						}
					}
				}
			}
		}
	}
}

void objectTool::buttonsetting()
{
	// ���� ��ư ��������
	if (PtInD2D1Rect(_leftButton, PointFMake(_ptMouse.x - CAMERA->getPosX(), _ptMouse.y - CAMERA->getPosY())))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			--_currentPage;
			if (_currentPage < OBJECT_1)
			{
				_currentPage = OBJECT_10;
			}
		}
	}

	//������ ��ư ��������
	if (PtInD2D1Rect(_rightButton, PointFMake(_ptMouse.x - CAMERA->getPosX(), _ptMouse.y - CAMERA->getPosY())))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			++_currentPage;
			if (_currentPage > OBJECT_10)
			{
				_currentPage = OBJECT_1;
			}
		}
	}
}

void objectTool::selectSampleMap()
{	//����ó��
	if (_ptMouse.x - CAMERA->getPosX() < SAMPLE_TILE_START) return;

	int indX = ((_ptMouse.x - CAMERA->getPosX()) - SAMPLE_TILE_START) / TILE_SIZE;
	int indY = (_ptMouse.y - CAMERA->getPosY()) / TILE_SIZE;

	if (indX >= SAMPLETILE || indX < 0) return;
	if (indY >= SAMPLETILE || indY < 0) return;

	if (PtInD2D1Rect(_sampleTileRange, PointFMake(_ptMouse.x, _ptMouse.y)))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_isTileSelect = true;

			if ((indX >= 0 && indX < SAMPLETILE) && (indY >= 0 && indY < SAMPLETILE))
			{
				_selectSampleTile.currentX = indX;
				_selectSampleTile.currentY = indY;
				_selectSampleTile.isObj = true;
			}
			else
				_isTileSelect = false;
		}
	}
}

void objectTool::mapSizeUpDown()
{

	//���λ����� ���̱�
	if (PtInD2D1Rect(_sizeDownWidth, PointFMake(_ptMouse.x - CAMERA->getPosX(), _ptMouse.y - CAMERA->getPosY())))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && TILEX > 1)
		{
			for (int i = 0; i < TILEY; ++i)
			{
				tagTile* target = _vvTile[i].back();
				D2D1_RECT_F targetRc = _vvRect[i].back();

				_vvTile[i].pop_back();
				_vvRect[i].pop_back();
				SAFE_DELETE(target);
			}
			TILEX--;
		}
	}

	//���λ����� �ø���
	if (PtInD2D1Rect(_sizeUpWidth, PointFMake(_ptMouse.x - CAMERA->getPosX(), _ptMouse.y - CAMERA->getPosY())))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && TILEX > 1)
		{
			for (int i = 0; i < TILEY; ++i)
			{
				tagTile* tempTile = new tagTile;
				D2D1_RECT_F tempRect = { (float)_vvRect[i].back().left + TILE_SIZE
									  , (float)_vvRect[i].back().top
									  , (float)_vvRect[i].back().right + TILE_SIZE
									  , (float)_vvRect[i].back().bottom };

				tempTile->terrainFrameX = 0;
				tempTile->terrainFrameY = 0;

				tempTile->objectFrameX = 0;
				tempTile->objectFrameY = 0;

				tempTile->attr |= ATTR_NONE;

				tempTile->terrainImageIndex = TERRAIN_NONE;
				tempTile->objectImageIndex = OBJECT_NONE;

				_vvTile[i].push_back(tempTile);
				_vvRect[i].push_back(tempRect);
			}
			++TILEX;
		}
	}

	//���λ����� ���̱� (Y���� ��� ������ ������ �����Ͻÿ�)
	if (PtInD2D1Rect(_sizeDownHeight, PointFMake(_ptMouse.x - CAMERA->getPosX(), _ptMouse.y - CAMERA->getPosY())))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && TILEX > 1)
		{
			for (int i = 0; i < TILEX; ++i)
			{
				delete _vvTile.back()[i];
				_vvTile.back()[i] = nullptr;
			}
			_vvTile.pop_back();
			_vvRect.pop_back();
			--TILEY;
		}
	}

	//���� ������ �ø���
	if (PtInD2D1Rect(_sizeUpHeight, PointFMake(_ptMouse.x - CAMERA->getPosX(), _ptMouse.y - CAMERA->getPosY())))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) && TILEY > 1)
		{
			vector<tagTile*> vTile;
			vector<D2D1_RECT_F> vRect;

			for (int i = 0; i < TILEX; ++i)
			{
				tagTile* tempTile = new tagTile;

				D2D1_RECT_F tempRect = { (float)_vvRect.back()[i].left
									   , (float)_vvRect.back()[i].top + TILE_SIZE
									   , (float)_vvRect.back()[i].right
									   , (float)_vvRect.back()[i].bottom + TILE_SIZE };

				tempTile->terrainFrameX = 0;
				tempTile->terrainFrameY = 0;

				tempTile->objectFrameX = 0;
				tempTile->objectFrameY = 0;

				tempTile->attr |= ATTR_NONE;

				tempTile->terrainImageIndex = TERRAIN_NONE;
				tempTile->objectImageIndex = OBJECT_NONE;

				vTile.push_back(tempTile);
				vRect.push_back(tempRect);
			}
			_vvTile.push_back(vTile);
			_vvRect.push_back(vRect);
			++TILEY;
		}
	}
}

void objectTool::mapSave()
{
	//�ʻ����� ����
	HANDLE file;
	DWORD write;

	char mapSize[128];
	sprintf_s(mapSize, "%d, %d", TILEX, TILEY);
	file = CreateFile("East_Forest_size.map", GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, mapSize, strlen(mapSize), &write, NULL);

	CloseHandle(file);

	//��Ÿ�� ����
	HANDLE file2;
	DWORD write2;

	tagTile* tile = (tagTile*)malloc(sizeof(tagTile) * TILEX * TILEY);
	ZeroMemory(tile, sizeof(tagTile) * (TILEX * TILEY));

	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			tile[j + i * TILEX].setTile(*_vvTile[i][j]);
		}
	}

	file2 = CreateFile("East_Forest_tile.map", GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	WriteFile(file2, tile, sizeof(tagTile) * TILEX * TILEY, &write2, NULL);

	CloseHandle(file2);
}

void objectTool::mapLoad()
{

	for (int i = TILEY - 1; i >= 0; i--)
	{
		for (int j = TILEX - 1; j >= 0; j--)
		{
			if (_vvTile[i][j])
			{
				SAFE_DELETE(_vvTile[i][j]);
				_vvTile[i].pop_back();
			}
		}
		_vvTile.pop_back();
	}


	_vvTile.clear();

	HANDLE file;
	DWORD read;
	char mapSize[128] = { 0, };

	file = CreateFile("East_Forest_size.map", GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	ReadFile(file, mapSize, 128, &read, NULL);
	CloseHandle(file);

	string mapX, mapY;
	mapX.clear();
	mapY.clear();
	bool x = true;
	for (int i = 0; i < strlen(mapSize); ++i)
	{
		if (mapSize[i] == ',')
		{
			x = false;
			continue;
		}
		if (mapSize[i] == NULL)
			break;
		if (x)
		{
			mapX += mapSize[i];
		}
		else
		{
			mapY += mapSize[i];
		}
	}

	TILEX = stoi(mapX);
	TILEY = stoi(mapY);
	_vvTile.resize(TILEY);

	for (int i = 0; i < TILEY; ++i)
	{
		_vvTile[i].resize(TILEX);
	}

	tagTile* tile = (tagTile*)malloc(sizeof(tagTile) * TILEX * TILEY);
	ZeroMemory(tile, sizeof(tagTile) * (TILEX * TILEY));

	HANDLE file2;
	DWORD read2;

	file2 = CreateFile("East_Forest_tile.map", GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file2, tile, sizeof(tagTile) * TILEX * TILEY, &read2, NULL);

	CloseHandle(file2);

	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			_vvTile[i][j] = new tagTile;
			_vvTile[i][j]->setTile(tile[j + i * TILEX]);
		}
	}
}
