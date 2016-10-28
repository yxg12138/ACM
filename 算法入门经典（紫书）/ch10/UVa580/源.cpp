#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;

int main(){
	ll f[35], g[35];
	f[0] = 0, f[1] = 0, f[2] = 0;
	g[0] = 1, g[1] = 2, g[2] = 4;
	for (int n = 3; n <= 30; n++){
		f[n] = 1 << (n - 3);
		for (int i = 2; i <= n-2; i++)
			f[n] += g[i - 2] * (1 << (n - i - 2));
		g[n] = (1 << n) - f[n];
	}

	int n;
	while (scanf("%d", &n) == 1 && n){
		printf("%lld\n", f[n]);
	}



}