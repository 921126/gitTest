#pragma once
#include "gameNode.h"
#include "dataNode.h"

enum NEWPLAYER_STATE
{
	NEW_FATHER_NAME_INPUT,
	NEW_DAUGHTER_NAME_INPUT,
	NEW_DAUGHTER_BRIT_SELECT,
	NEW_FATHER_AGE_SELECT,
	NEW_FATHER_BRIT_SELECT,
	NEW_DAUGTHER_BTYPE_SELECT,
};

class princess;

class newPlayerScene : public gameNode
{
private:
	princess* _princess;

	tagInfo _princessInfo;
	tagStatus _princessStatus;
	tagEtc _calendar[12][42];
	tagEtc _fatherAge[10];
	tagEtc _blood[4];

	NEWPLAYER_STATE _nState;

	string _fatherName;
	string _daughterName;

	image* _img;

	list<int>			_lfatherAge;
	list<int>::iterator _ilfatherAge;

	int _fatherage;
	int _fatherYear;
	int _count;

	D2D1_RECT_F _clearBtn;
	D2D1_RECT_F _returnBtn;

public:
	newPlayerScene();
	~newPlayerScene();

	HRESULT init();
	void release();
	void update();
	void render();

	void fatherNameCreat();
	void dautherNameCreat();
};

