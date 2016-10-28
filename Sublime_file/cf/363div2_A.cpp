#include <stdio.h>
#include <string>
using namespace std;

const int maxn = 200005;
long long n,a[maxn],minn = 0x7fffffff;
char s[maxn];


int main()
{
	scanf("%I64d%s",&n,s);
	for(int i=0; i<n; i++)
		scanf("%I64d",&a[i]);
	int flag = 0;
	for(int i=0; i<n-1; i++)
	{
		if(s[i] == 'R' && s[i+1] == 'L')
		{
			if(a[i+1]-a[i] < minn)
			{
				minn = a[i+1] - a[i];
				flag = 1;
			}
		}
	}
	if(flag)
		printf("%I64d\n",minn/2);
	else
		printf("-1\n");




	return 0;
}