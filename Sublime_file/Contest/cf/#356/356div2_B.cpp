#include <stdio.h>
#include <algorithm>
using namespace std;


int main()
{
	int a[105];
	int n,pos,ans=0;
	scanf("%d %d",&n,&pos);
	int len= max(pos,n-pos);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	if(a[pos])
		ans++;
	int i,j;
	for(i=pos,j=pos; i!=n+1&&j; i++,j--)
	{
		if(a[i]==1 && a[j]==1 && i!=j)
			ans+=2;
	}
	if(i==n+1)
	{
		for(int k=1; k<=j; k++)
		{
			if(a[k])
				ans++;
		}
	}
	if(j==0)
	{
		for(int k=i; k<=n; k++)
		{
			if(a[k])
				ans++;
		}
	}
	printf("%d\n",ans);



	return 0;
}