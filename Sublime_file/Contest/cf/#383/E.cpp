#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5+7;

int n;
vector<int> E[maxn];
int b[maxn],g[maxn],ans[maxn];

void dfs(int x,int y){
    if(ans[x]) return;
    ans[x] = y;
    for(int i=0; i<E[x].size(); i++)
        dfs(E[x][i],1-y);
}

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        E[2*i-1].push_back(2*i);
        E[2*i].push_back(2*i-1);
    }

    for(int i=1; i<=n; i++){
        int x,y;
        cin >> x >> y;
        E[x].push_back(y);
        E[y].push_back(x);
        b[i] = x,g[i] = y;
    }

    int tmp = 0;
    for(int i=1; i<=2*n; i++) if(!ans[i])
        dfs(i,tmp);

    for(int i=1; i<=n; i++)
        cout << ans[b[i]] + 1 << " " << ans[g[i]] + 1 << endl;
}