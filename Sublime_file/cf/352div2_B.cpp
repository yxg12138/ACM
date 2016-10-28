#include <stdio.h>
#include <cstring>

char str[100005];
int a[30];

int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",str);
	int len = strlen(str);
	for(int i=0; i<len; i++)
	{
		a[str[i]-'a'+1]++;
	}
	int sum=0,tmp=0;
	for(int i=1; i<=26; i++)
	{
		if(a[i])
			tmp++;
		sum += a[i];
	}
	sum -= tmp;
	if(sum > 26-tmp)
		printf("-1\n");
	else
		printf("%d\n",sum);





	return 0;
}