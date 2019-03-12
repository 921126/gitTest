#pragma once


enum PLAYER_AGE
{
	AGE_10 = 1,
	AGE_11,
	AGE_12,
	AGE_13,
	AGE_14,
	AGE_15,
	AGE_16,
	AGE_17,
	AGE_18
};
enum PLAYER_BLOODTYPE					//������
{
	BLOODTYPE_NONE,

	BLOODTYPE_A,
	BLOODTYPE_B,
	BLOODTYPE_O,
	BLOODTYPE_AB

};
enum PLAYER_CONSTRLLATION				//���ڸ�
{
	CONS_NONE,

	CONS_CAORICORN,						//�����ڸ�
	CONS_AQUARIUS,						//�����ڸ�
	CONS_PISCES,						//������ڸ�
	CONS_ARIES,							//���ڸ�
	CONS_TAURUS,						//Ȳ���ڸ�
	CONS_GEMINI,						//�ֵ����ڸ�
	CONS_CANCER,						//���ڸ�
	CONS_LEO,							//�����ڸ�
	CONS_VIRGO,							//ó���ڸ�
	CONS_LIBRA,							//õĪ�ڸ�
	CONS_SCORPIO,						//�����ڸ�
	CONS_SAGIRRARIUS					//����ڸ�
};

typedef struct tagPlayerStatus			//�ɷ�ġ
{
	unsigned int hp;					//ü��
	unsigned int muscular_strength;		//�ٷ�
	unsigned int intelligence;			//����
	unsigned int elegance;				//��ǰ
	unsigned int charm;					//�ŷ�
	unsigned int morality;				//������
	unsigned int faith;					//�ž�
	unsigned int karma;					//����
	unsigned int sensitivity;			//������
	unsigned int stress;				//��Ʈ����

	unsigned int cambat_skill;			//�������
	unsigned int attk_power;			//���ݷ�
	unsigned int def_power;				//����
	unsigned int magic_skill;			//�������
	unsigned int magic_power;			//����
	unsigned int magicdef_power;		//�������׷�

	unsigned int warrior_appraisal;		//������
	unsigned int magic_appraisal;		//������
	unsigned int sociable_appraisal;	//�米��
	unsigned int housework_appraisal;	//������

	unsigned int etiquette;				//���ǹ���
	unsigned int art;					//����
	unsigned int talking_sense;			//ȭ��
	unsigned int cooking;				//�丮
	unsigned int cleaning;				//û�Ҽ�Ź
	unsigned int charactre;				//��ǰ

};
class playerInfo
{
public:
	playerInfo();
	~playerInfo();
};

