#pragma once
#include "stdafx.h"

#ifndef  _DATA_H_
#define _DATA_H_

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
//���
enum DIALOG_TYPE
{
	DIALOG_ING,
	DIALOG_END
};
//���� ����
enum STATUS_TYPE
{
	BEGINNING_STATUS,
	STUDY_STATUS,
	ING_STATUS,
	END_STATUS,
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
	int indexX;				//�̹����� �ε���
};
//ĳ���� ����
struct tagInfo
{
	string lastName;		//��
	string firstName;		//�̸�
	string strBloodType;	//�������۾�
	string dietType;		//�ǰ�����
	
	BLOOD_TYPE bloodType;	//������

	int year;				//��
	int mon;				//��
	int day;				//��
	int dayday;				//����

	int age;				//����
	int gold;				//��

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
//ĳ���� ���� ��ġ
struct tagBodyStatus
{
	float height;				//Ű
	float weight;				//������
	float bast;					//����
	float waist;				//�㸮
	float hip;					//������

	int clothesType;			//��
};
//��¥ó��
struct tagDate
{
	string lastName;
	string fristName;
	PRINCESS_FACE faceType;

	int year;		//��
	int mon;		//��
	int day;		//��
	int dayday;		//����
};
//����ó��
struct tagStatusData
{
	string fristName;	//�̸�
	int start;
	int end;
	int pStart;
	int pEnd;
};
//��Ĳ�� ó��
struct tagVacation
{
	int sensitivity;
	int stress;
	
	float weight;
};

//��Ÿ ó����
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
