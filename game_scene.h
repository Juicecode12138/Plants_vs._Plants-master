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
		cout << "������Ϸ���ڳ���" << endl;
	} //��������ʱ�ĳ�ʼ���߼�

	virtual void on_update()
	{
		cout << "��Ϸ�������С�" << endl;
	}//��������

	virtual void on_draw()
	{
		outtextxy(10, 10, _T("��Ϸ���ڻ�ͼ����"));
	} //��Ⱦ��ͼ

	virtual void on_input(const ExMessage& msg) 
	{
		if (msg.message == WM_KEYDOWN)
		{
			scene_manager.switch_to(SceneManager::SceneType::Menu);
		}
	}//�����������

	virtual void on_exit()  //�����˳�ʱ��ж���߼�
	{
		cout << "��Ϸ�����˳�" << endl;
	}
private:

};