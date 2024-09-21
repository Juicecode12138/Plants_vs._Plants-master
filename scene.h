﻿#pragma once
#include <graphics.h>
#include "camera.h"

class Scene 
{
public:
	Scene() = default;
	~Scene() = default;

	virtual void on_enter() {} //场景进入时的初始化逻辑
	virtual void on_update(int delta) {} //处理数据 delta表示实际过去的时间
	virtual void on_draw(const Camera& camera) {} //渲染绘图
	virtual void on_input(const ExMessage& msg) {} //处理玩家输入
	virtual void on_exit() {} //场景退出时的卸载逻辑

private:
	
};