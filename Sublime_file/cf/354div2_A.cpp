#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int n,x,minn,maxx;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&x);
		if(x==1)
			minn = i;
		if(x==n)
			maxx = i;
	}
	int t1 = max(n-minn,minn-1);
	int t2 = max(n-maxx,maxx-1);
	printf("%d\n",max(t1,t2));



	return 0;
}