//============================================================================
// Name        : poj3984.cpp
// Author      : feng
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int maze[5][5];

int parent[5][5];

int value[5][5];

queue<int> open;

stack<int> result;

int main()
{
//	freopen("poj3984.in", "r", stdin);
//	freopen("poj3984.out","w",stdout);

	int i, j, x, y;

	for (i = 0; i < 5; ++i)
	{
		for (j = 0; j < 5; ++j)
		{
			scanf("%d", &maze[i][j]);

			value[i][j] = -1;
			parent[i][j] = -1;
		}
	}

	open.push(0);

	while (!open.empty())
	{
		int pos = open.front();
		open.pop();
		x = pos / 5;
		y = pos % 5;

		int nx;
		int ny;
		nx = x - 1;
		ny = y;
		if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && parent[nx][ny] == -1
				&& maze[nx][ny] == 0)
		{
			value[nx][ny] = value[x][y] + 1;
			parent[nx][ny] = pos;
			open.push(nx * 5 + ny);
		}
		nx = x + 1;
		ny = y;
		if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && parent[nx][ny] == -1
				&& maze[nx][ny] == 0)
		{
			value[nx][ny] = value[x][y] + 1;
			parent[nx][ny] = pos;
			open.push(nx * 5 + ny);
		}
		nx = x;
		ny = y - 1;
		if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && parent[nx][ny] == -1
				&& maze[nx][ny] == 0)
		{
			value[nx][ny] = value[x][y] + 1;
			parent[nx][ny] = pos;
			open.push(nx * 5 + ny);
		}
		nx = x;
		ny = y + 1;
		if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && parent[nx][ny] == -1
				&& maze[nx][ny] == 0)
		{
			value[nx][ny] = value[x][y] + 1;
			parent[nx][ny] = pos;
			open.push(nx * 5 + ny);
		}

	}

	x = 4;
	y = 4;
	result.push(x * 5 + y);

	int cparent = parent[x][y];
	result.push(cparent);

	while (cparent != 0)
	{
		x = cparent / 5;
		y = cparent % 5;

		cparent = parent[x][y];
		result.push(cparent);
	}

	while (!result.empty())
	{
		int pos = result.top();
		result.pop();
		printf("(%d, %d)\n", pos / 5, pos % 5);
	}

	return 0;
}

