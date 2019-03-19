#include "stdafx.h"
#include "frame.h"


frame::frame()
	:_frameInfo(nullptr)
{
}


frame::~frame()
{
}

HRESULT frame::init(UINT destX, UINT destY, UINT frameWidth, UINT frameHeight)
{
	if (_frameInfo != NULL) release();

	_frameInfo					= new FRAME_BOX_INFO;
	_frameInfo->destX			= destX;
	_frameInfo->destY			= destY;
	_frameInfo->frameWidth		= frameWidth;
	_frameInfo->frameHeight		= frameHeight;

	return S_OK;
}

void frame::release()
{
	if (_frameInfo)
	{
		SAFE_DELETE(_frameInfo);
	}
}

void frame::update()
{
}

void frame::render(string imageName)
{

	//상단 오른쪽 왼쪽
	IMAGEMANAGER->findImage(imageName + "_01")->render(_frameInfo->destX + CAMERA->getPosX(), _frameInfo->destY + CAMERA->getPosY(), 1);
	IMAGEMANAGER->findImage(imageName + "_03")->render(_frameInfo->destX + ((_frameInfo->frameWidth - 1) * 18) + CAMERA->getPosX(), _frameInfo->destY + CAMERA->getPosY(), 1);

	//하단 오른쪽 왼쪽
	IMAGEMANAGER->findImage(imageName + "_06")->render(_frameInfo->destX + CAMERA->getPosX(), _frameInfo->destY + (_frameInfo->frameHeight - 1) * 18 + CAMERA->getPosY(), 1);
	IMAGEMANAGER->findImage(imageName + "_08")->render(_frameInfo->destX + ((_frameInfo->frameWidth - 1) * 18) + CAMERA->getPosX(), _frameInfo->destY + (_frameInfo->frameHeight - 1) * 18 + CAMERA->getPosY(), 1);


	//상단 길게 
	IMAGEMANAGER->findImage(imageName + "_02")->render(_frameInfo->destX + 18 + CAMERA->getPosX(),
		_frameInfo->destY + CAMERA->getPosY(),
		(_frameInfo->frameWidth - 2) * 18,
		18,
		0, 0, 18, 18, 1);
	//하단 길게 
	IMAGEMANAGER->findImage(imageName + "_07")->render(_frameInfo->destX + 18 + CAMERA->getPosX(),
		_frameInfo->destY + ((_frameInfo->frameHeight - 1) * 18) + CAMERA->getPosY(),
		(_frameInfo->frameWidth - 2) * 18,
		18,
		0, 0, 18, 18, 1);
	//왼쪽 길게
	IMAGEMANAGER->findImage(imageName + "_04")->render(_frameInfo->destX + CAMERA->getPosX(),
		_frameInfo->destY + 18 + CAMERA->getPosY(),
		18,
		(_frameInfo->frameHeight - 2) * 18,
		0, 0, 18, 18, 1);
	//오른쪽 길게
	IMAGEMANAGER->findImage(imageName + "_05")->render(_frameInfo->destX + ((_frameInfo->frameWidth - 1) * 18) + CAMERA->getPosX(),
		_frameInfo->destY + 18 + CAMERA->getPosY(),
		18,
		(_frameInfo->frameHeight - 2) * 18,
		0, 0, 18, 18, 1);

	IMAGEMANAGER->findImage("프레임기본")->render(_frameInfo->destX + 18 + CAMERA->getPosX(),				//그려주기 시작할 지점 
		_frameInfo->destY + 18 + CAMERA->getPosY(),				//그려주기 시작할 지점
		(_frameInfo->frameWidth - 2) * 18,							//늘릴 크기
		(_frameInfo->frameHeight - 2) * 18,							//늘릴 크기
		0,
		0, 18, 18, 1);
}
