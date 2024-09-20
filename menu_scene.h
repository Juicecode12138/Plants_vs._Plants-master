#pragma once

#include "scene.h"
#include "scene_manager.h"

#include <iostream>

extern SceneManager scene_manager;
using namespace std;

class MenuScene:public Scene
{
public:
	MenuScene() = default;
	~MenuScene() = default;

	virtual void on_enter() 
	{
		cout << "进入主菜单" << endl;
	} //场景进入时的初始化逻辑

	virtual void on_update() 
	{
		cout << "主菜单正在运行…" << endl;
	}//处理数据

	virtual void on_draw() 
	{
		outtextxy(10, 10, _T("主菜单绘图内容"));
	} //渲染绘图

	virtual void on_input(const ExMessage& msg) 
	{
		if (msg.message == WM_KEYDOWN) {
			scene_manager.switch_to(SceneManager::SceneType::Game);
		}
	}//处理玩家输入
	
	virtual void on_exit()  //场景退出时的卸载逻辑
	{
		cout << "退出主菜单" << endl;
	}
private:
	
};