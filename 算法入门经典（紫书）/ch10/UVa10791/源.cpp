#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int divide_all(int& n, int d){
	int x = 1;
	while (n%d == 0){
		n /= d;
		x *= d;
	}

	return x;
}


long long solve(int n){
	if (n == 1) return 2;
	int m = floor(sqrt(n) + 0.5);
	long long ans = 0;
	int pf = 0;
	for (int i = 2; i < m; i++){
		if (n%i == 0){
			pf++;
			ans += divide_all(n, i);
		}
	}

	if (n > 1) { pf++; ans += n; }
	if (pf <= 1) ans += 1;

	return ans;
}

int main(){
	int n, kase = 0;
	while (scanf("%d", &n) && n){
		printf("Case %d: %lld\n",++kase, solve(n));
	}

}