#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <queue>
#include <sstream>
#include <map>
#include <time.h> 

#define INF 0x3f3f3f3f
#define EPS 1e-10
#define PI acos(-1.0)
#define LL long long
#define scan(x) scanf("%d",x)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define PII pair<int,int>
#define sqr(x) ((x)*(x))

#define IN freopen("in.txt","r",stdin);
#define OUT freopen("out.txt","w",stdout);
using namespace std;
#define N 1111
#define M 63333
struct  node
{
	int ai,bi;
}a[N];
bool cmp(node a,node b)
{
	return a.ai==b.ai?a.bi>b.bi:a.ai>b.ai;
}
priority_queue<int>que;
int main()
{
	//if (2&1)	cout<<"r"<<endl;

	
    int n,T;
    scan(&T);
    while (T--)
    {
		scan(&n);
		rep(i,0,n)
		scan(&a[i].ai);
		rep(i,0,n)
		scan(&a[i].bi);
		sort(a,a+n,cmp);
		rep(i,1,n){
			cout<<i<<" "<<a[i].ai<<endl;
			if (i&1) {/*cout<<i<<" "<<a[i].ai<<endl;*/que.push(-a[i].bi);}
			else if (a[i].bi>-que.top()) {que.pop();que.push(-a[i].bi);}
		}
		LL ans=0;
		while (!que.empty())
		{
			ans=ans-que.top();
			que.pop();
		}
		cout<<ans<<endl;
	}
    return 0;    
}
