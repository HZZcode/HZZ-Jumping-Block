#include <easyx.h>
#pragma once

const int playn = 20;	//±ﬂ≥§

class player_t
{
public:
	double l, t;
	inline void draw() {
		setfillcolor(RED);
		solidrectangle((int)l, (int)t, (int)(l + 20), (int)(t + 20));
	}	//ªÊ÷∆
};
