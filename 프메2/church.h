#pragma once
#include "baseUi.h"

enum CHURCH_STATE
{
	C_SELECT_NONE,				//���þ���
	C_SELECT_CONTRIBURION,		//����ϱ�
	C_SELECT_NOTCON,			//��ξ��ϱ�
};
class church : public baseUi
{
private:

	CHURCH_STATE _cState;

public:
	church();
	~church();

	HRESULT init();
	void release();
	void update();
	void render();
};

