#include <easyx.h>
#pragma once

const int blockn = 20;	//±ß³¤

class block
{
public:
	double l, t;
	inline void draw() {
		setfillcolor(WHITE);
		fillrectangle((int)l, (int)t, (int)(l + blockn), (int)(t + blockn));
		fillrectangle((int)l, (int)t, (int)(l + blockn), (int)(t + blockn));
	}	//»æÖÆ
	inline bool crashP();	//ÅĞ¶ÏÖØµş
};