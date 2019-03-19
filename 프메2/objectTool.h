#pragma once
#include "gameNode.h"
#include "TileNode.h"
#include "mapTool.h"
#include <vector>
#include <assert.h>

#define OBJECT_IMG_NUM		22
#define SAMPLE_TILE_SIZE	TILE_SIZE * SAMPLETILE			//����Ÿ�� ������
#define SAMPLE_TILE_START	(WINSIZEX - SAMPLE_TILE_SIZE)	//����Ÿ�� ��������
#define CAMERA_RANGE		13 * TILE_SIZE					//ī�޶� �̵� ����

struct tagSampleTile_Object
{
	D2D1_RECT_F sampleRc;
	int frameX;
	int frameY;
};
struct tagCurrentTile_Object
{
	bool isObj = true;
	int currentX = 0;
	int currentY = 0;
};

class objectTool : public gameNode
{
private:
	image* _sampleImg_Obj[OBJECT_IMG_NUM];
	tagSampleTile_Object _sampleTile_Obj[SAMPLETILE][SAMPLETILE];

	vector<vector<tagTile*>> _vvTile;
	vector<vector<D2D1_RECT_F>> _vvRect;

	D2D1_RECT_F		_leftButton;							//������ �̵� ����
	D2D1_RECT_F		_rightButton;							//������ �̵� ������

	D2D1_RECT_F		_sizeUpWidth;							//Ÿ�� ������ ���� > ����ũ��
	D2D1_RECT_F		_sizeDownWidth;							//Ÿ�� ������ ���� > �����۰�
	D2D1_RECT_F		_sizeUpHeight;							//Ÿ�� ������ ���� > ����ũ��
	D2D1_RECT_F		_sizeDownHeight; 						//Ÿ�� ������ ���� > �����۰�

	tagCurrentTile_Object	_selectSampleTile;
	tagCurrentTile_Object	_tempObjectTile;

	UINT TILEX;
	UINT TILEY;

	UINT _saveX;
	UINT _saveY;

	int	_currentPage;
	bool _isTileSelect;

	//���콺ó���� ��Ʈ
	D2D1_RECT_F _sampleTileRange;

public:
	objectTool();
	~objectTool();

	HRESULT init();
	void release();
	void update();
	void render();

	void setSampleTile();
	void setTile();
	void setMap();

	void buttonsetting();

	void selectSampleMap();
	void mapSizeUpDown();

	void mapSave();
	void mapLoad();
};

