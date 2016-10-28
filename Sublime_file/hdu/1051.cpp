#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct node
{
	int l;
	int w;
}a[5001];
int book[5001];

int cmp(node a,node b)
{
	if(a.l == b.l)
		return a.w < b.w;
	else
		return a.l < b.l;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,i,j;
		scanf("%d",&n);
		for(i=0; i<n; i++)
			scanf("%d%d",&a[i].l,&a[i].w);
		sort(a,a+n,cmp);
		memset(book,0,sizeof(book));
		book[0] = 1;
		int ans = 0,mark = 0,flag;
		while(mark < n)
		{
			ans++;
			flag = 1;
			for(j=mark,i=mark+1; i<n; i++)
			{
				if(book[i]) continue;
				if(a[j].l<=a[i].l && a[j].w<=a[i].w)
				{
					book[i] = 1;
					j = i;
				}
				else
				{
					if(flag)
					{
						mark = i;
						flag = 0;
					}
				}
			}
			if(flag)
				break;
		}
		printf("%d\n",ans);

	}
}