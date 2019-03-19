#pragma once
#include "gameNode.h"
#include "princess.h"

class mainScene : public gameNode
{
private: 
	princess* _princess;

	string _firstName;
	string _lastName;

	int _year;
	int _mon;
	int _day;
	int _dayday;


public:
	mainScene();
	~mainScene();

	HRESULT init();
	void release();
	void update();
	void render();

};

