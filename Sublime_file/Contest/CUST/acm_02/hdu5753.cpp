#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1005;
const int M = 100005;

int s[N];


int main()
{
	int n,i,sum1,sum2;
	while(~scanf("%d",&n))
	{
		sum2=0;
		for(i=1; i<=n; i++)
		{
			scanf("%d",&s[i]);
			if(i>1 && i<n)
				sum2 += s[i];
		}
		sum1 = s[1] + s[n];
		printf("%.6f\n",1.0*sum1/2 + 1.0*sum2/3);
	}
}