#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

const int MAXN = 2e5+7;

int a[MAXN], b[MAXN],  c[MAXN],  d[MAXN];

int main() {
    int n, m, k, x, s;
    scanf("%d%d%d%d%d", &n, &m, &k, &x, &s);
    for(int i = 0; i < m; i++) scanf("%d", &a[i]);
    for(int i = 0; i < m; i++) scanf("%d", &b[i]);
    for(int i = 0; i < k; i++) scanf("%d", &c[i]);
    for(int i = 0; i < k; i++) scanf("%d", &d[i]);

    ll sum;
    int ans = upper_bound(d, d+k, s) - d - 1;
    if(ans >= 0) sum = 1LL*x*(n-c[ans]);
    else sum = 1LL*x*n;

    for(int i = 0; i < m; i++) {
        ll now = s - b[i];
        if(now >= 0) {
            int ans = upper_bound(d, d+k, now)-d-1;
            if(ans >= 0) {
                sum = min(sum, 1LL*a[i]*(n-c[ans]));
            } else {
                sum = min(sum, 1LL*n*a[i]);
            }
        }
    }
    printf("%I64d\n", sum);
    return 0;
}