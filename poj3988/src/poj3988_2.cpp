/*
//============================================================================
// Name        : poj3988.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stdlib.h>
using namespace std;

//某时间点与可选课程列表
map<int,vector<int>> timeCourses;
//某课程与kexuan
map<int,vector<int>> courseTimes;

//可选课程时间
set<int> c[5][201];
set<int> result;

map<int, int> numMap;

void makedata()
{
	freopen("poj3988.in","w",stdout);

	int i, j;
	for (i = 0; i < 100; i++)
	{
		printf("300\n");
		for (j = 0; j < 300; j++)
		{
			int a = rand() % 1001;
			int b = rand() % 1001;
			if (a > b)
				printf("%d %d\n", b, a);
			else if (a < b)
				printf("%d %d\n", a, b);
			else
				printf("%d %d\n", a, b + 1);
		}
	}
	printf("0\n");
}

int main()
{
	//makedata();

	freopen("poj3988.in1", "r", stdin);
	freopen("poj3988.out","w",stdout);

	int n = 0,a=0,b=0;
	int i,j,k;

	scanf("%d", &n);
	while (n > 0)
	{
		for (j = 0; j < 5; j++)
		{
			for (k = 0; k <= 201; k++)
			{
				c[j][k].clear();
			}
		}
		 收集数据
		for (i = 0; i < n; ++i)
		{
			scanf("%d %d", &a, &b);
			for (j = 0; j < 5; j++)
			{
				for (k = 0; j+k*5 <= 1000; k++)
				{
					if(a<=j+k*5 && j+k*5<=b)
					{
						c[j][k].insert(i);
					}
				}
			}
		}

		int max = 0;
		寻找最大值
		for (j = 0; j < 5; j++)
		{
			寻找最优值
			 处理没有一个元素集合的情况
			numMap.clear();
			for (i = 0; i <= 201; ++i)
			{
				set<int> setc = c[j][i];

				对每个元素引用计数
				set<int>::iterator it;
				for(it=setc.begin(); it!=setc.end();it++)
				{
					if(numMap.find(*it) == numMap.end())
					{
						numMap[*it] = 1;
					}
					else
					{
						numMap[*it] = numMap[*it]+1;
					}
				}
			}

			while(numMap.size() > 0)
			{
				寻找引用计数最小的元素
				int minCount = 300,minvalue = 0;
				map <int, int>::iterator m1_Iter,min_iter;
				for ( m1_Iter = numMap.begin( ); m1_Iter != numMap.end( );m1_Iter++ )
				{
					if(m1_Iter->second < minCount)
					{
						minvalue = m1_Iter->first;
						minCount = m1_Iter->second;
						min_iter = m1_Iter;
					}
				}
				numMap.erase(min_iter);

				删除引用计数最小的元素，把该元素添加到result中
				int i2;
				for (i2 = 0; i2 <= 201; ++i2)
				{
					if(c[j][i2].find(minvalue) != c[j][i2].end())
					{
						c[j][i2].erase(minvalue);
						if(result.find(minvalue) == result.end())
						{
							result.insert(minvalue);
							c[j][i2].clear();
						}
					}
				}
			};

			if(max < result.size())
			{
				max = result.size();
			}
			result.clear();
		}
		printf("%d\n",max);

		scanf("%d", &n);
	}

	return 0;
}
*/
