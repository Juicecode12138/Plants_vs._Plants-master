#pragma once

#include "scene.h"
#include "scene_manager.h"

#include <iostream>

using namespace std;

class GameScene :public Scene 
{
public:
	GameScene() = default;
	~GameScene() = default;

	virtual void on_enter()
	{
		cout << "进入游戏局内场景" << endl;
	} //场景进入时的初始化逻辑

	virtual void on_update(int delta)
	{
		cout << "游戏正在运行…" << endl;
	}//处理数据

	virtual void on_draw()
	{
		outtextxy(10, 10, _T("游戏局内绘图内容"));
	} //渲染绘图

	virtual void on_input(const ExMessage& msg) 
	{
		if (msg.message == WM_KEYDOWN)
		{
			scene_manager.switch_to(SceneManager::SceneType::Menu);
		}
	}//处理玩家输入

	virtual void on_exit()  //场景退出时的卸载逻辑
	{
		cout << "退出游戏…" << endl;
	}
private:

};