#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN = 2 * 1e5 + 10;
int x[MAXN], y[MAXN];
bool vis[MAXN];
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0; i<n; i++)
        {
            scanf("%d %d",&x[i],&y[i]);
        }
        int flag = 0;
        memset(vis,0,sizeof(vis));
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n && !flag; j++)
            {
                int d = abs(x[i]-x[j]) + abs(y[i]-y[j]);
                if(!vis[d])
                    vis[d] = 1;
                else
                    flag = 1;
            }
            if(flag)
                break;
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
   }

    return 0;
}