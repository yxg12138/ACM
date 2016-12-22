#include <bits/stdc++.h>
using namespace std;

int a[10];
int b[10] = {0,1,10,100,1000,10000,100000,1000000,10000000};

int main()
{
	int k;
	while(~scanf("%d",&k))
	{
		int maxn = 0;
		int cur = 1;
		while(k)
		{
			a[cur++] = k%10;
			maxn = max(a[cur-1],maxn);
			k /= 10;
		}
		printf("%d\n",maxn);
		for(int j=0; j<maxn; j++)
		{
			int res = 0;
			for(int i=1; i<cur; i++)
			{
				if(a[i])
				{
					res += b[i];
					a[i]--;
				}
			}
			if(j==0)
				printf("%d",res);
			else
				printf(" %d",res);
		}
		printf("\n");
	}




	return 0;
}