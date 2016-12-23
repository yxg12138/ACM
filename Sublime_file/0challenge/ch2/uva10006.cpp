#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

typedef long long ll;
const int maxn = 65000+10;

bool is_prime(int n){
	for(int i=2; i*i<=n; i++){
		if(n%i==0)
			return false;
	}
	return n!=1;
}

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
	ll n;
	while(scanf("%lld",&n)==1 && n){
		if(is_prime(n)){
			printf("%d is normal.\n",n);
			continue;
		}
		int flag = 1;
		for(ll x=1; x<n; x++){
			if(mod_pow(x,n,n) != x){
				printf("%lld is normal.\n",n);
				flag = 0;
				break;
			}
		}

		if(flag)
			printf("The number %lld is a Carmichael number.\n",n);
	}

}