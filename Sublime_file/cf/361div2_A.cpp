#include <stdio.h>

int main()
{
	int n,v[10]={0},U=0,D=0,L=0,R=0;
	scanf("%d",&n);
	char s[10];
	scanf("%s",s);
	for(int i=0; i<n; i++)
	{
		v[s[i]-'0'] = 1;
		if(v[7] || v[0] || v[9])
			D = 1;
		if(v[1] || v[2] || v[3])
			U = 1;
		if(v[0] || v[1] || v[4] || v[7])
			L = 1;
		if(v[0] || v[3] || v[6] || v[9])
			R = 1;

	}
	if(U && D && L && R)
		printf("YES\n");
	else
		printf("NO\n");
			





	return 0;
}