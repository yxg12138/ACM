#include <iostream>
#include <stdio.h>
#include <algorithm>
#define maxn 200005
using namespace std;

int main()
{
	long long t,s,x;
	scanf("%lld %lld %lld",&t,&s,&x);

	if(t>x)
		printf("NO\n");

	if(t<=x)
		if((x-t)%s==0 || ((x-t)%s==1&&(x-t)!=1) || t==x)
			printf("YES\n");
		else
			printf("NO\n");


	return 0;
}