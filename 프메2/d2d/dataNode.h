#pragma once
#include "stdafx.h"

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
enum PLAYER_FOODSTYLE
{
	NOT_OVER,
	STRONG,
	QUIET,
	DIET
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

//캐릭터 정보
struct tagInfo
{
	string lastName;		//성
	string firstName;		//이름

	BLOOD_TYPE bloodType;	//혈액형

	int year;				//년
	int mon;				//월
	int day;				//일
	DAYDAY dayday;			//요일

	int age;				//나이
	int gold;				//돈

	float height;				//키
	float weight;				//몸무게
	float bast;					//가슴
	float waist;				//허리
	float hip;					//엉덩이

	tagStatus		status;
	PRINCESS_FACE	faceType;
	SEASEON_TYPE	seaseonType;
	PLAYER_FOODSTYLE foodStyle;
};

enum class HOME_STATE
{
	IDLE,
	SAVELOAD,
	SAVE,
	LOAD
};