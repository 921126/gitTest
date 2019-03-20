#pragma once
#include "stdafx.h"

//ĳ���� ��
enum PRINCESS_FACE
{
	FACE_NOMAL,		//�⺻��
	FACE_STRESS,	//��Ʈ�����ִ� ��
	FACE_SICK,		//���� ��
	FACE_HAPPY,		//��Ʈ���� 0�϶� �ູ�� ��
	FACE_LOVELY		//������� ��(�����ִ� ��)
};
//������
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
//��������
enum SEASEON_TYPE
{
	SPRING,
	SUMMER,
	AUTUMN,
	WINTER
};
//����
enum DAYDAY
{
	MON, TUE, WED, THU, FRI, SAT, SUN
};
//������Ÿ��
enum ITEM_TYPE
{
	ITEM_WEAPON, ITEM_ARMOR, ITEM_CLOTHES
};
//��ȣ��
struct tagGuardianGod
{
	string planet;			//��ȣ �༺
	string name;			//��ȣ�� �̸�
	string constellation;	//���ڸ�
};

//ĳ���� ����
struct tagStatus
{
	tagGuardianGod Guardian;	//��ȣ��
	
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

//ĳ���� ����
struct tagInfo
{
	string lastName;		//��
	string firstName;		//�̸�

	BLOOD_TYPE bloodType;	//������

	int year;				//��
	int mon;				//��
	int day;				//��
	DAYDAY dayday;			//����

	int age;				//����
	int gold;				//��

	float height;				//Ű
	float weight;				//������
	float bast;					//����
	float waist;				//�㸮
	float hip;					//������

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