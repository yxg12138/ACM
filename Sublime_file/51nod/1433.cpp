#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 10000 + 1;

int main()
{
	int n,x,cnt0=0,cnt5=0;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&x);
		if(x) cnt5++;
		else cnt0++;
	}
	while(cnt5)
		if(cnt5%9==0)
			break;
		else cnt5--;
	if(cnt0!=0 && cnt5!=0)
	{
		while(cnt5--)
			printf("5");
		while(cnt0--)
			printf("0");
		printf("\n");
	}
	else if(cnt0!=0)
		printf("0\n");
	else
		printf("-1\n");

  	return 0;
}  