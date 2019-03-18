#include "stdafx.h"
#include "playGround.h"

playGround::playGround()
{
}


playGround::~playGround()
{
}

HRESULT playGround::init()
{
	gameNode::init(true);


	//============================================================================================= 이미지 추가
	//기본 이미지
	{
		//01. 배경
		IMAGEMANAGER->addImage("메인배경", L"image/bg.png", 800, 600);
		IMAGEMANAGER->addImage("메인달력", L"image/ui/UI_common_calendar.png", 180, 100);
		IMAGEMANAGER->addImage("메인스텟", L"image/ui/UI_common_state.png", 200, 218);
		IMAGEMANAGER->addFrameImage("year", L"image/ui/ui_year.png", 40, 200, 1, 10);
		IMAGEMANAGER->addFrameImage("mon", L"image/ui/ui_mon.png", 60, 240, 1, 12);
		IMAGEMANAGER->addFrameImage("day", L"image/ui/ui_day.png", 80, 1550, 1, 31);
		IMAGEMANAGER->addFrameImage("dayday", L"image/ui/ui_dayday.png", 60, 140, 1, 7);
	}
	//아이템
	{
		IMAGEMANAGER->addFrameImage("items", L"image/item/items.png", 273, 195, 7, 5);
	}

	// UI
	{
		// 01. 프레임이미지
		{
			// 프레임 1
			IMAGEMANAGER->addImage("프레임기본", L"image/ui/UI_base.png", 18, 18);
			IMAGEMANAGER->addImage("스케쥴박스_01", L"image/ui/UI_schedule_frame_box_01.png", 18, 18);
			IMAGEMANAGER->addImage("스케쥴박스_02", L"image/ui/UI_schedule_frame_box_02.png", 18, 18);
			IMAGEMANAGER->addImage("스케쥴박스_03", L"image/ui/UI_schedule_frame_box_03.png", 18, 18);
			IMAGEMANAGER->addImage("스케쥴박스_04", L"image/ui/UI_schedule_frame_box_04.png", 18, 18);
			IMAGEMANAGER->addImage("스케쥴박스_05", L"image/ui/UI_schedule_frame_box_05.png", 18, 18);
			IMAGEMANAGER->addImage("스케쥴박스_06", L"image/ui/UI_schedule_frame_box_06.png", 18, 18);
			IMAGEMANAGER->addImage("스케쥴박스_07", L"image/ui/UI_schedule_frame_box_07.png", 18, 18);
			IMAGEMANAGER->addImage("스케쥴박스_08", L"image/ui/UI_schedule_frame_box_08.png", 18, 18);
			// 프레임 2
			IMAGEMANAGER->addImage("선택박스_01", L"image/ui/UI_selectbox_01.png", 18, 18);
			IMAGEMANAGER->addImage("선택박스_02", L"image/ui/UI_selectbox_02.png", 18, 18);
			IMAGEMANAGER->addImage("선택박스_03", L"image/ui/UI_selectbox_03.png", 18, 18);
			IMAGEMANAGER->addImage("선택박스_04", L"image/ui/UI_selectbox_04.png", 18, 18);
			IMAGEMANAGER->addImage("선택박스_05", L"image/ui/UI_selectbox_05.png", 18, 18);
			IMAGEMANAGER->addImage("선택박스_06", L"image/ui/UI_selectbox_06.png", 18, 18);
			IMAGEMANAGER->addImage("선택박스_07", L"image/ui/UI_selectbox_07.png", 18, 18);
			IMAGEMANAGER->addImage("선택박스_08", L"image/ui/UI_selectbox_08.png", 18, 18);
			// 프레임 3
			IMAGEMANAGER->addImage("텍스트박스_01", L"image/ui/UI_textbox_01.png", 18, 18);
			IMAGEMANAGER->addImage("텍스트박스_02", L"image/ui/UI_textbox_02.png", 18, 18);
			IMAGEMANAGER->addImage("텍스트박스_03", L"image/ui/UI_textbox_03.png", 18, 18);
			IMAGEMANAGER->addImage("텍스트박스_04", L"image/ui/UI_textbox_04.png", 18, 18);
			IMAGEMANAGER->addImage("텍스트박스_05", L"image/ui/UI_textbox_05.png", 18, 18);
			IMAGEMANAGER->addImage("텍스트박스_06", L"image/ui/UI_textbox_06.png", 18, 18);
			IMAGEMANAGER->addImage("텍스트박스_07", L"image/ui/UI_textbox_07.png", 18, 18);
			IMAGEMANAGER->addImage("텍스트박스_08", L"image/ui/UI_textbox_08.png", 18, 18);
		}
	}

	//============================================================================================= 씬 추가

	{

		SCENEMANAGER->addScene("main", new mainScene);

	}
	SCENEMANAGER->changeScene("main");
	

	
	return S_OK;
}

void playGround::release()
{
	gameNode::release();
	
}

void playGround::update()
{
	gameNode::update();

	SCENEMANAGER->update();

}

void playGround::render()
{
	// Draw 시작 - 이 코드가 빠지면 D2D 출력 X
	D2DMANAGER->beginDraw();
	//===========================================================================
	//				##		여기에 코드 작성(Start)			##



	SCENEMANAGER->render();




	//				##			여기에 코드 작성(End)			##
	//===========================================================================
	//				##카메라 정보 마우스 정보 시간정보 출력	##===================
	WCHAR str[128];
	swprintf_s(str, L"cameraX : %d", CAMERA->getPosX());
	D2DMANAGER->drawText(str, CAMERA->getPosX(), CAMERA->getPosY() + 80);
	swprintf_s(str, L"cameraY : %d", CAMERA->getPosY());
	D2DMANAGER->drawText(str, CAMERA->getPosX(), CAMERA->getPosY() + 100);
	swprintf_s(str, L"mouseX : %.2f", _ptMouse.x);
	D2DMANAGER->drawText(str, CAMERA->getPosX(), CAMERA->getPosY() + 140);
	swprintf_s(str, L"mouseY : %.2f", _ptMouse.y);
	D2DMANAGER->drawText(str, CAMERA->getPosX(), CAMERA->getPosY() + 160);
	TIMEMANAGER->render();
	// Draw 끝 - 이 코드가 빠지면 D2D 출력 X
	D2DMANAGER->endDraw();
}