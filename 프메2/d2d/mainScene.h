#pragma once
#include "gameNode.h"
#include "princess.h"

class mainScene : public gameNode
{
private: 
	princess* _princess;

	//========== 개인정보
	string _firstName;
	string _lastName;
	string _dietType;

	int _age;
	//==================

	//========== 날짜관련
	int _year;
	int _mon;
	int _day;
	int _dayday;
	int _lastDay;

	tagImage _iyear;
	tagImage _imon;
	tagImage _iday;
	tagImage _idayday;
	//==================


public:
	mainScene();
	~mainScene();

	HRESULT init();
	void release();
	void update();
	void render();


	//void mainCalendarRender();	//달력그리기
};

