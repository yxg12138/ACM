#include <stdio.h>

int main()
{
	int n,h,x,tmp;
	scanf("%d %d",&n,&h);
	tmp = n;
	for(int i=0; i<tmp; i++)
	{
		scanf("%d",&x);
		if(x > h)
			n++;
	}
	printf("%d\n",n);

	return 0;
}