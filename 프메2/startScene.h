#pragma once
#include "gameNode.h"

enum SELECT_START_STATE
{
	S_SELECT_NONE,			//�ƹ��͵� �����ϰ� ���� ����
	S_SELECT_OPENING_START,	//��������� ���� ����
	S_SELECT_START,			//�����׽�ŵ ���� ����
	S_SELECT_LOAD,			//�ҷ����� ����
};
struct tagSelectBox
{
	D2D1_RECT_F _rc;
};
class startScene : public gameNode
{
private:

	tagSelectBox _selectBox[3];
	SELECT_START_STATE _selectState;

public:
	startScene();
	~startScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

