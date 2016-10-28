#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
	char str[40];
	while(scanf("%s",str)!=EOF)
	{
		int len = strlen(str);
		int num = 0;
		if(len==1&&str[0]=='0') break;
		for(int i=len-1; i>=0; i--)
		{
			num += (str[i]-'0')*(pow(2,len-i)-1);
		}
		printf("%d\n",num);

	}
}