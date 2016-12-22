/* ***********************************************
Author        :guanjun
Created Time  :2015/12/1 23:10:56
File Name     :answer.cpp
************************************************ */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <list>
#include <deque>
#include <stack>
#define ull unsigned long long
#define ll long long
#define mod 90001
#define INF 0x3f3f3f3f
#define maxn 10000+10
#define cle(a) memset(a,0,sizeof(a))
const ull inf = 1LL << 61;
const double eps=1e-5;
using namespace std;

bool cmp(int a,int b){
    return a>b;
}
int a[110];
int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    #endif
   // freopen("output.txt","w",stdout);
    int n;
	while(cin>>n){
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]>a[k])ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
    return 0;
}
