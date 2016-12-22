#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
char s[maxn];
char sb[maxn];
#define showtime fprintf(stderr,"time = %.15f\n",clock() / (double)CLOCKS_PER_SEC)
int main() {
    int t;
    scanf("%d", &t);
    while(t --) {
        int n, k;
        scanf("%d%d%s", &n, &k, s);
        memset(sb, 0, sizeof(sb));
        int cnt = 0;
        for(int i = 0; i < n; i ++) {
            if(s[i] == 'a') {
                sb[cnt++] = 'a';
            }
            if(s[i] == 'b') {
                if(sb[cnt-1] == 'a') {sb[cnt++] = '#';}
                sb[cnt++] = 'b';
            }
            if(s[i] == 'c') {
                int ct = 0;
                for(int j = cnt-1; j >= 0; j --) {
                    if(sb[j] == '#') break;
                    ct ++;
                }
                if(ct >= k) sb[cnt++] = '#';
                sb[cnt ++] = 'c';
            }
        }
        printf("%d\n", cnt);
    }
    showtime;
}

            
