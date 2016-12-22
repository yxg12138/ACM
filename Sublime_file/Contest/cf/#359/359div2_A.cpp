#include <stdio.h>

struct node
{
	char c;
	long long a;
}kk[1005];

int main()
{
	long long n,m,cnt = 0;
	scanf("%I64d %I64d",&n,&m);
	for(int i=0; i<n; i++)
	{
		getchar();
		scanf("%c %I64d",&kk[i].c,&kk[i].a);
		if(kk[i].c=='+')
			m += kk[i].a;
		else
		{
			if(m-kk[i].a < 0)
				cnt++;
			else
				m -= kk[i].a;
		}
	}
	printf("%I64d %I64d\n",m,cnt);



	return 0;
}