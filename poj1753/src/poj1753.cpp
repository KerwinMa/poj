//============================================================================
// Name        : poj1753.cpp
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
using namespace std;

bool flip[4][4];

//��ת����
int maxFlip = 16;

void input()
{
//	freopen("poj1753.in", "r", stdin);
//	freopen("poj1753.out","w",stdout);

	int i, j;
	for (i = 0; i < 4; i++)
	{
		char c;
		for (j = 0; j < 4; j++)
		{
			scanf("%c", &c);
			if (c == 'b')
				flip[i][j] = false;
			else
				flip[i][j] = true;
		}
		scanf("%c", &c);
	}
}

/**
 * �ж��Ƿ���������
 */
bool check()
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (flip[i][j] != flip[0][0])
				return false;
		}
	}
	return true;
}

/**
 * index ��תλ��
 * flipNum ��ת����
 */
void flipOne(int index, int flipNum)
{
	int i = index / 4;
	int j = index % 4;
	//��
	flip[i][j] = !flip[i][j];
	//��
	if (i - 1 >= 0)
		flip[i - 1][j] = !flip[i - 1][j];
	//��
	if (i + 1 < 4)
		flip[i + 1][j] = !flip[i + 1][j];
	//��
	if (j - 1 >= 0)
		flip[i][j - 1] = !flip[i][j - 1];
	//��
	if (j + 1 < 4)
		flip[i][j + 1] = !flip[i][j + 1];
}

void onFlip(int index, int flipNum)
{
	if (index >= 16)
		return;
	if(flipNum > maxFlip)
		return;

	onFlip(index + 1, flipNum);
	flipOne(index, flipNum);
	flipNum++;
	if (check() && flipNum < maxFlip)
		maxFlip = flipNum;
	else
		onFlip(index + 1, flipNum);

	//��ת��ԭ
	flipOne(index, flipNum);
}

int main()
{
	input();

	if (check())
	{
		maxFlip = 0;
	}

	onFlip(0, 0);

	if (maxFlip != 16)
		printf("%d\n", maxFlip);
	else
		printf("Impossible\n");
	return 0;
}
