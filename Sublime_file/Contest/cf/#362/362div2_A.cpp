#include <stdio.h>

int main()
{
	int t,s,x;
	while(~scanf("%d %d %d",&t,&s,&x))
	{
		if(x==t || (x-t)%s==0&&x>=t+s || (x-t)%s==1&&x>=t+s)
			printf("YES\n");
		else
			printf("NO\n");
	}



	return 0;
}