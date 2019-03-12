#pragma once
#include "stdafx.h"

enum DAUGHTER_BLOODTYPE	
{ 
	BLOODTYPE_A, BLOODTYPE_B, BLOODTYPE_O, BLOODTYPE_AB 
};
enum DAUGHTER_FACE
{
	FACE_NOMAL, FACE_STRESS, FACE_SICK, FACE_HAPPY, FACE_LOVELY
};
enum DIALOG_TYPE 
{
	DIALOG_ING, DIALOG_FIN
};
enum STATUS_TYPE 
{ 
	STATUS_START, STATUS_TEACH, STATUS_ING, STATUS_FIN
};
enum SEASON_TYPE 
{ 
	SPRING, SUMMER, AUTUMN, WINTER
};
enum WEEK		 
{ 
	MON, TUE, WED, THU, FRI, SAT, SUN
};
enum ITEM_TYPE	 
{ 
	ITEM_WEAPON, ITEM_ARMOR, ITME_CLOTHES, ITEM_COOK, 
};

struct tagObj
{
	D2D1_RECT_F rc;
	bool isData;
	int indexX, indexY;
	bool isSelect;
};

struct tagPlayerInfo
{
	string firstName;					//이름
	string familyName;					//성

	int year;							//년
	int mon;							//월
	int day;							//일
	int age;							//나이
	int week;							//일주일 날짜
	DAUGHTER_BLOODTYPE blood;			//혈액형 타입
	string strBlood;					//혈액형 글자
	string dietType;					//식단 상태
};

struct tagConstellation
{
	string planet;						//행성
	string name;						//이름
	string constellation;				//별자리
	int index;							//인덱스
};

struct tagPlayerStatus
{
	tagConstellation god;
	
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

struct tagBody
{
	float height;				//키
	float weight;				//몸무게
	float bast;					//가슴
	float waist;				//허리
	float hip;					//엉덩이

	int clothesType;			//옷
};

struct tagString
{
	string str;
	D2D1_RECT_F rc;
	bool isSelected;
	bool isChoose;
};

struct tagImg
{
	image* img;
	int x, y;
	int frameX, frameY;
	tagString data;
};

struct tagDate
{
	int index;
	string firstName;					//이름
	string familyName;					//성

	int year;							//년
	int mon;							//월
	int day;							//일
	int age;							//나이
	int week;							//일주일 날짜
	DAUGHTER_FACE	faceType;			//딸냄 얼굴
};

struct tagStatusData
{
	string name;
	int startP;
	int endP;
	int plusStart;
	int plusEnd;
};

struct tagRelax
{
	int sensitivity;					//감수성
	int stress;							//스트레스
	float weight;						//몸무게
};