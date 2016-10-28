#include <cstdio>
#include <cmath>

const int maxn = 200000 + 10;
long double logF[maxn * 2];

long double logC(int n, int m){
	return logF[n] - (logF[n - m] + logF[m]);
}

double solve(int n,double p){
	double ans = 0;
	for (int i = 0; i <= n; i++){
		long double v1 = logC(2 * n-i, n) + (n + 1)*log(p) + (n - i)*log(1 - p);
		long double v2 = logC(2 * n - i, n) + (n + 1)*log(1 - p) + (n - i)*log(p);
		ans += i * (exp(v1) + exp(v2));

	}
	return ans;
}

int main() {
	logF[0] = 0;
	for (int i = 1; i <= maxn; i++)
		logF[i] = logF[i - 1] + log(i);

	int kase = 0, n;
	double p;
	while (scanf("%d%lf", &n, &p) == 2)
		printf("Case %d: %.6lf\n", ++kase, solve(n, p));
	return 0;
}
