//============================================================================
// Name        : poj1328.cpp
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
#include<cmath>
using namespace std;

struct point
{
	double lmax, rmax;
} p[1000];
bool mycomp(point a, point b)
{
	return (a.lmax - b.lmax) < 10e-7;
}

int n;
int r;
int greedy()
{
	int count = 1;
	double pre = p[0].rmax;
	for (int i = 1; i < n; i++)
	{
		if (p[i].lmax - pre > 10e-7)
		{ //¹ý½ç
			count++;
			pre = p[i].rmax;
		} else if (p[i].rmax - pre < 10e-7)
			pre = p[i].rmax;
	}
	return count;
}

int main()
{

//	freopen("in.data", "r", stdin);

	int i, index = 0;
	bool impossible;
	double temp;
	int x, y;
	while (scanf("%d%d", &n, &r) != EOF)
	{
		if (n==0)
		break;
		impossible = false;
		index++;
		for (i = 0; i < n; i++)
		{
			scanf("%d%d", &x, &y);
			if (y > r)
			{
				impossible = true;
			}
			if(impossible == false)
			{
				temp = sqrt(double(r * r - y * y));
				p[i].lmax = x - temp;
				p[i].rmax = x + temp;
			}
		}
		if (impossible)
		{
			printf("Case %d: -1\n", index);
			continue;
		}
		sort(p, p + n, mycomp);

		printf("Case %d: %d\n", index, greedy());
	}
	return 0;
}
