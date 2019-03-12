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

	//================================================================================= 이미지 등록 
	{
		//0. 스타트 화면
		{
			IMAGEMANAGER->addImage("배경", L"image/startScene_bg.png", 800, 600);
		}
		//0-1. 캐릭터 생성화면
		{
			IMAGEMANAGER->addFrameImage("캐릭터생성선택", L"image/ui/ui_selectbox.png", 1600, 600, 2, 1);
			IMAGEMANAGER->addFrameImage("캐릭터생성선택2", L"image/ui/ui_brithday.png", 1600, 600, 2, 1);

			//초성
			{
				IMAGEMANAGER->addFrameImage("초성_0", L"image/text/txt_0.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("초성_1", L"image/text/txt_1.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("초성_2", L"image/text/txt_2.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("초성_3", L"image/text/txt_3.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("초성_4", L"image/text/txt_4.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("초성_5", L"image/text/txt_5.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("초성_6", L"image/text/txt_6.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("초성_7", L"image/text/txt_7.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("초성_8", L"image/text/txt_8.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("초성_9", L"image/text/txt_9.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("초성_10", L"image/text/txt_10.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("초성_11", L"image/text/txt_11.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("초성_12", L"image/text/txt_12.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("초성_13", L"image/text/txt_13.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("초성_14", L"image/text/txt_14.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("초성_15", L"image/text/txt_15.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("초성_16", L"image/text/txt_16.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("초성_17", L"image/text/txt_17.png", 60, 30, 2, 1);
				IMAGEMANAGER->addFrameImage("초성_18", L"image/text/txt_18.png", 60, 30, 2, 1);
			}
		}
		//1. 메인 화면
		{
			IMAGEMANAGER->addImage("메인배경", L"image/ui/UI_common_background.png", 800, 600);
			IMAGEMANAGER->addImage("메인달력", L"image/ui/UI_common_calendar.png", 180, 100);
			IMAGEMANAGER->addImage("상태창", L"image/ui/UI_common_state.png", 200, 218);
			IMAGEMANAGER->addFrameImage("선택창", L"image/ui/UI_common_select.png", 400, 120, 2, 1);

			//1-1. 상점리스트 
			{
				IMAGEMANAGER->addFrameImage("상점목록", L"image/icon/icon_shoplist.png", 240, 40, 6, 1);
			}
			//1-6. 성 방문
			{
				IMAGEMANAGER->addImage("성이미지", L"image/ui/UI_castle.png", 290, 181);

				IMAGEMANAGER->addImage("문지기", L"image/face/UI_face_01.png", 140, 144);
			}
		}
		//2. 캐릭터
		{
			IMAGEMANAGER->addFrameImage("10살기본옷얼굴", L"image/chara/10age/chara_10age_common_clothes_face.png", 784, 131, 4, 1);
			IMAGEMANAGER->addFrameImage("10살여름옷얼굴", L"image/chara/10age/chara_10age_summer_clothes_face.png", 784, 131, 4, 1);
		
			IMAGEMANAGER->addFrameImage("12살옷", L"image/chara/12age/12age_clothes.png", 365, 1357, 1, 4);
		}


		//etc 맵툴
		{
			IMAGEMANAGER->addFrameImage("맵툴이동버튼", L"image/ui/mapTool_button_01.png", 200, 80, 2, 2);
			IMAGEMANAGER->addFrameImage("맵툴조절버튼", L"image/ui/mapTool_button_02.png", 420, 160, 2, 4);

			//지형
			IMAGEMANAGER->addFrameImage(TERRAIN_INFO[TERRAIN_ROAD], L"image/tile/tile_01.png", 240, 240, 6, 6);
			IMAGEMANAGER->addFrameImage(TERRAIN_INFO[TERRAIN_ROAD2], L"image/tile/tile_02.png", 240, 240, 6, 6);
			//오브젝트
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
	//================================================================================= 프레임 이미지
	{
		// 1. 스케쥴 박스

		IMAGEMANAGER->addImage("프레임기본", L"image/ui/UI_schedule_frame_box_09.png", 18, 18);
		IMAGEMANAGER->addImage("스케쥴박스_01", L"image/ui/UI_schedule_frame_box_01.png", 18, 18);
		IMAGEMANAGER->addImage("스케쥴박스_02", L"image/ui/UI_schedule_frame_box_02.png", 18, 18);
		IMAGEMANAGER->addImage("스케쥴박스_03", L"image/ui/UI_schedule_frame_box_03.png", 18, 18);
		IMAGEMANAGER->addImage("스케쥴박스_04", L"image/ui/UI_schedule_frame_box_04.png", 18, 18);
		IMAGEMANAGER->addImage("스케쥴박스_05", L"image/ui/UI_schedule_frame_box_05.png", 18, 18);
		IMAGEMANAGER->addImage("스케쥴박스_06", L"image/ui/UI_schedule_frame_box_06.png", 18, 18);
		IMAGEMANAGER->addImage("스케쥴박스_07", L"image/ui/UI_schedule_frame_box_07.png", 18, 18);
		IMAGEMANAGER->addImage("스케쥴박스_08", L"image/ui/UI_schedule_frame_box_08.png", 18, 18);

		//2. 선택 박스

		IMAGEMANAGER->addImage("선택박스_01", L"image/ui/UI_selectbox_01.png", 18, 18);
		IMAGEMANAGER->addImage("선택박스_02", L"image/ui/UI_selectbox_02.png", 18, 18);
		IMAGEMANAGER->addImage("선택박스_03", L"image/ui/UI_selectbox_03.png", 18, 18);
		IMAGEMANAGER->addImage("선택박스_04", L"image/ui/UI_selectbox_04.png", 18, 18);
		IMAGEMANAGER->addImage("선택박스_05", L"image/ui/UI_selectbox_05.png", 18, 18);
		IMAGEMANAGER->addImage("선택박스_06", L"image/ui/UI_selectbox_06.png", 18, 18);
		IMAGEMANAGER->addImage("선택박스_07", L"image/ui/UI_selectbox_07.png", 18, 18);
		IMAGEMANAGER->addImage("선택박스_08", L"image/ui/UI_selectbox_08.png", 18, 18);

		//3. 텍스트 박스

		IMAGEMANAGER->addImage("텍스트박스_01", L"image/ui/UI_textbox_01.png", 18, 18);
		IMAGEMANAGER->addImage("텍스트박스_02", L"image/ui/UI_textbox_02.png", 18, 18);
		IMAGEMANAGER->addImage("텍스트박스_03", L"image/ui/UI_textbox_03.png", 18, 18);
		IMAGEMANAGER->addImage("텍스트박스_04", L"image/ui/UI_textbox_04.png", 18, 18);
		IMAGEMANAGER->addImage("텍스트박스_05", L"image/ui/UI_textbox_05.png", 18, 18);
		IMAGEMANAGER->addImage("텍스트박스_06", L"image/ui/UI_textbox_06.png", 18, 18);
		IMAGEMANAGER->addImage("텍스트박스_07", L"image/ui/UI_textbox_07.png", 18, 18);
		IMAGEMANAGER->addImage("텍스트박스_08", L"image/ui/UI_textbox_08.png", 18, 18);

		//선택
		IMAGEMANAGER->addImage("선택중", L"image/ui/UI_select.png", 168, 30);
	}

	FRAMEMANAGER->addFrame("테스트1", 100, 100, 10, 10);
	//================================================================================= 씬 등록
	{
		SCENEMANAGER->addScene("맵툴", new mapTool);
		SCENEMANAGER->addScene("오브젝트툴", new objectTool);
		SCENEMANAGER->addScene("테스트씬", new testtttt);

		SCENEMANAGER->addScene("스타트씬", new startScene);
		SCENEMANAGER->addScene("프롤로그씬", new prologueScene);
		SCENEMANAGER->addScene("캐릭터생성씬", new newPlayerScene);
		SCENEMANAGER->addScene("메인씬", new mainScene);


	}

	SCENEMANAGER->changeScene("메인씬");
	
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
	// Draw 시작 - 이 코드가 빠지면 D2D 출력 X
	D2DMANAGER->beginDraw();
	//===========================================================================
	//				##		여기에 코드 작성(Start)			##
	
	SCENEMANAGER->render();
	UIMANAGER->render();

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