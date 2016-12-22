// http://blog.csdn.net/lljjccsskk/article/details/51383156
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int N=100005;
const int mod = 1e9+7;

struct poi
{
	int x,y;
};
poi g[N],a,b,t;

double dis(poi x,poi y)
{
	double tmp = 0;
	tmp = (double)(x.x-y.x)*(x.x-y.x)+(double)(x.y-y.y)*(x.y-y.y);
	tmp = sqrt(tmp);
	return tmp;
}

int main()
{
	int n;
	scanf("%d%d%d%d%d%d",&a.x,&a.y,&b.x,&b.y,&t.x,&t.y);
	scanf("%d",&n);
	double amin,bmin,amin_2,bmin_2;
	amin = bmin = 0;
	amin_2 = bmin_2 = 1e20;
	double sum = 0;
	for(int i=1; i<=n; i++)
	{
		scanf("%d %d",&g[i].x,&g[i].y);
		sum += 2*dis(g[i],t);
	}
	int flaga,flagb;
	double fa,fb;
	flaga = flagb = 0;
	for(int i=1; i<=n; i++)
	{
		fa = dis(g[i],a) - dis(g[i],t);
		fb = dis(g[i],b) - dis(g[i],t);
		if(fa < amin)
		{
			//if(flaga)
				amin_2 = amin;
			amin = fa;
			flaga = i;
		}
		else if(fa < amin_2)
			amin_2 = fa;
		if(fb < bmin)
		{
			//if(flagb)
				bmin_2 = bmin;
			bmin = fb;
			flagb = i;
		}
		else if(fb < bmin_2)
			bmin_2 = fb;
	}

	double temp = 0;
	if(flaga!=0 && flagb!=0)
	{
		if(flaga == flagb)
			temp = min(amin+bmin_2,bmin+amin_2);
		else
			temp = amin+bmin;
	}
	else if(flaga>0 || flagb>0)
	{
		if(flaga>0) temp = amin;
		if(flagb>0) temp = bmin;
	}
	else
	{
		temp = min(amin_2,bmin_2);
	}

	sum += temp;
	printf("%.12lf\n",sum);






	return 0;
}