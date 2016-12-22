#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1e6;
char s[maxn], t[maxn];

int main()
{
	scanf("%s",s);
	int i,len = strlen(s);
	strcpy(t,s);
	reverse(s,s+strlen(s));
	printf("%s%s\n",t,s);

	return 0;
}