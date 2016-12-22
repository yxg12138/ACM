#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int t,l,n,m;

int length[12];
int ci[101];
int vi[101];
int d[501][501];

void dp(int x)
{
    for(int i = 1;i <= length[x];++i)
    for(int j = 1;j <= m;++j)
    {
        if(ci[j] > i) continue;
        d[x][i] = max(d[x][i-ci[j]]+vi[j], d[x][i]);
    }
}

void init()
{
    memset(length,0,sizeof(length));
    memset(d,0,sizeof(d));
    int tmp1 = 0;
    int tmp2 = 0;
    scanf("%d%d%d", &l, &n, &m);
    for(int i = 1;i <= n;++i)
    {
        scanf("%d",&tmp1);
        if(tmp1 == 0){i--; continue;}
        length[i] = tmp1 - tmp2;
        tmp2 = tmp1;
    }
    length[n+1] = l - tmp1;
    for(int i = 1;i <= m;++i) scanf("%d%d", &ci[i], &vi[i]);
}

int main()
{
    cin>>t;
    while(t--)
    {
        int tot = 0;
        init();
        for(int i = 1;i <= n+1;++i) dp(i);
        for(int i = 1;i <= n+1;++i) tot += d[i][length[i]];
        cout<<tot<<endl;
    }
    return 0;
}
