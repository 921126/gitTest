#pragma once
#include "stdafx.h"

#define TILE_SIZE 40
#define SAMPLETILE 6

//타일
#define ATTR_NONE		0x00000000UL		//NONE 아무것도 아님
#define ATTR_MOVE		0x00000001UL		//이동 가능한 길
#define ATTR_UNMOVE		0x00000002UL		//이동 불가능한 길
#define ATTR_SWAMP		0X00000004UL		//이동 가능한 늪지대
#define ATTR_PORTAL		0x00000008UL		//이동 하는 포탈

//오브젝트

#define ATTR_TREE		0X00000010UL		//나무 
#define ATTR_SIGN		0X00000020UL		//표지판 
#define ATTR_RAMPART	0X00000040UL		//성벽
#define ATTR_TREASURE	0X00000080UL		//보물상자
#define ATTR_RELIC		0X00000100UL		//유물
#define ATTR_ROCK		0X00000200UL		//바위
#define ATTR_FOREST		0X00000400UL		//숲


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
static string TERRAIN_INFO[TERRAIN_COUNT]	= { "none" , "맵타일_01", "맵타일_02" };
static string OBJECT_INFO[OBJECT_COUNT]		= { "none" , "오브젝트_01", "오브젝트_02" ,"오브젝트_03" ,"오브젝트_04" ,"오브젝트_05" ,"오브젝트_06" ,"오브젝트_07" ,"오브젝트_08","오브젝트_09","오브젝트_10" };

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
	UINT	terrainFrameX;			//0으로 초기화
	UINT	terrainFrameY;			//0으로 초기화
	UINT	objectImageIndex;		//OBJECT_NAME_NONE 으로 초기화
	UINT	objectFrameX;			//0으로 초기화
	UINT	objectFrameY;			//0으로 초기화
	DWORD	attr;					//이건 ATTR_NONE으로 초기화 후에 시작합시다

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

//타일의 포인터를 LPTILE이라고 하겠다
typedef class tagTile *LPTILE;