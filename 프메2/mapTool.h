#pragma once
#include "gameNode.h"
#include "TileNode.h"
#include <vector>

#define TILE_IMG_NUM		2
#define SAMPLE_TILE_SIZE	TILE_SIZE * SAMPLETILE			//샘플타일 사이즈
#define SAMPLE_TILE_START	(WINSIZEX - SAMPLE_TILE_SIZE)	//샘플타일 시작지점
#define CAMERA_RANGE		13 * TILE_SIZE					//카메라 이동 범위

//샘플 선택 시 저장할 변수
struct tagSampleTile
{
	D2D1_RECT_F samplerc;
	int frameX;
	int frameY;
};
struct tagCurrentTile
{
	bool isObject = false;
	int currentX = 0;
	int currentY = 0;
};
class mapTool : public gameNode
{
private:

	image*			_sampleImg[2];							//샘플타일 개수
	tagSampleTile	_sampleTile[SAMPLETILE][SAMPLETILE];	//샘플타일 배열

	tagCurrentTile	_selectSampleTile;						//선택한 샘플타일
	tagCurrentTile	_selectObjectTile;						//선택한 오브젝트타일

	//맵 이중백터
	vector<vector<tagTile*>>	_vvTile;					//타일
	vector<vector<D2D1_RECT_F>> _vvRect;					//상자

	UINT TILEX;
	UINT TILEY;

	UINT _saveX;
	UINT _saveY;

	//버튼
	D2D1_RECT_F		_leftButton;							//페이지 이동 왼쪽
	D2D1_RECT_F		_rightButton;							//페이지 이동 오른쪽

	D2D1_RECT_F		_sizeUpWidth;							//타일 사이즈 변경 > 가로크게
	D2D1_RECT_F		_sizeDownWidth;							//타일 사이즈 변경 > 가로작게
	D2D1_RECT_F		_sizeUpHeight;							//타일 사이즈 변경 > 세로크게
	D2D1_RECT_F		_sizeDownHeight; 						//타일 사이즈 변경 > 세로작게

	int				_currentPage;							//샘플타일 페이지

	//샘플타일 선택 확인용 변수
	bool _isTileSelect;										//너 타일선택했니?
	bool _isDrag;											//너 드레그할꺼니?


	//마우스처리용 렉트
	D2D1_RECT_F _sampleTileRange;

public:
	mapTool();
	~mapTool();

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

private:

	DWORD setAttribute(string imgName, UINT frameX, UINT frameY);

};

