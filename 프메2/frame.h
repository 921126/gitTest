#pragma once
class frame
{
public:

	typedef struct tagFrameBoxInfo
	{
		UINT frameWidth		= NULL;
		UINT frameHeight	= NULL;
		UINT destX			= NULL;
		UINT destY			= NULL;
	}FRAME_BOX_INFO, *LPMENU_FRAME_INFO;

private:

	LPMENU_FRAME_INFO _frameInfo;

	
public:
	frame();
	~frame();

	HRESULT init(UINT destX, UINT destY, UINT frameWidth, UINT frameHeight);
	void release();
	void update();
	void render(string imageName);
};

