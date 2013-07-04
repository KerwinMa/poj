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
using namespace std;

//��ѡ�γ�ʱ��
set<int> c[5][300];
set<int> result;

map<int, int> numMap;

int main()
{
	freopen("poj3988.in", "r", stdin);
	freopen("poj3988.out","w",stdout);

	int n = 0,a=0,b=0;
	int i,j,k;

	scanf("%d", &n);
	while (n > 0)
	{
		 �ռ�����
		for (i = 0; i < n; ++i)
		{
			scanf("%d %d", &a, &b);
			for (j = 0; j < 5; j++)
			{
				c[j][i].clear();
				for (k = j; k <= 1000; k = k+5)
				{
					if(a<=k && k<=b)
					{
						c[j][i].insert(k);
					}
				}
			}
		}

		int max = 0;
		Ѱ�����ֵ
		for (j = 0; j < 5; j++)
		{
			Ѱ������ֵ
			 ����û��һ��Ԫ�ؼ��ϵ����
			numMap.clear();
			for (i = 0; i < n; ++i)
			{
				set<int> setc = c[j][i];

				��ÿ��Ԫ�����ü���
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
				Ѱ�����ü�����С��Ԫ��
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

				ɾ�����ü�����С��Ԫ�أ��Ѹ�Ԫ����ӵ�result��
				int i2;
				for (i2 = 0; i2 < n; ++i2)
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
