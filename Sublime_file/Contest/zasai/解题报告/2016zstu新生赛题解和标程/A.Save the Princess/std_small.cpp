#include <bits/stdc++.h>

const int N = 1e3 + 5;
int sg[N][N];
bool vis[N];

int SG(int x, int y) {
    if (sg[x][y] != -1) return sg[x][y];

    int a = -1, b = -1;
    if (x > 1) a = SG(x-1, y);
    if (y > 1) b = SG(x, y-1);
    
    int vis[2] = {0};
    if (a != -1) vis[a] = true;
    if (b != -1) vis[b] = true;

    int ret = 0;
    while (vis[ret]) ret++;
    return sg[x][y] = ret;
}

int main() {
    memset(sg, -1, sizeof(sg));
    sg[1][1] = 0;
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        printf("%s\n", SG(k-1, n-k) ? "LYF" : "BH");
    }
    return 0;
}
