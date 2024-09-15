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
		cout << "�������˵�" << endl;
	} //��������ʱ�ĳ�ʼ���߼�

	virtual void on_update() 
	{
		cout << "���˵��������С�" << endl;
	}//��������

	virtual void on_draw() 
	{
		outtextxy(10, 10, _T("���˵���ͼ����"));
	} //��Ⱦ��ͼ

	virtual void on_input(const ExMessage& msg) 
	{
		if (msg.message == WM_KEYDOWN) {
			scene_manager.switch_to(SceneManager::SceneType::Game);
		}
	}//�����������
	
	virtual void on_exit()  //�����˳�ʱ��ж���߼�
	{
		cout << "���˵��˳�" << endl;
	}
private:

};