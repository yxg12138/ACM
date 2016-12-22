#include <string>
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 1e5+5;
int a[maxn];

int main()
{
	int n,t;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&t);
		for(int i=1; i<=t; i++)
			scanf("%d",&a[i]);
		for(int i=1; i<=t; i++)
			for(int j=t; j>i; j--)
			{
				if(a[j-1] > a[j])
					swap(a[j-1],a[j]);
				printf("%d ",abs(a[t]-a[1]));
			}
		printf("\n");
	}




	return 0;
}