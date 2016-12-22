#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
char s[maxn];
#define showtime fprintf(stderr,"time = %.15f\n",clock() / (double)CLOCKS_PER_SEC)
int main() {
	freopen ("I.in", "r", stdin);
	freopen ("ha.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t --) {
        int n, k;
        scanf("%d%d%s", &n, &k, s);
        int cnt = 0, ans = 0, last = 0;
        for(int i = 0; i < n; i ++) {
           if(s[i] == 'a') {last = 1; ans ++;}
           if(s[i] == 'b') {
              ans ++;
              if(last) {ans ++; cnt = 0;}
              last = 0;
           }
           if(s[i] == 'c') {
               last = 0;
               ans ++;
               if(cnt >= k) {cnt = 0; ans ++;}
           }
           cnt ++;
        }
        printf("%d\n", ans);
    }
    showtime;
    return 0;
}
                 
        
