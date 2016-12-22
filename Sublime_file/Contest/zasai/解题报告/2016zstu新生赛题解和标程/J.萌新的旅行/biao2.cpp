#include <cstdio>
#include <ctime>
#include <cstdlib>
#define showtime fprintf(stderr,"time = %.15f\n",clock() / (double)CLOCKS_PER_SEC)
const int N = 100000 + 5;
int g[N], c[N];
int n, ans;
int d[N];
int main(){
	freopen("read3.txt", "r", stdin);
	freopen("w.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T --){
		scanf("%d", &n);
		ans = 0;
		for(int i = 0; i < n; i ++) scanf("%d", &g[i]);
		for(int i = 0; i < n; i ++) scanf("%d", &c[i]);
		for(int i = 0, gas, p; i < n; i ++){
			p = i;
			gas = g[i];
			
			while((p+1)%n != i && c[p] <= gas){
				gas -= c[p];
				p = (p+1)%n;
				gas += g[p];
			}
			d[i] = (p<i?p+n:p)-i+1;
			ans = ans > d[i] ? ans : d[i];
		}
		for(int i = 0, f = 0; i < n; i ++){
			if(d[i] == ans){
				if(f) printf(" %d", i);
				else {
					printf("%d", i);
					f = 1;
				}
			}
		}
		printf("\n");
	}
	showtime;
}