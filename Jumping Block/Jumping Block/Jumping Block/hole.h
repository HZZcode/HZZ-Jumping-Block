#include <easyx.h>
#pragma once
const int hlength = 30;	//����
class hole
{
public:
	double l;	//�������
	inline void draw() {
		setfillcolor(BLACK);
		fillrectangle((int)l, 450, (int)(l + hlength), 480);
	}
};
