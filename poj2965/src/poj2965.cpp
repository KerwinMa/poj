//============================================================================
// Name        : poj2965.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include <queue>
using namespace std;

int state = 0;

int openNum[16];

//翻转次数
int minFlip = 16;

//当前方式
int current[16];

//最终结果
int result[16];

void init()
{
	for (int i = 0; i < 16; i++)
	{
		openNum[i] = 0;
		for (int j = 0; j < 16; j++)
		{
			if (j / 4 == i / 4 || j % 4 == i % 4)
			{
				openNum[i] += 1 << (15 - j);
			}
		}
	}
}

void input()
{

	int i, j;
	for (i = 0; i < 4; i++)
	{
		char c;
		for (j = 0; j < 4; j++)
		{
			scanf("%c", &c);
			if (c == '+')
			state += 1<<(15 - (i*4+j));
		}
		scanf("%c", &c);
	}
}

void onFlip(int index, int flipNum)
{
	if (index >= 16)
		return;
	if (flipNum > minFlip)
		return;

	onFlip(index + 1, flipNum);
	state = state ^ openNum[index];
	current[flipNum] = index;
	flipNum++;
	if (state == 0 && flipNum <= minFlip)
	{
		minFlip = flipNum;
		memcpy(result, current, 16 * sizeof(int));
	} else
		onFlip(index + 1, flipNum);

	//还原
	state = state ^ openNum[index];
}

int main()
{
	freopen("in.data", "r", stdin);
	freopen("out.data", "w", stdout);

	input();

	init();

	if (state == 0)
	{
		minFlip = 0;
	}

	onFlip(0, 0);

	printf("%d\n", minFlip);
	for (int i = 0; i < minFlip; i++)
	{
		printf("%d %d\n", (result[i] / 4 + 1), (result[i] % 4 + 1));
	}

	return 0;
}
