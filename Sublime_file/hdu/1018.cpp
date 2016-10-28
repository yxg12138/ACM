#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const double e = 2.7182818284590452354, pi = 3.141592653589793239;

double str_ling(int n)
{
	return 0.5*log10(2*pi*n) + n*log10(n/e);
}

int main()
{
	int T,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		printf("%d\n",(int)str_ling(n)+1);
	}


	return 0;
}