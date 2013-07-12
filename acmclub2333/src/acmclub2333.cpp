//============================================================================
// Name        : acmclub火爆的一乐拉面.cpp
// Author      : wardenfeng
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

struct people
{
	long long lamian, kaorou, yinliao;
};

int main()
{
	freopen("in.data", "r", stdin);

	int n,l,k,y;
	while (scanf("%d%d%d%d", &n, &l, &k, &y) != EOF)
	{

		people a,b,c,p;
		a.lamian = 1;
		a.kaorou = 1;
		a.yinliao = 1;

		b.lamian = 2;
		b.kaorou = 1;
		b.yinliao = 0;

		c.lamian = 3;
		c.kaorou = 3;
		c.yinliao = 2;

		int i,j;
		long long time,minTime = 10000000000000000;
		char ch[101];
		for(i = 0; i < n; i++)
		{
			time = 0;
			scanf("%s",ch);
			for(j = 0;ch[j]!='\0';j++)
			{
				switch(ch[j])
				{
					case 'A':
					p = a;
					break;
					case 'B':
					p = b;
					break;
					case 'C':
					p = c;
					break;
				}
				time += p.lamian * l + p.kaorou * k + p.yinliao * y;
			}
			if(time < minTime)
			minTime = time;
		}
		cout << minTime<<endl;
	}
	return 0;
}
