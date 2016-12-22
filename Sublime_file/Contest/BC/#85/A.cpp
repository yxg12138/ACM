#include <stdio.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];

int main()
{
	int T,n,m;
	scanf("%d",&T);
	while(T--)
	{
		int sum = 0;
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n; i++)
			scanf("%d",&a[i]);
		int flag = 0;
		for(int i=1; i<=n && !flag; i++)
		{
			sum = 0;
			for(int j=i; j<=n && !flag; j++)
			{
				sum += a[j];
				if(sum%m==0)
				{
					flag = 1;
				}
			}
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
}