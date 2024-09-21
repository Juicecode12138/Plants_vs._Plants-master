#pragma once
#include <functional>


class Timer
{
public:
	Timer() = default;
	~Timer() = default;

	void restart()					//重置定时器状态
	{
		pass_time = 0;
		shotted = false;
	}

	void set_wait_time(int val)		//设置定时器等待的时间
	{
		wait_time = val;
	}

	void set_one_shot(bool flag)	//设置定时器是否单次触发
	{
		one_shot = flag;
	}

	void pause()					//计时器暂停运行
	{
		paused = true;
	}

	void resume()					//计时器恢复运行
	{
		paused = false;
	}

	void on_update(int delta)
	{
		if (paused)
			return;
		
		pass_time += delta;			//累加帧更新实际过去的时间
		if (pass_time >= wait_time)
		{
			if ((!one_shot /*定时器不是单次触发*/ 
				|| (one_shot && !shotted)) /*定时器单次触发并且没有被触发过*/ 
				&& callback /*callback是否有效*/)
				callback();
			shotted = true; //设置定时器的触发状态
			pass_time = 0;	//重置已经度过的时间
		}
		
	}

	void set_callback(std::function<void()> callback)
	{
		this->callback = callback;
	}

protected:
	std::function<void()> callback;

private:
	int pass_time = 0;		//已过时间
	int wait_time = 0;		//等待时间
	bool paused = false;	//是否暂停
	bool shotted = false;	//是否触发
	bool one_shot = false;	//单次触发
};