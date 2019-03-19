#include "stdafx.h"
#include "status.h"


status::status()
{
}


status::~status()
{
}

HRESULT status::init()
{
	return S_OK;
}

void status::release()
{
}

void status::update()
{
}

void status::render()
{
}

void status::setStatus(string name, string teacher, int tuition, int plus, vector<tagStatusData> vStatus, int frameX, int frameY)
{
	_name = name;
	_teacher = teacher;
	_tuition = tuition;
	_vStatus = vStatus;
	_frameX = frameX;
	_frameY = frameY;
	_step = 0;
}

void status::upgradeClass()
{
	if (_step < 4)
	{
		_step += 1;
	}
}

string status::getStringClass()
{
	if (_step == 0) return "초급";
	if (_step == 1) return "중급";
	if (_step == 2) return "상급";
	if (_step == 3) return "고급";
}
