#pragma once
#include "gameNode.h"
#include "data.h"

class status : public gameNode
{
private:
	string _name;
	string _teacher;
	int _tuition, _plusTuition;
	int _frameX, _frameY, _step;
	float _x, _y;

	vector<tagStatusData> _vStatus;

public:
	status();
	~status();

	HRESULT init();
	void release();
	void update();
	void render();

	void setStatus(string name, string teacher, int tuition, int plus, vector<tagStatusData> vStatus, int frameX, int frameY);
	void upgradeClass();
	string getStringClass();

	string getName() { return _name; }

	int getTuition() { return _tuition; }
	int getFrameIndex() { return _frameX; }
	void setXY(float x, float y) { _x = x, _y = y; }

	vector<tagStatusData> getStatus() { return _vStatus; }
};

