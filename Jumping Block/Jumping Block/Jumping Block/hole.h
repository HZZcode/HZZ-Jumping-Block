#include <easyx.h>
#pragma once
const int hlength = 30;	//¶´¿í
class hole
{
public:
	double l;	//×ó²à×ø±ê
	inline void draw() {
		setfillcolor(BLACK);
		fillrectangle((int)l, 450, (int)(l + hlength), 480);
	}
};
