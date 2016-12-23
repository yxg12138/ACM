#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

typedef long long ll;

ll mod_pow(ll x,ll n,ll m){
	ll res = 1;
	while(n>0){
		if(n&1) res = res*x%m;
		x = x*x%m;
		n >>= 1;
	}

	return res;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int m,h,ans=0;
		scanf("%d%d",&m,&h);

		while(h--){
			int a,b;
			scanf("%d%d",&a,&b);
			ans += mod_pow(a,b,m);
		}

		ans %= m;
		printf("%d\n",ans);
	}
}