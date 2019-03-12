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
	string firstName;					//�̸�
	string familyName;					//��

	int year;							//��
	int mon;							//��
	int day;							//��
	int age;							//����
	int week;							//������ ��¥
	DAUGHTER_BLOODTYPE blood;			//������ Ÿ��
	string strBlood;					//������ ����
	string dietType;					//�Ĵ� ����
};

struct tagConstellation
{
	string planet;						//�༺
	string name;						//�̸�
	string constellation;				//���ڸ�
	int index;							//�ε���
};

struct tagPlayerStatus
{
	tagConstellation god;
	
	int hp;						//ü��
	int muscular_strength;		//�ٷ�
	int intelligence;			//����
	int elegance;				//��ǰ
	int charm;					//�ŷ�
	int morality;				//������
	int faith;					//�ž�
	int karma;					//����
	int sensitivity;			//������
	int stress;					//��Ʈ����

	int cambat_skill;			//�������
	int attk_power;				//���ݷ�
	int def_power;				//����
	int magic_skill;			//�������
	int magic_power;			//����
	int magicdef_power;			//�������׷�

	int warrior_appraisal;		//������
	int magic_appraisal;		//������
	int sociable_appraisal;		//�米��
	int housework_appraisal;	//������

	int etiquette;				//���ǹ���
	int art;					//����
	int talking_sense;			//ȭ��
	int cooking;				//�丮
	int cleaning;				//û�Ҽ�Ź
	int charactre;				//��ǰ

	int relationfather;
	int total;

};

struct tagBody
{
	float height;				//Ű
	float weight;				//������
	float bast;					//����
	float waist;				//�㸮
	float hip;					//������

	int clothesType;			//��
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
	string firstName;					//�̸�
	string familyName;					//��

	int year;							//��
	int mon;							//��
	int day;							//��
	int age;							//����
	int week;							//������ ��¥
	DAUGHTER_FACE	faceType;			//���� ��
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
	int sensitivity;					//������
	int stress;							//��Ʈ����
	float weight;						//������
};