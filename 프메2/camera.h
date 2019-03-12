#pragma once
#include "singletonBase.h"

#define CAMERA_SPEED 10.0f

class camera : public singletonBase<camera>
{
private:

	float _posX;
	float _posY;
	int _maxX;
	int _maxY;

public:
	camera();
	~camera();

	HRESULT init();
	HRESULT init(float x, float y, int maxX, int maxY);
	void release();
	void update();
	void render();
	void cameraMove(float x, float y);
	void mapToolMove();




	//==================================== get 함수
	float getPosX()			{ return _posX; }
	float getPosY()			{ return _posY; }
	float getMaxX()			{ return _maxX; }
	float getMaxY()			{ return _maxY; }
	//===================================== set 함수
	void setPosX(float x)	{ _posX = x; }
	void setPosY(float y)	{ _posY = y; }
	void setMaxX(int x)		{ _maxX = x; }
	void setMaxY(int y)		{ _maxY = y; }


};

