#pragma once

#include "scene.h"
#include "scene_manager.h"

#include <iostream>

extern IMAGE img_menu_background;

extern SceneManager scene_manager;

using namespace std;

class MenuScene:public Scene
{
public:
	MenuScene() = default;
	~MenuScene() = default;

	virtual void on_enter() 
	{
		mciSendString(_T("play bgm_menu repeat from 0"),NULL,0,NULL);
	} //场景进入时的初始化逻辑

	virtual void on_update(int delta) 
	{
		
	}//处理数据

	virtual void on_draw(const Camera& camera) 
	{
		putimage(0, 0, &img_menu_background);
	} //渲染绘图

	virtual void on_input(const ExMessage& msg) 
	{
		if (msg.message == WM_KEYUP)
		{
			mciSendString(_T("play ui_confirm from 0"), NULL, 0, NULL);
			scene_manager.switch_to(SceneManager::SceneType::Selector);
		}
	}//处理玩家输入
	
	virtual void on_exit()  //场景退出时的卸载逻辑
	{
		
	}
private:

};