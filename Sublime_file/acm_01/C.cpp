#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#define maxn 200005
using namespace std;

char map[1001][1001];
int n,m;

int main()
{
	scanf("%d %d",&n,&m);
	int i,j,p,q,flag = 0,wall = 0,heng[1000] = {0},shu[1000] = {0};
	memset(heng,0,sizeof(heng));
    memset(shu,0,sizeof(shu));
	for(i=0; i<n; i++)
	{
		scanf("%s",map[i]);
		for(j=0; j<m; j++)
		{
			if(map[i][j] == '*')
			{
				wall++;
				shu[j]++;
				heng[i]++;
			}
		}
	}

	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			if(map[i][j] == '*')
			{
				if(heng[i] + shu[j] - 1 == wall)
				{
					flag = 1;
					p = i + 1;
					q = j + 1;
					break;
				}
			}
			else
			{
				if(heng[i] + shu[j] == wall)
				{
					flag = 1;
					p = i + 1;
					q = j + 1;
					break;
				}
			}
		}
		if(flag)
			break;
	}

	if(flag)
		printf("YES\n%d %d\n",p,q);
	else
		printf("NO\n");


	return 0;
}