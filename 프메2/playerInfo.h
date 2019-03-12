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
enum PLAYER_BLOODTYPE					//혈액형
{
	BLOODTYPE_NONE,

	BLOODTYPE_A,
	BLOODTYPE_B,
	BLOODTYPE_O,
	BLOODTYPE_AB

};
enum PLAYER_CONSTRLLATION				//별자리
{
	CONS_NONE,

	CONS_CAORICORN,						//염소자리
	CONS_AQUARIUS,						//물병자리
	CONS_PISCES,						//물고기자리
	CONS_ARIES,							//양자리
	CONS_TAURUS,						//황소자리
	CONS_GEMINI,						//쌍둥이자리
	CONS_CANCER,						//게자리
	CONS_LEO,							//사자자리
	CONS_VIRGO,							//처녀자리
	CONS_LIBRA,							//천칭자리
	CONS_SCORPIO,						//전갈자리
	CONS_SAGIRRARIUS					//사수자리
};

typedef struct tagPlayerStatus			//능력치
{
	unsigned int hp;					//체력
	unsigned int muscular_strength;		//근력
	unsigned int intelligence;			//지능
	unsigned int elegance;				//기품
	unsigned int charm;					//매력
	unsigned int morality;				//도덕성
	unsigned int faith;					//신앙
	unsigned int karma;					//업보
	unsigned int sensitivity;			//감수성
	unsigned int stress;				//스트레스

	unsigned int cambat_skill;			//전투기술
	unsigned int attk_power;			//공격력
	unsigned int def_power;				//방어력
	unsigned int magic_skill;			//마법기술
	unsigned int magic_power;			//마력
	unsigned int magicdef_power;		//마법저항력

	unsigned int warrior_appraisal;		//전사평가
	unsigned int magic_appraisal;		//마법평가
	unsigned int sociable_appraisal;	//사교평가
	unsigned int housework_appraisal;	//가사평가

	unsigned int etiquette;				//예의범절
	unsigned int art;					//예술
	unsigned int talking_sense;			//화술
	unsigned int cooking;				//요리
	unsigned int cleaning;				//청소세탁
	unsigned int charactre;				//성품

};
class playerInfo
{
public:
	playerInfo();
	~playerInfo();
};

