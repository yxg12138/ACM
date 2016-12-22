#include <iostream>  
#include <cmath>  
#include <cstdio>
using namespace std;
long long a[100005];
long long sum;  

int main()
{
	long long n,k,x;
	scanf("%I64d%I64d",&n,&k);
	for(int i=1; i<=n; i++)
	{
		scanf("%I64d",&a[i]);
	}
	long long i;
	for(i=1; i<=n; i++)
	{
		if(i*(i+1)/2 >= k)
			break;
	}
	printf("%I64d\n",a[k-((i-1)*i/2)]);
}