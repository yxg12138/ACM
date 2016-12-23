#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 35;

vector<pair<int,int> > G;

int vis[35][35];

int n,m,p,a,b;
int t[10];
int d[maxn][maxn];

double dp[1<<10][maxn];
bool vis[1<<10][maxn];

void spfa(){
    for(int i=0; i<(1<<n); i++)
        fill(dp[i],dp[i]+m,INF);
    memset(vis,0,sizeof(vis));
}

int main()
{
    while(scanf("%d%d%d%d%d",&n,&m,&p,&a,&b)==5){
        if(n==0 && m==0 && p==0 && a==0 && b==0) break;
        for(int i=0; i<n; i++) scanf("%d",&t[i]);
        for(int i=0; i<=m; i++) G[i].clear();

        int u,v,w;
        memset(d,-1,sizeof(d));
        for(int i=0; i<p; i++){
            scanf("%d%d%d",&u,&v,&w); u--,v--;
            G[u].push_back(make_pair(v,w));
            G[v].push_back(make_pair(u,w));
        }

        spfa();

    }

    return 0;
}

