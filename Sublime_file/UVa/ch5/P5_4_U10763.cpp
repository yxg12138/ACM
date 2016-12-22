#include <cstdio>
#include <cstring>
using namespace std;

int in[500005];

int main()
{
	int n;
	while(scanf("%d",&n)==1&&n)
	{
		int a,b;
		memset(in,0,sizeof(in));
		for(int i=1; i<=n; i++)
		{
			scanf("%d%d",&a,&b);
			in[a]--;
			in[b]++;
		}
		int flag = 0;
		for(int i=1; i<500005; i++)
		{
			if(in[i]!=0)
			{
				flag = 1;
				break;
			}
		}
		if(flag)
			printf("NO\n");
		else
			printf("YES\n");
	}


}