//============================================================================
// Name        : poj3295.cpp
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
#include <stack>
using namespace std;

int pi, qi, ri, si, ti;

char cStack[105];

int clen = 0;
int index = 0;

int getValue(char c)
{
	if (c == 'p')
		return pi;
	if (c == 'q')
		return qi;
	if (c == 'r')
		return ri;
	if (c == 's')
		return si;
	if (c == 't')
		return ti;
	return 0;
}

bool isValue(char c)
{
	if (c == 'p')
		return true;
	if (c == 'q')
		return true;
	if (c == 'r')
		return true;
	if (c == 's')
		return true;
	if (c == 't')
		return true;
	return false;
}

int operate(char op, int param1, int param2)
{
	if (op == 'K')
		return param1 && param2;
	if (op == 'A')
		return param1 || param2;
	if (op == 'N')
		return !param2;
	if (op == 'C')
		return (!param1) || param2;
	if (op == 'E')
		return param1 == param2;
	return 0;
}

int compute()
{
	for (pi = 0; pi <= 1; pi++)
	{
		for (qi = 0; qi <= 1; qi++)
		{
			for (ri = 0; ri <= 1; ri++)
			{
				for (si = 0; si <= 1; si++)
				{
					for (ti = 0; ti <= 1; ti++)
					{
						int cresult = 1;
						int param = -1;

						index = clen - 1;

						char c = cStack[index--];
						cresult = getValue(c);

						while (index >= 0)
						{
							c = cStack[index--];
							if (isValue(c))
							{
								param = getValue(c);
							} else
							{
								cresult = operate(c, param, cresult);
							}
						}
						if (cresult == 0)
							return 0;
					}
				}
			}
		}
	}
	return 1;
}

int main()
{
	freopen("in.data", "r", stdin);

	while ( cin >> cStack && cStack[0] != '0' )
	{
		clen = strlen(cStack);

		int result = compute();

		if (result)
		cout << "tautology\n";
		else
		cout << "not\n";
	}

	return 0;
}
