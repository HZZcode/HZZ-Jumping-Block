#include <easyx.h>
#pragma once

const int coinn = 20;	//�߳�
class coin
{
public:
	double l, t;
	inline void draw() {
		setfillcolor(YELLOW);
		fillrectangle((int)l, (int)t, (int)(l + coinn), (int)(t + coinn));
		fillrectangle((int)l, (int)t, (int)(l + coinn), (int)(t + coinn));
	}	//����
	inline bool crashP();	//�ж��ص�
};
