#pragma once
#include "gameNode.h"
#include "data.h"

class player : public gameNode
{
private:

	tagPlayerInfo		_info;
	tagPlayerStatus		_status;
	tagBody				_bobyInfo;
	tagImg				_face, _boby;
	tagDate				_date;

public:
	player();
	~player();
};

