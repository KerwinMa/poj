#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=400;

struct node
{
    int s,t;
}a[MAXN];
int N;
bool v[MAXN];

void Solve()
{
    int now,Minj,ans=0;
    for (int i=0;i<5;i++)
    {
        memset(v,0,sizeof(v));
        now=0;
        for (int st=i;st<=1000;st+=5)
        {
            Minj=0;
            for (int k=1;k<=N;k++)
                if (!v[k] && a[k].s<=st && st< a[k].t)
                    if (!Minj || a[Minj].t>a[k].t) Minj=k;
                if (Minj)
                {
                    v[Minj]=1;
                    now++;
                }
        }
        if (now>ans) ans=now;
    }
    printf("%d\n",ans);
}

int main()
{
//	freopen("poj3988.in", "r", stdin);
//	freopen("poj3988.out","w",stdout);

    while (scanf("%d",&N),N)
    {
        for (int i=1;i<=N;i++)
            scanf("%d %d",&a[i].s,&a[i].t);
        Solve();
    }
}

//////////////////////
// 需要用生活中的常识去解决问题，特别适用于贪心
//
// 我就是因为考虑的太多了，用了更加复杂的方式，总超时
//////////////////////
