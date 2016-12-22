#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
const int N = 5005;
const int M = 100005;
const int inf = 1000000007;
const int mod = 1000000007;
char s[M],p[N];
// int ans[M];

int main()
{
	int t,n,m,i,j,k;
	scanf("%d",&t);
	while(t--)
	{
		memset(s,0,sizeof(s));
		memset(p,0,sizeof(p));
		// memset(ans,0,sizeof(ans));
		scanf("%d%d",&n,&m);
		scanf("%s",s);
		scanf("%s",p);
		for(i=0; s[i]!='\0'; i++)
		{
			if(i+m>n)
			{
				printf("0");
				continue;
			}
			for(j=0,k=i; p[j]!='\0';)
				if(s[k]==p[j])
					j++,k++;
				else if(s[k] == p[j+1] && s[k+1]==p[j])
					j += 2,k += 2;
				else
					break;
			if(p[j] == '\0')
				printf("1");
			else
				printf("0");
		}
		printf("\n");
	}
	return 0;
}