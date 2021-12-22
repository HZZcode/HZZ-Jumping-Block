////////////////////////////////////
//  项目名称：Jumping Block       //
//  版本：1.2.1                   //
//  作者：HZZ                     //
//  编译环境：VS2017 + Easyx2021  //
////////////////////////////////////

#include <iostream>
#include <conio.h>
#include <random>
#include <time.h>
#include <easyx.h>
#include <winsock.h>
#include <WinUser.h>
#include <mmsystem.h>
#include <string>
#include <fstream>

#include "crash.h"
#include "player_t.h"
#include "block.h"
#include "coin.h"
#include "reactangle_trigger.h"
#include "hole.h"

#pragma comment(lib,"Winmm.lib")

using namespace std;

#define KEYDOWN(vk) 0x8000 & ::GetAsyncKeyState(vk)		//实现按键的识别

double v = 0;
long long dist = 0;

player_t player;
block b[4];
coin c[4];
hole h;

inline bool block::crashP() {
	double r1[4] = { l,t,l + blockn,t + blockn };
	double r2[4] = { player.l,player.t,player.l + playn,player.t + playn };
	return RectOver(r1, r2);
}

inline bool coin::crashP() {
	double r1[4] = { l,t,l + blockn,t + blockn };
	double r2[4] = { player.l,player.t,player.l + playn,player.t + playn };
	return RectOver(r1, r2);
}

//char* 转 wchar*
wchar_t* AnsiToUnicode(const char* szStr)
{
	int nLen = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, szStr, -1, NULL, 0);
	if (nLen == 0)
	{
		return NULL;
	}
	wchar_t* pResult = new wchar_t[nLen];
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, szStr, -1, pResult, nLen);
	return pResult;
}

void music() {
	system("copy /v /b /y ./res/Horizon.mp3 %Temp%");

	FILE* pf = nullptr;
	fopen_s(&pf, "d:/我的文档/hzz/编程/cpps/jumpin~1/jumpin~1/jumpin~1/debug/res/horizon.mp3", "rb");
	if (pf == nullptr) {
		std::cout << L"文件不存在\n";
	}	//判断文件存在

	mciSendString(L"open d:/我的文档/hzz/编程/cpps/jumpin~1/jumpin~1/jumpin~1/debug/res/horizon.mp3 alias BGM", NULL, 0, NULL);
	mciSendString(L"play BGM", NULL, 0, NULL);
}	//播放音乐

void setup()
{
	setbkcolor(BLACK);
	setfillcolor(WHITE);
	fillrectangle(0, 450, 640, 480);	//地面
	player.draw();
	for (int i : {0, 1, 2, 3}) b[i].draw();
	for (int i : {0, 1, 2, 3}) c[i].draw();
}	//初始化

void redraw() {
	srand((unsigned int)time(NULL));

	setfillcolor(WHITE);
	fillrectangle(0, 450, 640, 480);	//地面

	player.t -= v * 0.1 + 0.05;
	player.draw();

	for (int i : {0, 1, 2, 3}) {
		b[i].l -= 0.25;	//障碍物移动
		c[i].l -= 0.25; //金币移动
	}
	/*if (dist > 1500)*/ h.l -= 0.25;

	for (int i : {0, 1, 2, 3}) {
		if (b[i].l <= -(rand() % 600)) {
			b[i].t = rand() % 600;
			b[i].l = rand() % 1000 + 400;
		}	//出屏幕后重新生成

		b[i].draw();
	}

	for (int i : {0, 1, 2, 3}) {
		if (c[i].l <= -(rand() % 600)) {
			c[i].t = rand() % 600;
			c[i].l = rand() % 1000 + 400;
		}	//出屏幕后重新生成

		c[i].draw();
	}

	if (h.l <= -(rand() % 600)) {
		h.l = rand() % 1000 + 1000;
	}	//出屏幕后重新生成

	h.draw();
}

int main()
{
	fstream datio("datas.txt");
	if (!datio) cout << "Cannot find datas.txt!\n";

	srand((unsigned int)time(NULL));
	cout << "Jumping Block Starting...\n";
	cout << "Jumping Block Loading...\n";
	bool end = 0;
	initgraph(640, 480, EW_SHOWCONSOLE | EW_NOCLOSE | EW_NOMINIMIZE);
	music();
	ExMessage key;

	while (end != 1) {
		ExMessage msg;
		peekmessage(&msg);
		reactangle_trigger button(260, 200, 120, 80);
		button.draw();
		while (button.is_trigger(msg) != 1) {
			peekmessage(&msg);
		}
		//start game 按钮

		setup();

		for (int i : {0, 1, 2, 3}) {
			b[i].t = rand() % 600;
			b[i].l = rand() % 1000 + 400;
		}

		for (int i : {0, 1, 2, 3}) {
			c[i].t = rand() % 600;
			c[i].l = rand() % 1000 + 400;
		}

		BeginBatchDraw();

		int x = 0;	//帧数
		double start = 0, end = 1000;
		int score = 0;

		while (1) {
			score = 0;

			if (x % 10000 == 0) start = (double)clock();

			x = (x + 1) % 10000;
			dist += (x % 20 == 0);

			bool die = 0;

			reactangle_trigger button1(610, 450, 20, 20, L"Up", BLUE, WHITE);
			button1.draw();
			ExMessage msg1;
			peekmessage(&msg1);

			peekmessage(&key);

			if (KEYDOWN(VK_ESCAPE)) break;	//按esc退出
			if (KEYDOWN(VK_UP) || button1.is_trigger(msg1)) {
				if (v == 0) v += 10;
			}
			if (KEYDOWN('P')) mciSendString(L"pause BGM", NULL, 0, NULL);
			if (KEYDOWN('C')) {
				mciSendString(L"pause BGM", NULL, 0, NULL);
				mciSendString(L"resume BGM", NULL, 0, NULL);
			}
			cleardevice();
			redraw();
			v -= 1;
			if (player.t >= 428) {
				player.t = 428;
				v = 0;
			}
			if (player.t <= 0) {
				player.t = 0;
			}
			for (int i : {0, 1, 2, 3}) {
				if (b[i].crashP()) {
					die = 1;
				}
				if (c[i].crashP()) {
					score++;
					c[i].l = 1000;
				}
			}
			settextcolor(WHITE);
			RECT r = { 0, 0, 640, 20 };
			drawtext(AnsiToUnicode(((string)"Score:" + to_string(score)).c_str()), &r, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
			r = { 0, 21, 640, 41 };
			drawtext(AnsiToUnicode(((string)"Distance:" + to_string(dist)).c_str()), &r, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
			if (die == 1)	break;

			if (x % 100 == 0) end = (double)clock();
			settextcolor(LIGHTGRAY);
			r = { 0, 0, 640, 20 };
			drawtext(AnsiToUnicode(((string)"Fps:1000*" + to_string(10000 / (end - start))).c_str()), &r, DT_RIGHT | DT_VCENTER | DT_SINGLELINE);
			FlushBatchDraw();
		}	//一帧
		cleardevice();

		settextstyle(100, 0, L"Consolas");
		RECT r = { 0, 0, 639, 439 };
		settextcolor(WHITE);
		drawtext(L"GAME OVER", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		FlushBatchDraw();

		ExMessage endmsg;
		peekmessage(&endmsg);
		reactangle_trigger endbut(120, 320, 140, 60, L"End");
		reactangle_trigger morebut(380, 320, 140, 60, L"One More Game");
		endbut.draw();
		morebut.draw();
		FlushBatchDraw();
		while (endbut.is_trigger(endmsg) != 1 && morebut.is_trigger(endmsg) != 1) {
			peekmessage(&endmsg);
			if (endbut.is_trigger(endmsg) == 1) end = 1;
			if (morebut.is_trigger(endmsg) == 1) end = 0;
		}
		string sc;
		int score0;
		datio >> sc >> score0;
		datio << "Score" << score0 + score / 100 << endl;
	}	//一轮游戏
	mciSendString(L"stop BGM", NULL, 0, NULL);
	return 0;
}