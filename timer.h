#pragma once
#include <functional>


class Timer
{
public:
	Timer() = default;
	~Timer() = default;

	void restart()					//���ö�ʱ��״̬
	{
		pass_time = 0;
		shotted = false;
	}

	void set_wait_time(int val)		//���ö�ʱ���ȴ���ʱ��
	{
		wait_time = val;
	}

	void set_one_shot(bool flag)	//���ö�ʱ���Ƿ񵥴δ���
	{
		one_shot = flag;
	}

	void pause()					//��ʱ����ͣ����
	{
		paused = true;
	}

	void resume()					//��ʱ���ָ�����
	{
		paused = false;
	}

	void on_update(int delta)
	{
		if (paused)
			return;
		
		pass_time += delta;			//�ۼ�֡����ʵ�ʹ�ȥ��ʱ��
		if (pass_time >= wait_time)
		{
			if ((!one_shot /*��ʱ�����ǵ��δ���*/ 
				|| (one_shot && !shotted)) /*��ʱ�����δ�������û�б�������*/ 
				&& callback /*callback�Ƿ���Ч*/)
				callback();
			shotted = true; //���ö�ʱ���Ĵ���״̬
			pass_time = 0;	//�����Ѿ��ȹ���ʱ��
		}
		
	}

	void set_callback(std::function<void()> callback)
	{
		this->callback = callback;
	}

protected:
	std::function<void()> callback;

private:
	int pass_time = 0;		//�ѹ�ʱ��
	int wait_time = 0;		//�ȴ�ʱ��
	bool paused = false;	//�Ƿ���ͣ
	bool shotted = false;	//�Ƿ񴥷�
	bool one_shot = false;	//���δ���
};