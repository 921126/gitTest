#pragma once
#include "stdafx.h"

#ifndef  _DATA_H_
#define _DATA_H_

//캐릭터 얼굴
enum PRINCESS_FACE
{
	FACE_NOMAL,		//기본얼굴
	FACE_STRESS,	//스트레스있는 얼굴
	FACE_SICK,		//아픈 얼굴
	FACE_HAPPY,		//스트레스 0일때 행복한 얼굴
	FACE_LOVELY		//사랑스런 얼굴(색기있는 얼굴)
};
//혈액형
enum BLOOD_TYPE
{
	BTYPE_A,
	BTYPE_B,
	BTYPE_O,
	BTYPE_AB
};
//대사
enum DIALOG_TYPE
{
	DIALOG_ING,
	DIALOG_END
};
//스탯 상태
enum STATUS_TYPE
{
	BEGINNING_STATUS,
	STUDY_STATUS,
	ING_STATUS,
	END_STATUS,
};
//계절상태
enum SEASEON_TYPE
{
	SPRING,
	SUMMER,
	AUTUMN,
	WINTER
};
//요일
enum DAYDAY
{
	MON, TUE, WED, THU, FRI, SAT, SUN
};
//아이템타입
enum ITEM_TYPE
{
	ITEM_WEAPON, ITEM_ARMOR, ITEM_CLOTHES
};
//수호신
struct tagGuardianGod
{
	string planet;			//수호 행성
	string name;			//수호신 이름
	string constellation;	//별자리
	int indexX;				//이미지용 인덱스
};
//캐릭터 정보
struct tagInfo
{
	string lastName;		//성
	string firstName;		//이름
	string strBloodType;	//혈액형글씨
	string dietType;		//건강상태
	
	BLOOD_TYPE bloodType;	//혈액형

	int year;				//년
	int mon;				//월
	int day;				//일
	int dayday;				//요일

	int age;				//나이
	int gold;				//돈

};
//캐릭터 스텟
struct tagStatus
{
	tagGuardianGod Guardian;	//수호성
	
	int hp;						//체력
	int muscular_strength;		//근력
	int intelligence;			//지능
	int elegance;				//기품
	int charm;					//매력
	int morality;				//도덕성
	int faith;					//신앙
	int karma;					//업보
	int sensitivity;			//감수성
	int stress;					//스트레스

	int cambat_skill;			//전투기술
	int attk_power;				//공격력
	int def_power;				//방어력
	int magic_skill;			//마법기술
	int magic_power;			//마력
	int magicdef_power;			//마법저항력

	int warrior_appraisal;		//전사평가
	int magic_appraisal;		//마법평가
	int sociable_appraisal;		//사교평가
	int housework_appraisal;	//가사평가

	int etiquette;				//예의범절
	int art;					//예술
	int talking_sense;			//화술
	int cooking;				//요리
	int cleaning;				//청소세탁
	int charactre;				//성품

	int relationfather;
	int total;
	
};
//캐릭터 몸매 수치
struct tagBodyStatus
{
	float height;				//키
	float weight;				//몸무게
	float bast;					//가슴
	float waist;				//허리
	float hip;					//엉덩이

	int clothesType;			//옷
};
//날짜처리
struct tagDate
{
	string lastName;
	string fristName;
	PRINCESS_FACE faceType;

	int year;		//년
	int mon;		//월
	int day;		//일
	int dayday;		//요일
};
//스텟처리
struct tagStatusData
{
	string fristName;	//이름
	int start;
	int end;
	int pStart;
	int pEnd;
};
//바캉스 처리
struct tagVacation
{
	int sensitivity;
	int stress;
	
	float weight;
};

//기타 처리용
struct tagEtc
{
	D2D1_RECT_F rc;

	int indeX, indexY;

	bool isData;
	bool isSelect;

};
struct tagEtc2
{
	string str;
	D2D1_RECT_F rc;
	bool isSelect;
	bool isChoose;
};
struct tagImage
{
	image* img;
	tagEtc2 data;
	int x, y;
	int frameX, frameY;
};

#endif // ! _DATA_H_
