#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 35;

int n,m,p,a,b;
int t[10];
int d[maxn][maxn];

double dp[1<<10][maxn];

void solve(){
    for(int i=0; i<(1<<n); i++)
        fill(dp[i],dp[i]+m,INF);

    dp[(1<<n)-1][a-1] = 0;

    double res = INF;
    for(int S=(1<<n)-1; S>=0; S--){
        res = min(res,dp[S][b-1]);
        for(int v=0; v<m; v++){
            for(int i=0; i<n; i++){
                if(S>>i & 1){
                    for(int u=0; u<m; u++){
                        if(d[v][u] >= 0){
                            dp[S&~(1<<i)][u] = min(dp[S&~(1<<i)][u],dp[S][v]+(double)d[v][u]/t[i]);
                        }
                    }
                }
            }
        }
    }

    if(res == INF){
        printf("Impossible\n");
    }else{
        printf("%.3lf\n",res);
    }
}

int main()
{
    while(scanf("%d%d%d%d%d",&n,&m,&p,&a,&b)==5){
        if(n==0 && m==0 && p==0 && a==0 && b==0) break;
        for(int i=0; i<n; i++) scanf("%d",&t[i]);
        int u,v,w;
        memset(d,-1,sizeof(d));
        for(int i=0; i<p; i++){
            scanf("%d%d%d",&u,&v,&w); u--,v--;
            d[u][v] = w;
            d[v][u] = w;
        }

        solve();

    }

    return 0;
}
