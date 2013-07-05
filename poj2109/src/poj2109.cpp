//============================================================================
// Name        : poj2109.cpp
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

int main()
{
//	freopen("in.data", "r", stdin);

	int k, n;
	double p;
	while (scanf("%d %lf", &n, &p) != EOF)
	{
//		printf("%d %lf\n", n, p);

		k = pow(p, 1.0 / n);
		if (pow(k * 1.0, n * 1.0) == p)
			printf("%d\n", k);
		else
			printf("%d\n", k + 1);

//		printf("%.0lf\n", pow(p, 1.0 / n));
	}

	return 0;
}
