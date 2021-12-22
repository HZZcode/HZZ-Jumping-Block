#include <iostream>
#include <easyx.h>
#pragma once
class reactangle_trigger
{
public:
	int x;
	int y;
	int width;
	int height;
	LPCTSTR str;
	COLORREF bgcol, txcol;	//����&������ɫ

	inline reactangle_trigger()
	{
		x = 0;
		y = 0;
		width = 0;
		height = 0;
		str = L"Start Game";
		bgcol = WHITE;
		txcol = BLACK;
	}	// Ĭ�Ϲ��캯��

	inline reactangle_trigger(int control_x, int control_y,
		int control_width, int control_height) {
		x = (control_x);
		y = (control_y);
		width = (control_width);
		height = (control_height);
		str = L"Start Game";
		bgcol = WHITE;
		txcol = BLACK;
	}	//���óߴ�

	inline reactangle_trigger(int control_x, int control_y,
		int control_width, int control_height, LPCTSTR cstr) {
		x = (control_x);
		y = (control_y);
		width = (control_width);
		height = (control_height);
		str = cstr;
		bgcol = WHITE;
		txcol = BLACK;
	}	//���óߴ缰����

	inline reactangle_trigger(int control_x, int control_y,
		int control_width, int control_height, LPCTSTR cstr,
		COLORREF cbgcol, COLORREF ctxcol) {
		x = (control_x);
		y = (control_y);
		width = (control_width);
		height = (control_height);
		str = cstr;
		bgcol = cbgcol;
		txcol = ctxcol;
	}	//���óߴ缰���֡���ɫ

	inline void draw() {
		setfillcolor(bgcol);
		setbkcolor(BLACK);
		fillrectangle(x, y, x + width, y + height);

		COLORREF bk0 = getbkcolor();
		setbkcolor(bgcol);
		settextstyle(17, 0, L"Consolas");
		RECT r = { x, y, x + width, y + height };
		settextcolor(txcol);
		drawtext(str, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		setbkcolor(bk0);
	}	//����

	inline bool is_trigger(ExMessage message)
	{
		return message.x >= x && message.y >= y &&
			message.x <= x + width &&
			message.y <= y + height &&
			message.message == WM_LBUTTONDOWN;
	}	// ����Ƿ񴥷�
};
