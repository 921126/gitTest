#pragma once

class baseUi
{
protected:

public:
	baseUi();
	~baseUi();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void uiOpen();
	virtual void uiClose();

	virtual void uiInfoSet();

	virtual int getHealthState();

};