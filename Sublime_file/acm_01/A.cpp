#include <iostream>
#include <stdio.h>
#include <algorithm>
#define maxn 200005
using namespace std;


long long x[maxn];
char ch[maxn];

int main()
{
	int n,i;
	scanf("%d %s",&n,ch);

	for(i=0; i<n; i++)
		scanf("%d",&x[i]);
	long long ans = -1;
	for(i=0; i<n; i++)
	{
		if(ch[i] == 'R' && ch[i+1] == 'L')
		{
			if(ans == -1)
				ans = x[i+1] - x[i];
			else
				ans = min(ans,x[i+1]-x[i]);
		}
	}

	if(ans == -1)
		printf("%d\n",ans);
	else
		printf("%d\n",ans/2);



	return 0;
}