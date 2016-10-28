#include <cstdio>
#include <algorithm>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn = 5555;
int sum[maxn<<2];
void PushUp(int rt)
{
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void build(int l,int r,int rt)
{
	sum[rt] = 0;
	if(l==r)
		return ;
	int m=(l+r)/2;
	build(lson);
	build(rson);
}

void update(int p,int l,int r,int rt)
{
	if(l == r)
	{
		sum[rt] ++;
		return ;
	}
	int m = (l+r)>>1;
	if(p<=m)
		update(p,lson);
	else
		update(p,rson);
	PushUp(rt);
}

int query(int L,int R,int l,int r,int rt)
{
	if(L<=l && r<=R)
		return sum[rt];
	int m = (l+r)>>1;
	int ret = 0;
	if(L<=m) ret += query(L,R,lson);
	if(R>m) ret += query(L,R,rson);
	return ret;
}

int x[maxn];
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		build(0,n-1,1);
		int sum = 0;
		for(int i=0; i<n; i++)
		{
			scanf("%d",&x[i]);
			sum += query(x[i],n-1,0,n-1,1);
			update(x[i],0,n-1,1);
		}
		int ret = sum;
		for(int i=0; i<n; i++)
		{
			sum  = sum - 2*x[i] + n - 1;
			ret = min(ret,sum);		
		}
		printf("%d\n",ret);
	}
}



