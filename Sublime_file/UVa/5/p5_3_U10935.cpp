#include <iostream>
#include <cstdio>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

queue<int> q;

int main()
{
	int n;
	while(scanf("%d", &n)==1 && n!=0)
	{
		while(!q.empty()) q.pop();
		for(int i=1; i<=n; i++)
			q.push(i);
		printf("Discarded cards:");
		while(q.size()!=1)
		{
			if(q.front()==1)
				printf(" %d",q.front());
			else
				printf(", %d",q.front());
			q.pop();
			q.push(q.front());
			q.pop();
		}
		printf("\nRemaining card: %d\n",q.front());
	}
}