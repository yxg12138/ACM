/* ***********************************************
Author        :axp
Created Time  :2016/11/21 11:13:49
TASK		  :solve.cpp
LANG          :C++
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef long long ll;
const int inf = 1<<30;
const int N = 340+5;
const int M = 13+1;
ll dp[M][N];
bool vis[M][N];
int v[M]={0,1,2,3,4,5,6,7,8,9,10,10,10,10};
int c[5]={1,4,6,4,1};
int n,m;
int T;

ll f(int now,int w)
{
	if(w>=N || w<0)return 0;
	ll &re=dp[now][w];
	if(vis[now][w])return re;
	vis[now][w]=1;
	if(now==0)return re=0;
	re=0;
	for(int i=0;i<5;i++)
	{
		re+=c[i]*f(now-1,w-i*v[now]);
		//w-=v[now];
	}
	return re;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    vis[0][0]=1;
	dp[0][0]=1;
	cin>>T;
	while(T--)
	{
		cin>>n;
		ll ans=f(13,n);
		cout<<ans<<endl;
	}
    return 0;
}
