#include <easyx.h>
#pragma once

const int blockn = 20;	//�߳�

class block
{
public:
	double l, t;
	inline void draw() {
		setfillcolor(WHITE);
		fillrectangle((int)l, (int)t, (int)(l + blockn), (int)(t + blockn));
		fillrectangle((int)l, (int)t, (int)(l + blockn), (int)(t + blockn));
	}	//����
	inline bool crashP();	//�ж��ص�
};