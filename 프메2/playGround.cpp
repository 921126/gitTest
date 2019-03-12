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

	//================================================================================= �̹��� ��� 
	{
		//0. ��ŸƮ ȭ��
		{
			IMAGEMANAGER->addImage("���", L"image/startScene_bg.png", 800, 600);
		}
		//0-1. ĳ���� ����ȭ��
		{
			IMAGEMANAGER->addFrameImage("ĳ���ͻ�������", L"image/ui/ui_selectbox.png", 1600, 600, 2, 1);
			IMAGEMANAGER->addFrameImage("ĳ���ͻ�������2", L"image/ui/ui_brithday.png", 1600, 600, 2, 1);

			//�ʼ�
			{
				IMAGEMANAGER->addFrameImage("�ʼ�_0", L"image/text/txt_0.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("�ʼ�_1", L"image/text/txt_1.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("�ʼ�_2", L"image/text/txt_2.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("�ʼ�_3", L"image/text/txt_3.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("�ʼ�_4", L"image/text/txt_4.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("�ʼ�_5", L"image/text/txt_5.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("�ʼ�_6", L"image/text/txt_6.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("�ʼ�_7", L"image/text/txt_7.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("�ʼ�_8", L"image/text/txt_8.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("�ʼ�_9", L"image/text/txt_9.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("�ʼ�_10", L"image/text/txt_10.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("�ʼ�_11", L"image/text/txt_11.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("�ʼ�_12", L"image/text/txt_12.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("�ʼ�_13", L"image/text/txt_13.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("�ʼ�_14", L"image/text/txt_14.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("�ʼ�_15", L"image/text/txt_15.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("�ʼ�_16", L"image/text/txt_16.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("�ʼ�_17", L"image/text/txt_17.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("�ʼ�_18", L"image/text/txt_18.png", 60, 30, 2, 1);
			}
		}
		//1. ���� ȭ��
		{
			IMAGEMANAGER->addImage("���ι��", L"image/ui/UI_common_background.png", 800, 600);
			IMAGEMANAGER->addImage("���δ޷�", L"image/ui/UI_common_calendar.png", 180, 100);
			IMAGEMANAGER->addImage("����â", L"image/ui/UI_common_state.png", 200, 218);
			IMAGEMANAGER->addFrameImage("����â", L"image/ui/UI_common_select.png", 400, 120, 2, 1);

			//1-1. ��������Ʈ 
			{
				IMAGEMANAGER->addFrameImage("�������", L"image/icon/icon_shoplist.png", 240, 40, 6, 1);
			}
			//1-6. �� �湮
			{
				IMAGEMANAGER->addImage("���̹���", L"image/ui/UI_castle.png", 290, 181);

				IMAGEMANAGER->addImage("������", L"image/face/UI_face_01.png", 140, 144);
			}
		}
		//2. ĳ����
		{
			IMAGEMANAGER->addFrameImage("10��⺻�ʾ�", L"image/chara/10age/chara_10age_common_clothes_face.png", 784, 131, 4, 1);
			IMAGEMANAGER->addFrameImage("10�쿩���ʾ�", L"image/chara/10age/chara_10age_summer_clothes_face.png", 784, 131, 4, 1);
		
			IMAGEMANAGER->addFrameImage("12���", L"image/chara/12age/12age_clothes.png", 365, 1357, 1, 4);
		}


		//etc ����
		{
			IMAGEMANAGER->addFrameImage("�����̵���ư", L"image/ui/mapTool_button_01.png", 200, 80, 2, 2);
			IMAGEMANAGER->addFrameImage("����������ư", L"image/ui/mapTool_button_02.png", 420, 160, 2, 4);

			//����
			IMAGEMANAGER->addFrameImage(TERRAIN_INFO[TERRAIN_ROAD], L"image/tile/tile_01.png", 240, 240, 6, 6);
			IMAGEMANAGER->addFrameImage(TERRAIN_INFO[TERRAIN_ROAD2], L"image/tile/tile_02.png", 240, 240, 6, 6);
			//������Ʈ
			IMAGEMANAGER->addFrameImage(OBJECT_INFO[OBJECT_1], L"image/object/object_01.png", 240, 240, 6, 6);
			IMAGEMANAGER->addFrameImage(OBJECT_INFO[OBJECT_2], L"image/object/object_02.png", 240, 240, 6, 6);
			IMAGEMANAGER->addFrameImage(OBJECT_INFO[OBJECT_3], L"image/object/object_03.png", 240, 240, 6, 6);
			IMAGEMANAGER->addFrameImage(OBJECT_INFO[OBJECT_4], L"image/object/object_04.png", 240, 240, 6, 6);
			IMAGEMANAGER->addFrameImage(OBJECT_INFO[OBJECT_5], L"image/object/object_05.png", 240, 240, 6, 6);
			IMAGEMANAGER->addFrameImage(OBJECT_INFO[OBJECT_6], L"image/object/object_06.png", 240, 240, 6, 6);
			IMAGEMANAGER->addFrameImage(OBJECT_INFO[OBJECT_7], L"image/object/object_07.png", 240, 240, 6, 6);
			IMAGEMANAGER->addFrameImage(OBJECT_INFO[OBJECT_8], L"image/object/object_08.png", 240, 240, 6, 6);
			IMAGEMANAGER->addFrameImage(OBJECT_INFO[OBJECT_9], L"image/object/object_09.png", 240, 240, 6, 6);
			IMAGEMANAGER->addFrameImage(OBJECT_INFO[OBJECT_10], L"image/object/object_10.png", 240, 240, 6, 6);
		}
	}
	//================================================================================= ������ �̹���
	{
		// 1. ������ �ڽ�

		IMAGEMANAGER->addImage("�����ӱ⺻", L"image/ui/UI_schedule_frame_box_09.png", 18, 18);
		IMAGEMANAGER->addImage("������ڽ�_01", L"image/ui/UI_schedule_frame_box_01.png", 18, 18);
		IMAGEMANAGER->addImage("������ڽ�_02", L"image/ui/UI_schedule_frame_box_02.png", 18, 18);
		IMAGEMANAGER->addImage("������ڽ�_03", L"image/ui/UI_schedule_frame_box_03.png", 18, 18);
		IMAGEMANAGER->addImage("������ڽ�_04", L"image/ui/UI_schedule_frame_box_04.png", 18, 18);
		IMAGEMANAGER->addImage("������ڽ�_05", L"image/ui/UI_schedule_frame_box_05.png", 18, 18);
		IMAGEMANAGER->addImage("������ڽ�_06", L"image/ui/UI_schedule_frame_box_06.png", 18, 18);
		IMAGEMANAGER->addImage("������ڽ�_07", L"image/ui/UI_schedule_frame_box_07.png", 18, 18);
		IMAGEMANAGER->addImage("������ڽ�_08", L"image/ui/UI_schedule_frame_box_08.png", 18, 18);

		//2. ���� �ڽ�

		IMAGEMANAGER->addImage("���ùڽ�_01", L"image/ui/UI_selectbox_01.png", 18, 18);
		IMAGEMANAGER->addImage("���ùڽ�_02", L"image/ui/UI_selectbox_02.png", 18, 18);
		IMAGEMANAGER->addImage("���ùڽ�_03", L"image/ui/UI_selectbox_03.png", 18, 18);
		IMAGEMANAGER->addImage("���ùڽ�_04", L"image/ui/UI_selectbox_04.png", 18, 18);
		IMAGEMANAGER->addImage("���ùڽ�_05", L"image/ui/UI_selectbox_05.png", 18, 18);
		IMAGEMANAGER->addImage("���ùڽ�_06", L"image/ui/UI_selectbox_06.png", 18, 18);
		IMAGEMANAGER->addImage("���ùڽ�_07", L"image/ui/UI_selectbox_07.png", 18, 18);
		IMAGEMANAGER->addImage("���ùڽ�_08", L"image/ui/UI_selectbox_08.png", 18, 18);

		//3. �ؽ�Ʈ �ڽ�

		IMAGEMANAGER->addImage("�ؽ�Ʈ�ڽ�_01", L"image/ui/UI_textbox_01.png", 18, 18);
		IMAGEMANAGER->addImage("�ؽ�Ʈ�ڽ�_02", L"image/ui/UI_textbox_02.png", 18, 18);
		IMAGEMANAGER->addImage("�ؽ�Ʈ�ڽ�_03", L"image/ui/UI_textbox_03.png", 18, 18);
		IMAGEMANAGER->addImage("�ؽ�Ʈ�ڽ�_04", L"image/ui/UI_textbox_04.png", 18, 18);
		IMAGEMANAGER->addImage("�ؽ�Ʈ�ڽ�_05", L"image/ui/UI_textbox_05.png", 18, 18);
		IMAGEMANAGER->addImage("�ؽ�Ʈ�ڽ�_06", L"image/ui/UI_textbox_06.png", 18, 18);
		IMAGEMANAGER->addImage("�ؽ�Ʈ�ڽ�_07", L"image/ui/UI_textbox_07.png", 18, 18);
		IMAGEMANAGER->addImage("�ؽ�Ʈ�ڽ�_08", L"image/ui/UI_textbox_08.png", 18, 18);

		//����
		IMAGEMANAGER->addImage("������", L"image/ui/UI_select.png", 168, 30);
	}

	FRAMEMANAGER->addFrame("�׽�Ʈ1", 100, 100, 10, 10);
	//================================================================================= �� ���
	{
		SCENEMANAGER->addScene("����", new mapTool);
		SCENEMANAGER->addScene("������Ʈ��", new objectTool);
		SCENEMANAGER->addScene("�׽�Ʈ��", new testtttt);

		SCENEMANAGER->addScene("��ŸƮ��", new startScene);
		SCENEMANAGER->addScene("���ѷα׾�", new prologueScene);
		SCENEMANAGER->addScene("ĳ���ͻ�����", new newPlayerScene);
		SCENEMANAGER->addScene("���ξ�", new mainScene);


	}

	SCENEMANAGER->changeScene("���ξ�");
	
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