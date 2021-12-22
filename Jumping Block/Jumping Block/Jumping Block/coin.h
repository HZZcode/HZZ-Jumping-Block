#include <easyx.h>
#pragma once

const int coinn = 20;	//±ﬂ≥§
class coin
{
public:
	double l, t;
	inline void draw() {
		setfillcolor(YELLOW);
		fillrectangle((int)l, (int)t, (int)(l + coinn), (int)(t + coinn));
		fillrectangle((int)l, (int)t, (int)(l + coinn), (int)(t + coinn));
	}	//ªÊ÷∆
	inline bool crashP();	//≈–∂œ÷ÿµ˛
};
