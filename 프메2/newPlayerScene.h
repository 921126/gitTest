#pragma once
#include "gameNode.h"

#define BASE_CODE 0x3131 //0xac00

enum NEWPLAYER
{
	NEWPLAYER_FAMILY_NAME,
	NEWPLAYER_DAUGHTER_NAME,
	NEWPLAYER_DAUGHTER_BIRTHDAY,
	NEWPLAYER_AGE,
	NEWPLAYER_BIRTHDAY,
	NEWPLAYER_DAUGHTER_BLOODYTYPE,
};
enum CHO_SELECT
{
	CHO_0,
	CHO_1,
	CHO_2,
	CHO_3,
	CHO_4,
	CHO_5,
	CHO_6,
	CHO_7,
	CHO_8,
	CHO_9,
	CHO_10,
	CHO_11,
	CHO_12,
	CHO_13,
	CHO_14,
	CHO_15,
	CHO_16,
	CHO_17,
	CHO_18,

	CHO_NONE = 99
};
class newPlayerScene : public gameNode
{
private: 

	NEWPLAYER _step;
	CHO_SELECT _chosung;

	D2D1_RECT_F _cho[19];
	D2D1_RECT_F _jung[21];
	D2D1_RECT_F _jong[28];


	int _selectCho;
	int _selectjung;
	int _selectjong;

	int _hagul; 

	int _nameSelectNum;

	string _name;

public:
	newPlayerScene();
	~newPlayerScene();

	HRESULT init();
	void release();
	void update();
	void render();


	void choSelect();
	void choRender();

	void hangul();
};

