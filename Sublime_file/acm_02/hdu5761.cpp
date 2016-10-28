#include <stdio.h>

int main()
{
	int a,v1,v2;
	while(scanf("%d %d %d",&a,&v1,&v2)!=EOF)
	{
		if(a == 0)
		{
			printf("0.0000000\n");
			continue;
		}
		if(v1 <= v2)
		{
			printf("Infinity\n");
			continue;
		}
		printf("%.10f\n",(double)1.0*v1*a/(1.0*(v1*v1-v2*v2)));
	}



	return 0;
}