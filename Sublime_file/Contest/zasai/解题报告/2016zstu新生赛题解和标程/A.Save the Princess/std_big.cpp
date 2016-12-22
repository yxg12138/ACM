#include <bits/stdc++.h>

int main() {
    //freopen("read.in", "r", stdin);
    //freopen("write.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        printf("%s\n", n & 1 ? "BH" : "LYF");
    }
    return 0;
}
