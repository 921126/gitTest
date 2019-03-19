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

	NEWPLAYER_STATE _nState;

	string _fatherName;
	string _daughterName;

	tagEtc _calendar[12][42];
	image* _img;

	tagEtc _fatherAge[10];
	list<int>			_lfatherAge;
	list<int>::iterator _ilfatherAge;

	int _fatherage;
	int _fatherYear;

	tagEtc _blood[4];
	int _count;

public:
	newPlayerScene();
	~newPlayerScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

