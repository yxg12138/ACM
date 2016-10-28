#include <stdio.h>
#include <cstring>

const long long mod = 1000000007;

int getx(char x)
{
	if(x>='0' && x<='9') return x-'0';
	if(x>='A' && x<='Z') return x-'A'+10;
	if(x>='a' && x<='z') return x-'a'+36;
	if(x=='-') return 62;
	if(x=='_') return 63;
}

char s[100005];
long long ans=1;
int a[64];

int main()
{
	for(int i=0; i<64; i++)
	{
		for(int j=0; j<64; j++)
			a[i&j]++;
	}
	scanf("%s",s);
	for(int i=0; i<strlen(s); i++)
	{
		ans = ans*a[getx(s[i])]%mod;
	}
	printf("%I64d\n",ans);



	return 0;
}