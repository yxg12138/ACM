#include <stdio.h>

int main()
{
	int n,x,v[1005] = {0};
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&x);
		v[x]++;
	}
	if((v[0]==1 && v[1]!=0) || (n==1 && v[1]==1))
		printf("YES\n");
	else
		printf("NO\n");




	return 0;
}