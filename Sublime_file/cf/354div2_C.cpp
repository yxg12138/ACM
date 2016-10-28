#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
char s[100100];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	queue<char> Q;
	int maxn = 0;
	int len = 0;
	for(int i=0; i<n; i++)
	{
		if(s[i] == 'a')
			Q.push(s[i]);
		else if(len<k)
		{
			len++;
			Q.push(s[i]);
		}
		else
		{
			maxn = max(maxn,(int)Q.size());
			while(!Q.empty() && Q.front()=='a')
				Q.pop();
			if(!Q.empty())
			{
				Q.pop();
				Q.push(s[i]);
			}
		}
	}
	maxn = max(maxn,(int)Q.size());
	while(!Q.empty()) Q.pop();
	len=0;
	for(int i=0; i<n; i++)
	{
		if(s[i]=='b')
			Q.push(s[i]);
		else if(len < k)
		{
			len++;
			Q.push(s[i]);
		}
		else
		{
			maxn = max(maxn,(int)Q.size());
			while(!Q.empty() && Q.front()=='b')
				Q.pop();
			if(!Q.empty())
			{
				Q.pop();
				Q.push(s[i]);
			}

		}
	}
	maxn = max(maxn,(int)Q.size());
	printf("%d\n",maxn);

	return 0;
}