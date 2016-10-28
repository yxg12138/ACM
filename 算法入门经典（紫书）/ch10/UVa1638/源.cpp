#include <cstdio>

const int maxn = 20;
long long d[maxn + 1][maxn + 1][maxn + 1];


int main(){
	d[1][1][1] = 1;
	for (int i = 2; i <= maxn; i++){
		for (int j = 1; j <= maxn; j++){
			for (int k = 1; k <= maxn; k++){
				d[i][j][k] = d[i - 1][j][k] * (i - 2);
				if (j > 1) d[i][j][k] += d[i - 1][j - 1][k];
				if (k > 1) d[i][j][k] += d[i - 1][j][k - 1];
			}
		}
	}

	int T, n, L, R;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d%d", &n, &L, &R);
		printf("%lld\n", d[n][L][R]);
	}
}

