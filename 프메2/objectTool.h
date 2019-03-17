#pragma once
#include "gameNode.h"
#include "TileNode.h"
#include "mapTool.h"
#include <vector>
#include <assert.h>

#define OBJECT_IMG_NUM		22
#define SAMPLE_TILE_SIZE	TILE_SIZE * SAMPLETILE			//샘플타일 사이즈
#define SAMPLE_TILE_START	(WINSIZEX - SAMPLE_TILE_SIZE)	//샘플타일 시작지점
#define CAMERA_RANGE		13 * TILE_SIZE					//카메라 이동 범위

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

	D2D1_RECT_F		_leftButton;							//페이지 이동 왼쪽
	D2D1_RECT_F		_rightButton;							//페이지 이동 오른쪽

	D2D1_RECT_F		_sizeUpWidth;							//타일 사이즈 변경 > 가로크게
	D2D1_RECT_F		_sizeDownWidth;							//타일 사이즈 변경 > 가로작게
	D2D1_RECT_F		_sizeUpHeight;							//타일 사이즈 변경 > 세로크게
	D2D1_RECT_F		_sizeDownHeight; 						//타일 사이즈 변경 > 세로작게

	tagCurrentTile_Object	_selectSampleTile;
	tagCurrentTile_Object	_tempObjectTile;

	UINT TILEX;
	UINT TILEY;

	UINT _saveX;
	UINT _saveY;

	int	_currentPage;
	bool _isTileSelect;

	//마우스처리용 렉트
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

