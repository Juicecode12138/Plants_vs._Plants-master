#pragma once

#include "scene.h"
#include "atlas.h"
#include "timer.h"
#include "camera.h"
#include "animation.h"
#include "scene_manager.h"

#include <iostream>

extern Atlas atlas_peashooter_run_right;

extern SceneManager scene_manager;

using namespace std;

class MenuScene:public Scene
{
public:
	MenuScene() = default;
	~MenuScene() = default;

	virtual void on_enter() 
	{
		animation_peashooter_run_right.set_atlas(&atlas_peashooter_run_right);
		animation_peashooter_run_right.set_interval(75);
		animation_peashooter_run_right.set_loop(true);
		animation_peashooter_run_right.set_callback(
			[]()
			{
				scene_manager.switch_to(SceneManager::SceneType::Game);
			}//lambda匿名函数
		);

		timer.set_wait_time(1000);
		timer.set_one_shot(false);
		timer.set_callback([]()
			{
				cout << "Shot!" << endl;
			});
		
	} //场景进入时的初始化逻辑

	virtual void on_update(int delta) 
	{
		timer.on_update(delta);
		camera.on_update(delta);
		animation_peashooter_run_right.on_update(delta);
	}//处理数据

	virtual void on_draw() 
	{
		const Vector2& pos_camera = camera.get_position();
		animation_peashooter_run_right.on_draw((int)(100 - pos_camera.x), (int)(100 - pos_camera.y));
	} //渲染绘图

	virtual void on_input(const ExMessage& msg) 
	{
		if (msg.message == WM_KEYDOWN) {
			camera.shake(10, 350);
		}
	}//处理玩家输入
	
	virtual void on_exit()  //场景退出时的卸载逻辑
	{
		cout << "退出主菜单" << endl;
	}
private:
	Timer timer;
	Camera camera;
	Animation animation_peashooter_run_right;
};