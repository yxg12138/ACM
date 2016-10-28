#include <cstdio>
typedef long long ll;

ll gcd(ll a, ll b){
	return b == 0 ? a : gcd(b, a%b);
}

void reduce(ll& a, ll& b){
	ll g = gcd(a, b);
	a /= g, b /= g;
}

int main(){

	int T, n, k;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; kase++){
		scanf("%d%d", &n, &k);
		ll b = 1LL << k;
		ll a = b - k - 1;
		reduce(a, b);
		printf("Case #%d: %lld/%lld\n", kase, a, b);
	}

}