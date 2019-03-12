#pragma once
#include "stdafx.h"

#define TILE_SIZE 40
#define SAMPLETILE 6

//Ÿ��
#define ATTR_NONE		0x00000000UL		//NONE �ƹ��͵� �ƴ�
#define ATTR_MOVE		0x00000001UL		//�̵� ������ ��
#define ATTR_UNMOVE		0x00000002UL		//�̵� �Ұ����� ��
#define ATTR_SWAMP		0X00000004UL		//�̵� ������ ������
#define ATTR_PORTAL		0x00000008UL		//�̵� �ϴ� ��Ż

//������Ʈ

#define ATTR_TREE		0X00000010UL		//���� 
#define ATTR_SIGN		0X00000020UL		//ǥ���� 
#define ATTR_RAMPART	0X00000040UL		//����
#define ATTR_TREASURE	0X00000080UL		//��������
#define ATTR_RELIC		0X00000100UL		//����
#define ATTR_ROCK		0X00000200UL		//����
#define ATTR_FOREST		0X00000400UL		//��


enum TERRAIN_INFO
{
	TERRAIN_NONE,
	TERRAIN_ROAD,
	TERRAIN_ROAD2,

	TERRAIN_COUNT
};
enum OBJECT_INFO
{
	OBJECT_NONE,
	OBJECT_1,
	OBJECT_2,
	OBJECT_3,
	OBJECT_4,
	OBJECT_5,
	OBJECT_6,
	OBJECT_7,
	OBJECT_8,
	OBJECT_9,
	OBJECT_10,

	OBJECT_COUNT
};
static string TERRAIN_INFO[TERRAIN_COUNT]	= { "none" , "��Ÿ��_01", "��Ÿ��_02" };
static string OBJECT_INFO[OBJECT_COUNT]		= { "none" , "������Ʈ_01", "������Ʈ_02" ,"������Ʈ_03" ,"������Ʈ_04" ,"������Ʈ_05" ,"������Ʈ_06" ,"������Ʈ_07" ,"������Ʈ_08","������Ʈ_09","������Ʈ_10" };

typedef class tagTile
{
public:

	tagTile() :terrainImageIndex(NULL),
		objectImageIndex(NULL),
		terrainFrameX(NULL),
		terrainFrameY(NULL),
		objectFrameX(NULL),
		objectFrameY(NULL),
		attr(NULL)
	{};
	~tagTile()
	{};

	UINT	terrainImageIndex;
	UINT	terrainFrameX;			//0���� �ʱ�ȭ
	UINT	terrainFrameY;			//0���� �ʱ�ȭ
	UINT	objectImageIndex;		//OBJECT_NAME_NONE ���� �ʱ�ȭ
	UINT	objectFrameX;			//0���� �ʱ�ȭ
	UINT	objectFrameY;			//0���� �ʱ�ȭ
	DWORD	attr;					//�̰� ATTR_NONE���� �ʱ�ȭ �Ŀ� �����սô�

	void setTile(tagTile tile)
	{
		if (tile.terrainImageIndex > 0)
			terrainImageIndex = tile.terrainImageIndex;
		terrainFrameX = tile.terrainFrameX;
		terrainFrameY = tile.terrainFrameY;
		if (tile.objectImageIndex > 0)
			objectImageIndex = tile.objectImageIndex;
		objectFrameX = tile.objectFrameX;
		objectFrameY = tile.objectFrameY;
		attr = tile.attr;
	}
};

//Ÿ���� �����͸� LPTILE�̶�� �ϰڴ�
typedef class tagTile *LPTILE;