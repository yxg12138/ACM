#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long p,a,i,book=0;
	scanf("%lld %lld",&p,&a);
	for(i=0; i<=p; i++)
	{
		if((i*i)%p == a)
		{
			if(book==0)
				printf("%d",i);
			else printf(" %d",i);
			book = 1;
		}
	}
	if(book)
		printf("\n");
	else
		printf("No Solution\n");

	return 0;
}