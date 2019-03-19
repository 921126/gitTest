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


	//============================================================================================= �̹��� �߰�
	//�⺻ �̹���
	{
		//01. ���
		IMAGEMANAGER->addImage("���ι��", L"image/bg.png", 800, 600);
		IMAGEMANAGER->addImage("���δ޷�", L"image/ui/UI_common_calendar.png", 180, 100);
		IMAGEMANAGER->addImage("���ν���", L"image/ui/UI_common_state.png", 200, 218);
		IMAGEMANAGER->addImage("���θ޴�", L"image/ui/ui_main_menu.png", 200, 120);
		IMAGEMANAGER->addFrameImage("year", L"image/ui/ui_year.png", 40, 200, 1, 10);
		IMAGEMANAGER->addFrameImage("mon", L"image/ui/ui_mon.png", 60, 240, 1, 12);
		IMAGEMANAGER->addFrameImage("day", L"image/ui/ui_day.png", 80, 1550, 1, 31);
		IMAGEMANAGER->addFrameImage("dayday", L"image/ui/ui_dayday.png", 60, 140, 1, 7);
	}
	//������
	{
		IMAGEMANAGER->addFrameImage("items", L"image/item/items.png", 273, 195, 7, 5);
	}

	// UI
	{
		// 01. �������̹���
		{
			// ������ 1
			IMAGEMANAGER->addImage("�����ӱ⺻", L"image/ui/UI_base.png", 18, 18);
			IMAGEMANAGER->addImage("������ڽ�_01", L"image/ui/UI_schedule_frame_box_01.png", 18, 18);
			IMAGEMANAGER->addImage("������ڽ�_02", L"image/ui/UI_schedule_frame_box_02.png", 18, 18);
			IMAGEMANAGER->addImage("������ڽ�_03", L"image/ui/UI_schedule_frame_box_03.png", 18, 18);
			IMAGEMANAGER->addImage("������ڽ�_04", L"image/ui/UI_schedule_frame_box_04.png", 18, 18);
			IMAGEMANAGER->addImage("������ڽ�_05", L"image/ui/UI_schedule_frame_box_05.png", 18, 18);
			IMAGEMANAGER->addImage("������ڽ�_06", L"image/ui/UI_schedule_frame_box_06.png", 18, 18);
			IMAGEMANAGER->addImage("������ڽ�_07", L"image/ui/UI_schedule_frame_box_07.png", 18, 18);
			IMAGEMANAGER->addImage("������ڽ�_08", L"image/ui/UI_schedule_frame_box_08.png", 18, 18);
			// ������ 2
			IMAGEMANAGER->addImage("���ùڽ�_01", L"image/ui/UI_selectbox_01.png", 18, 18);
			IMAGEMANAGER->addImage("���ùڽ�_02", L"image/ui/UI_selectbox_02.png", 18, 18);
			IMAGEMANAGER->addImage("���ùڽ�_03", L"image/ui/UI_selectbox_03.png", 18, 18);
			IMAGEMANAGER->addImage("���ùڽ�_04", L"image/ui/UI_selectbox_04.png", 18, 18);
			IMAGEMANAGER->addImage("���ùڽ�_05", L"image/ui/UI_selectbox_05.png", 18, 18);
			IMAGEMANAGER->addImage("���ùڽ�_06", L"image/ui/UI_selectbox_06.png", 18, 18);
			IMAGEMANAGER->addImage("���ùڽ�_07", L"image/ui/UI_selectbox_07.png", 18, 18);
			IMAGEMANAGER->addImage("���ùڽ�_08", L"image/ui/UI_selectbox_08.png", 18, 18);
			// ������ 3
			IMAGEMANAGER->addImage("�ؽ�Ʈ�ڽ�_01", L"image/ui/UI_textbox_01.png", 18, 18);
			IMAGEMANAGER->addImage("�ؽ�Ʈ�ڽ�_02", L"image/ui/UI_textbox_02.png", 18, 18);
			IMAGEMANAGER->addImage("�ؽ�Ʈ�ڽ�_03", L"image/ui/UI_textbox_03.png", 18, 18);
			IMAGEMANAGER->addImage("�ؽ�Ʈ�ڽ�_04", L"image/ui/UI_textbox_04.png", 18, 18);
			IMAGEMANAGER->addImage("�ؽ�Ʈ�ڽ�_05", L"image/ui/UI_textbox_05.png", 18, 18);
			IMAGEMANAGER->addImage("�ؽ�Ʈ�ڽ�_06", L"image/ui/UI_textbox_06.png", 18, 18);
			IMAGEMANAGER->addImage("�ؽ�Ʈ�ڽ�_07", L"image/ui/UI_textbox_07.png", 18, 18);
			IMAGEMANAGER->addImage("�ؽ�Ʈ�ڽ�_08", L"image/ui/UI_textbox_08.png", 18, 18);
		}

		// 02. ����
		{
			IMAGEMANAGER->addImage("���θ޴�����", L"image/ui/ui_menu_select.png", 50, 40);
			IMAGEMANAGER->addImage("������޴�����", L"image/ui/ui_scehdule_select.png", 200, 40);
		}
	}
	// ĳ����
	{

	}
	//============================================================================================= �� �߰�

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
	UIMANAGER->update();
}

void playGround::render()
{
	// Draw ���� - �� �ڵ尡 ������ D2D ��� X
	D2DMANAGER->beginDraw();
	//===========================================================================
	//				##		���⿡ �ڵ� �ۼ�(Start)			##



	SCENEMANAGER->render();
	UIMANAGER->render();



	//				##			���⿡ �ڵ� �ۼ�(End)			##
	//===========================================================================
	//				##ī�޶� ���� ���콺 ���� �ð����� ���	##===================
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
	// Draw �� - �� �ڵ尡 ������ D2D ��� X
	D2DMANAGER->endDraw();
}