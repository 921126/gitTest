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

	image* _img;

	int _fatherage;
	int _fatherYear;
	int _fathermon;
	int _fatherday;
	int _count;

	D2D1_RECT_F _clearBtn;
	bool _isClear;
	D2D1_RECT_F _returnBtn;

	D2D1_RECT_F _1mon[31];
	D2D1_RECT_F _2mon[29];
	D2D1_RECT_F _3mon[31];
	D2D1_RECT_F _4mon[30];
	D2D1_RECT_F _5mon[31];
	D2D1_RECT_F _6mon[30];
	D2D1_RECT_F _7mon[31];
	D2D1_RECT_F _8mon[31];
	D2D1_RECT_F _9mon[30];
	D2D1_RECT_F _10mon[31];
	D2D1_RECT_F _11mon[30];
	D2D1_RECT_F _12mon[31];

	D2D1_RECT_F _fatherAge[10];
	bool _isAgeSelect[10];

	D2D1_RECT_F _bloodyType[4];
	bool _isbtypeSelect[4];
	int _bloodType;

	bool _isSelect[31];
	bool _isSelect2[29];
	bool _isSelect3[31];
	bool _isSelect4[30];
	bool _isSelect5[31];
	bool _isSelect6[30];
	bool _isSelect7[31];
	bool _isSelect8[31];
	bool _isSelect9[30];
	bool _isSelect10[31];
	bool _isSelect11[30];
	bool _isSelect12[31];


public:
	newPlayerScene();
	~newPlayerScene();

	HRESULT init();
	void release();
	void update();
	void render();

	void fatherNameInput();
	void fatherNameRender();

	void daughterNameInput();
	void daughterNAmeRender();

	void BrithDayCalendar();
	void BrithDayCalendarSelect();
	void BrithDayCalendarSelect2();
	void statusSetting();
	void BrithDayCalendarRender();
};

