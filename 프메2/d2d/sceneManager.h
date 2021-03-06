#pragma once
#include "singletonBase.h"
#include <map>

//���� ���� ���ӳ�� ���漱��
class gameNode;
class princess;

class sceneManager : public singletonBase<sceneManager>
{
public:
	typedef map<string, gameNode*>			 mapSceneList;
	typedef map<string, gameNode*>::iterator mapSceneIter;

private:
	static gameNode*	_currentScene;	//���� ��
	mapSceneList		_mSceneList;

	princess* _princess;
public:
	sceneManager();
	~sceneManager();

	HRESULT init();
	void release();
	void update();
	void render();

	//�� �߰� �Ծ�
	gameNode* addScene(string sceneName, gameNode* scene);

	//�� ���� �Ծ�
	HRESULT changeScene(string sceneName);

	//��ũ����
	void SetPrincessAddressLink(princess* princess) { _princess = princess; }
	princess* getPrincessAddress() { return _princess; }

};

