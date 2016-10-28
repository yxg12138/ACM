/****************
	  TLE
****************/
#include <cstdio>

const int maxn = 100 * 2 + 5;
const int M = 10001;
int T, x[maxn];

void solve(){
	for (int a = 0; a < M; a++){
		for (int b = 0; b < M; b++){
			bool ok = true;
			for (int i = 2; i <= T * 2; i += 2){
				x[i] = (a*x[i - 1] + b) % M;
				if (x[i + 1] != (a*x[i] + b) % M) {
					ok = false;
					break;
				}
			}
			if (ok) return;
		}
	}
}


int main(){

	while (scanf("%d", &T)){
		for (int i = 1; i <= T * 2 - 1; i += 2) scanf("%d", &x[i]);
		solve();
		for (int i = 2; i <= 2 * T; i += 2) printf("%d\n", x[i]);
	}

}