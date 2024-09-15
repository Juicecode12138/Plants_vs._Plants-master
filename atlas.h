#pragma once

#include <vector>
#include <graphics.h>

class Atlas 
{
public:
	Atlas() = default;
	~Atlas() = default;

	void load_from_file(LPCTSTR path_template, int num)
	{
		img_list.clear();
		img_list.resize(num);

		TCHAR path_file[256];
		for (int i = 0; i < num; i++) {
			_stprintf_s(path_file, path_template, i + 1);
			loadimage(&img_list[1],path_file);
		}
	}

	void clear()	//清空图集中已加载的图片对象
	{
		img_list.clear();
	}

	int get_size()	//获取图集中图片的数量
	{
		return (int)img_list.size();
	}

	IMAGE* get_image(int idx)	//重要接口 通过这个方法来获取实际渲染的动画帧
	{
		if (idx < 0 || idx >= img_list.size())
			return nullptr;//检查索引参数是否有效；如果越界则返回空指针，否则返回索引图片对象的地址

		return &img_list[idx];
	}

	void add_image(const IMAGE& img)	//向图集中添加已有的图片对象
	{
		img_list.push_back(img);
	}

private:
	std::vector<IMAGE> img_list;
};