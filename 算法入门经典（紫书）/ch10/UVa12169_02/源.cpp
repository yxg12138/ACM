#include <cstdio>

typedef long long LL;
const int max_size = 10001;
const int maxn = 200 + 10;

void gcd(LL a, LL b, LL& d, LL& x, LL& y){
	if (!b){
		d = a;
		x = 1, y = 0;
		return;
	}
	else{
		gcd(b, a%b, d, y, x);
		y -= x*(a / b);
		return;
	}
}

int main()
{
// 	freopen("in.txt", "r", stdin);
 	LL a, b, x[maxn];
	int T;
	scanf("%d", &T);
	for (int i = 1; i < 2 * T; i+=2)
		scanf("%lld", &x[i]);
	for (a = 0;; a++){
		LL k, b, d;
		LL t = (x[3] - a*a*x[1]);
		gcd(max_size, a + 1, d, k, b);
		if (t%d) continue;
		b = b*t / d;
		k = k*t / d;
		int ok = 1;
		for (int i = 2; i <= 2 * T; i += 2){
			x[i] = (a*x[i - 1] + b) % max_size;
			if (i!=2*T && x[i + 1] != (a*x[i] + b) % max_size){
				ok = 0;
				break;
			}
		}

		if (ok) break;
	}
	for (int i = 2; i <= 2 * T; i += 2)
		printf("%lld\n", x[i]);
}


