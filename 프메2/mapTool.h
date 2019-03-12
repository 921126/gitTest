#pragma once
#include "gameNode.h"
#include "TileNode.h"
#include <vector>

#define TILE_IMG_NUM		2
#define SAMPLE_TILE_SIZE	TILE_SIZE * SAMPLETILE			//����Ÿ�� ������
#define SAMPLE_TILE_START	(WINSIZEX - SAMPLE_TILE_SIZE)	//����Ÿ�� ��������
#define CAMERA_RANGE		13 * TILE_SIZE					//ī�޶� �̵� ����

//���� ���� �� ������ ����
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

	image*			_sampleImg[2];							//����Ÿ�� ����
	tagSampleTile	_sampleTile[SAMPLETILE][SAMPLETILE];	//����Ÿ�� �迭

	tagCurrentTile	_selectSampleTile;						//������ ����Ÿ��
	tagCurrentTile	_selectObjectTile;						//������ ������ƮŸ��

	//�� ���߹���
	vector<vector<tagTile*>>	_vvTile;					//Ÿ��
	vector<vector<D2D1_RECT_F>> _vvRect;					//����

	UINT TILEX;
	UINT TILEY;

	UINT _saveX;
	UINT _saveY;

	//��ư
	D2D1_RECT_F		_leftButton;							//������ �̵� ����
	D2D1_RECT_F		_rightButton;							//������ �̵� ������

	D2D1_RECT_F		_sizeUpWidth;							//Ÿ�� ������ ���� > ����ũ��
	D2D1_RECT_F		_sizeDownWidth;							//Ÿ�� ������ ���� > �����۰�
	D2D1_RECT_F		_sizeUpHeight;							//Ÿ�� ������ ���� > ����ũ��
	D2D1_RECT_F		_sizeDownHeight; 						//Ÿ�� ������ ���� > �����۰�

	int				_currentPage;							//����Ÿ�� ������

	//����Ÿ�� ���� Ȯ�ο� ����
	bool _isTileSelect;										//�� Ÿ�ϼ����ߴ�?
	bool _isDrag;											//�� �巹���Ҳ���?


	//���콺ó���� ��Ʈ
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

