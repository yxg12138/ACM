#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int n,m,x,y,l,r;
	scanf("%d%d",&n,&m);
	l=1,r=n;
	for(int i=1; i<=m; i++)
	{
		scanf("%d%d",&x,&y);
		if(x>y)
			swap(x,y);
		l = max(l,x),r = min(r,y);
	}

	if(r-l>0)
		printf("%d\n",r-l);
	else
		printf("0\n");

	return 0;
}