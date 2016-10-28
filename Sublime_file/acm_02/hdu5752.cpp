#include<cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

long long n;
char s[105];

int main(){
	while(~scanf("%s",s))
	{
		int len = strlen(s);
		if(len>10) 
		{
			printf("TAT\n");
			continue;
		}
		n=0;
		for(int i=0; i<len; i++)
		{
			n = n*10+(s[i]-'0');
		}
		if(n>=4294967296 || !n)
		{
			printf("TAT\n");
			continue;
		}
		int ans = 0;
		while(n!=1)
		{
			n = (long long)sqrt(n*1.0);
			ans++;
		}
		printf("%d\n",ans);
	}


	return 0;
}

